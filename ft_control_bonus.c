/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:21:31 by algasnie          #+#    #+#             */
/*   Updated: 2025/12/14 14:37:32 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotation(int keycode, t_mlx *mlx_data)
{
	double	incr;

	incr = 0.01;
	if (keycode == KEY_RIGHT)
		mlx_data->view.angle_y += incr;
	else if (keycode == KEY_LEFT)
		mlx_data->view.angle_y -= incr;
	else if (keycode == KEY_UP)
		mlx_data->view.angle_x += incr;
	else if (keycode == KEY_DOWN)
		mlx_data->view.angle_x -= incr;
}

void	ft_translation(int keycode, t_mlx *mlx_data)
{
	double	incr;

	incr = 10;
	if (keycode == KEY_W)
		mlx_data->view.offset_y -= incr;
	else if (keycode == KEY_S)
		mlx_data->view.offset_y += incr;
	else if (keycode == KEY_A)
		mlx_data->view.offset_x -= incr;
	else if (keycode == KEY_D)
		mlx_data->view.offset_x += incr;
}

void	ft_manip_view(int keycode, t_mlx *mlx_data)
{
	double	incr;

	incr = 0.01;
	if (keycode == KEY_PLUS)
		mlx_data->view.z_scale += incr;
	else if (keycode == KEY_MINUS)
	{
		if (mlx_data->view.z_scale >= incr)
			mlx_data->view.z_scale -= incr;
	}
	else if (keycode == CTRL)
		ft_set_view_iso(mlx_data);
	else if (keycode == SHIFT)
		ft_set_view_para(mlx_data);
	else if (keycode == KEY_H)
	{
		if (mlx_data->heat == 0)
			mlx_data->heat = 1;
		else
			mlx_data->heat = 0;
	}
}

void	ft_set_view_para(t_mlx *mlx_data)
{
	mlx_data->view.zoom = ((double)mlx_data->windows_size_x
			* 0.25) / mlx_data->map_size_x;
	mlx_data->view.offset_x = mlx_data->windows_size_x / 2;
	mlx_data->view.offset_y = mlx_data->windows_size_y / 2;
	mlx_data->view.z_scale = 1;
	mlx_data->view.angle_x = PARA_ANGLE_X;
	mlx_data->view.angle_y = 0;
	mlx_data->view.angle_z = PARA_ANGLE_Y;
}
