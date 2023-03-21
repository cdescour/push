/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elem_cap_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:01:28 by lreille           #+#    #+#             */
/*   Updated: 2023/03/20 20:50:07 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

int		ft_check_A(t_item *data, char **tab)
{
	if (ft_dbltablen(tab) < 3)
		ft_error(data, A1001);
	if (check_double(tab[1]) == 0 ||\
		(ft_atod(tab[1]) < 0 || ft_atod(tab[1]) > 1))
		ft_error(data, A1002);
	else if (check_rgb(tab[2]) == 0)
		ft_error(data, A1003);
	if (data->parsing.a == 1)
		ft_error(data, A1004);
	return (AMB);
}

int			ft_check_L(t_item *data, char **tab)
{
	if (ft_dbltablen(tab) < 3)
		ft_error(data, L1001);
	if (check_pos(tab[1]) == 0)
		ft_error(data, L1002);
	else if (check_double(tab[2]) == 0 ||\
			(ft_atod(tab[2]) < 0 || ft_atod(tab[2]) > 1))
		ft_error(data, L1003);
	return (LIG);
}

static void	camera(t_item *data, char **tab)
{
	if (ft_dbltablen(tab) > 6)
		ft_error(data, E1001);//miss_or_out(data, CAMERA_D, 7);
	if (ft_dbltablen(tab) >= 5)
	{
		if (check_pos(tab[4]) == 0)
		ft_error(data, E1001);//	wrong_trans_rot(data, CAMERA_D, 1);
		data->tool.tran_rot = 1;
	}
	if (ft_dbltablen(tab) >= 6)
	{
		if (check_rotation(tab[5]) == 0)
		ft_error(data, E1001);//	wrong_trans_rot(data, CAMERA_D, 2);
		data->tool.tran_rot = 2;
	}
}

int			ft_check_C(t_item *data, char **tab)
{
	if (ft_dbltablen(tab) < 4)
		ft_error(data, C1001);
	else if (ft_dbltablen(tab) > 4)
		camera(data, tab);
	if (check_pos(tab[1]) == 0)
		ft_error(data, C1002);
	else if (check_vec_ort(tab[2]) == 0)
		ft_error(data, C1003);
	else if (check_double(tab[3]) == 0 ||\
			(ft_atod(tab[3]) < 0 || ft_atod(tab[3]) > 180))
		ft_error(data, C1004);
	return (CAM);
}

