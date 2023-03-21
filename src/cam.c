/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:50:23 by cdescour          #+#    #+#             */
/*   Updated: 2023/03/20 14:37:28 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

void		half_w_h(t_item *data)
{
	double theta;
	double ratio;

	theta = data->camera->fov * M_PI / 180;
	ratio = (double)data->rsl.width / (double)data->rsl.height;
	data->rsl.half_height = 2 * tan(theta / 2);
	data->rsl.half_width = ratio * data->rsl.half_height;
}

void		calcul_pixel(t_item *data)
{
	double		x;
	double		y;
	t_vector	pixel_x;
	t_vector	pixel_y;
	t_vector	pixel;

	x = (data->rsl.x + 0.5) * data->rsl.half_width / (double)data->rsl.width;
	y = (data->rsl.y + 0.5) * data->rsl.half_height / (double)data->rsl.height;
	pixel_x = vector_scal(x, data->camera->u);
	pixel_y = vector_scal(y, data->camera->v);
	pixel = vector_add(pixel_x, pixel_y);
	pixel = vector_sub(data->camera->l, pixel);
	data->camera->pixel = pixel;
}

void		mapper_pixel(t_item *data)
{
	t_vector center;
	t_vector l;

	center = vector_sub(data->camera->pos, data->camera->n);
	l.x = data->camera->u.x * data->rsl.half_width / 2\
		+ data->camera->v.x * data->rsl.half_height / 2;
	l.y = data->camera->u.y * data->rsl.half_width / 2\
		+ data->camera->v.y * data->rsl.half_height / 2;
	l.z = data->camera->u.z * data->rsl.half_width / 2\
		+ data->camera->v.z * data->rsl.half_height / 2;
	data->camera->l = vector_add(center, l);
}

void		camera_setting(t_item *data)
{
	t_vector vup;

	vup = make_pos(0, 1, 0);
	if (data->camera->ort_vec.y != 0 && (data->camera->ort_vec.z == 0 &&\
		data->camera->ort_vec.x == 0))
		vup = make_pos(0, 0, 1);
	half_w_h(data);
	data->camera->n = vector_scal(-1, data->camera->ort_vec);
	data->camera->n = unit_vector(data->camera->n);
	data->camera->u = vector_cross(vup, data->camera->n);
	data->camera->u = unit_vector(data->camera->u);
	data->camera->v = vector_cross(data->camera->n, data->camera->u);
	mapper_pixel(data);
}

void		ray(t_item *data)
{
	calcul_pixel(data);
	data->ray.origin = data->camera->pos;
	data->ray.direction = vector_sub(data->camera->pixel, data->ray.origin);
	data->ray.direction = unit_vector(data->ray.direction);
}
