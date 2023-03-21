/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:29:37 by cdescour          #+#    #+#             */
/*   Updated: 2023/03/20 15:39:43 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

static t_color	shadow_intersect(t_item *data)
{
	t_color zero;

	if (data->shad.degre > 1)
		data->shad.degre = 1;
	zero.r = 1 - data->shad.degre;
	zero.g = 1 - data->shad.degre;
	zero.b = 1 - data->shad.degre;
	return (zero);
}

t_color		shadows(t_item *data, t_objet *tmp)
{
	t_color		un;
	t_ray		ombre;
	t_light		*light;

	data->shad.intersect = 0;
	light = data->light;
	data->shad.degre = 0;
	un = make_number(1.0);
	ombre.origin = vector_scal(0.001, data->objet->normal);
	ombre.origin = vector_add(data->objet->point, ombre.origin);
	while (data->light != NULL)
	{
		ombre.direction = vector_sub(data->light->pos, data->objet->point);
		ombre.lenght = vector_length(ombre.direction);
		ombre.direction = unit_vector(ombre.direction);
		hit_objet2(data, &ombre, tmp);
		data->light = data->light->next;
	}
	data->light = light;
	if (data->shad.intersect == 1)
		return (shadow_intersect(data));
	return (un);
}

void	parc_resl(t_item *data)
{
	int		a;
	int		b;

	mlx_get_screen_size(data->mlx.mlx_ptr, &a, &b);
	data->rsl.width = RX;
	data->rsl.height = RY;
//	if (data->rsl.width > a);
	//	data->rsl.width = a;
//	if (data->rsl.height > b)
//		data->rsl.height = b;
	data->parsing.r = 1;
}
