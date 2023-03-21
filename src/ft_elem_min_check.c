/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elem_min_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:50:18 by cdescour          #+#    #+#             */
/*   Updated: 2023/03/20 22:04:41 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

int		ft_check_sp(t_item *data, char **tab)
{
	if (ft_dbltablen(tab) < 4)
		ft_error(data, SP1001);//return (miss_or_out(data, SPHERE_D, 1));
	if (ft_dbltablen(tab) > 4)
	{
		if (ft_dbltablen(tab) > 5)
			ft_error(data, E1001);//rreturn (miss_or_out(data, SPHERE_D, 7));
		if (ft_dbltablen(tab) >= 5)
		{
			if (check_pos(tab[4]) == 0)
				ft_error(data, E1001);//rreturn (wrong_trans_rot(data, SPHERE_D, 1));
			data->tool.tran_rot = 1;
		}
	}
	if (check_pos(tab[1]) == 0)
		ft_error(data, SP1002);
	else if (check_double(tab[2]) == 0 || ft_atod(tab[2]) < 0)
		ft_error(data, SP1003);
	else if (check_rgb(tab[3]) == 0)
		ft_error(data, SP1004);
	return (SPH);
}
/*
static void	plane(t_item *data, char **tab)
{
	if (ft_dbltablen(tab) > 6)
		ft_error(data, E1001);//rmiss_or_out(data, PLANE_D, 7);
	if (ft_dbltablen(tab) >= 5)
	{
		if (check_pos(tab[4]) == 0)
			ft_error(data, E1001);//rwrong_trans_rot(data, PLANE_D, 1);
		data->tool.tran_rot = 1;
	}
	if (ft_dbltablen(tab) >= 6)
	{
		if (check_rotation(tab[5]) == 0)
			ft_error(data, E1001);//rwrong_trans_rot(data, PLANE_D, 2);
		data->tool.tran_rot = 2;
	}
}
*/
int			ft_check_pl(t_item *data, char **tab)
{
	if (ft_dbltablen(tab) < 4)
		ft_error(data, PL1001);
//	else if (ft_dbltablen(tab) > 4)
//		plane(data, tab);
	if (check_pos(tab[1]) == 0)
		ft_error(data, PL1002);
	else if (check_vec_ort(tab[2]) == 0)
		ft_error(data, PL1003);
	else if (check_rgb(tab[3]) == 0)
		ft_error(data, PL1004);
	return (PLA);
}
/*
static void	cylinder(t_item *data, char **tab)
{
	if (ft_dbltablen(tab) > 8)
		ft_error(data, E1001);//riss_or_out(data, CYLINDER_D, 7);
	if (ft_dbltablen(tab) >= 7)
	{
		if (check_pos(tab[6]) == 0)
			ft_error(data, E1001);//rwrong_trans_rot(data, CYLINDER_D, 1);
		data->tool.tran_rot = 1;
	}
	if (ft_dbltablen(tab) >= 8)
	{
		if (check_rotation(tab[7]) == 0)
			ft_error(data, E1001);//rwrong_trans_rot(data, CYLINDER_D, 2);
		data->tool.tran_rot = 2;
	}
}
*/
int			ft_check_cy(t_item *data, char **tab)
{
	if (ft_dbltablen(tab) < 6)
		ft_error(data, CY1001);//rreturn (miss_or_out(data, CYLINDER_D, 1));
//	else if (ft_dbltablen(tab) > 6)
//	cylinder(data, tab);
	if (check_pos(tab[1]) == 0)
		ft_error(data, CY1002);//rreturn (wrong_pos(data, CYLINDER_D));
	else if (check_vec_ort(tab[2]) == 0)
		ft_error(data, CY1003);//rreturn (wrong_vec_ort(data, CYLINDER_D));
	else if (check_double(tab[3]) == 0 || ft_atod(tab[3]) < 0)
		ft_error(data, CY1004);
	else if (check_double(tab[4]) == 0 || ft_atod(tab[4]) < 0)
		ft_error(data, CY1005);
	else if (check_rgb(tab[5]) == 0)
		ft_error(data, CY1006);
	return (CYL);
}
