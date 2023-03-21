/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:50:23 by cdescour          #+#    #+#             */
/*   Updated: 2023/03/20 15:18:16 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

static t_color	ft_ambient(t_item *data)
{
	t_color ambient;
	t_color scal;

	scal = color_scal(data->ambient.int_amb, data->ambient.rgb_amb);
	ambient.r = data->objet->color.r * scal.r;
	ambient.g = data->objet->color.g * scal.g;
	ambient.b = data->objet->color.b * scal.b;
	ambient.r = min(1, ambient.r);
	ambient.g = min(1, ambient.g);
	ambient.b = min(1, ambient.b);
	return (ambient);
}

static t_color	ft_diffuse(t_item *data)
{
	double		dot;
	t_color	diffuse;
	t_vector	l_norm;

	l_norm = unit_vector(data->objet->light);
	dot = vector_dot(l_norm, data->objet->normal);
	dot = max(0.0, dot) * data->light->int_light;
	diffuse.r = data->light->rgb_light.r * data->objet->color.r * dot;
	diffuse.g = data->light->rgb_light.g * data->objet->color.g * dot;
	diffuse.b = data->light->rgb_light.b * data->objet->color.b * dot;
	return (diffuse);
}

t_color		render(t_item *data, t_color shadow)
{
	t_light		*light;
	t_color	somme;
	t_color	pixel;//render_s;

	ft_bzero(&data->render, sizeof(t_render));
	light = data->light;
	while (data->light != NULL)
	{
		data->objet->light = vector_sub(data->light->pos, data->objet->point);
		data->render.diffuse = color_add(data->render.diffuse, ft_diffuse(data));
			data->light = data->light->next;
	}
	data->render.diffuse = color_scal(255, data->render.diffuse);
	data->render.ambiant = color_scal(255, ft_ambient(data));
	somme = color_create(data->render.diffuse);
	pixel = color_prd(shadow, somme);
	pixel = color_add(pixel, data->render.ambiant);
	data->light = light;
	pixel = min_max(pixel);
	return (pixel);
}
