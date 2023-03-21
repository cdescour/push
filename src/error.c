/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:43:45 by cdescour          #+#    #+#             */
/*   Updated: 2023/03/20 17:17:08 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"
/*
void	ft_print(t_item *data, char *name, int number)
{
	ft_putstr_fd(name, 1);
	ft_putstr_fd(" : line ", 1);
	ft_putnbr_fd(data->parsing.error, 1);
	if (number == 1)
		ft_putstr_fd(" : miss element\n", 1);
	else if (number == 2)
		ft_putstr_fd(" : pos\n", 1);
	else if (number == 3)
		ft_putstr_fd(" : orientation vector\n", 1);
	else if (number == 4)
		ft_putstr_fd(" : rgb\n", 1);
	else if (number == 5)
		ft_putstr_fd(" : translation\n", 1);
	else if (number == 6)
		ft_putstr_fd(" : rotation\n", 1);
	else if (number == 7)
		ft_putstr_fd(" : out of limit of element\n", 1);
}

void	ft_print_cont(t_item *data, char *name, int object, int error)
{
	ft_putstr_fd(name, 1);
	ft_putstr_fd(" : line ", 1);
	ft_putnbr_fd(data->parsing.error, 1);
	if (object == RESOLUTION_D)
		(error == 1) ? ft_putstr_fd(" : width\n", 1)\
			: ft_putstr_fd(" : height\n", 1);
	else if (object == AMBIENT_D || object == LIGHT_D)
		ft_putstr_fd(" : intensity\n", 1);
	else if (object == SPHERE_D)
		ft_putstr_fd(" : radius\n", 1);
	else if (object == SQUARE_D)
		ft_putstr_fd(" : height\n'", 1);
	else if (object == CYLINDER_D)
		(error = 1) ? ft_putstr_fd(" : radius\n", 1)\
			: ft_putstr_fd(" : height\n\n", 1);
	else if (object == CAMERA_D)
		ft_putstr_fd(" : fov\n", 1);
	free_exit(data, 1);
}

void	print_error_data(t_item *data)
{
	ft_putstr_fd("Error\nCheck data of line ", 1);
	ft_putnbr_fd(data->parsing.error, 1);
	free_exit(data, 1);
}*/

void    ft_error(t_item *data, char *str)
{
    	ft_putstr_fd(str, 2);
	free_exit(data);
}
