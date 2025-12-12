/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:08:04 by algasnie          #+#    #+#             */
/*   Updated: 2025/12/12 14:50:44 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_input_key(int keycode, t_mlx *mlx_data)
{
	double	incr;

	incr = 0.01;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(mlx_data->addr_init, mlx_data->addr_windows); /// + free malloc
		exit(0);
	}

	
	else if (keycode == KEY_RIGHT)
		mlx_data->view.angle_y += incr;
	else if (keycode == KEY_LEFT)
		mlx_data->view.angle_y -= incr;

	
	else if (keycode == KEY_UP)
		mlx_data->view.angle_x += incr;
	else if (keycode == KEY_DOWN)
		mlx_data->view.angle_x -= incr;
	
		
	else if (keycode == KEY_PLUS)
		mlx_data->view.z_scale += incr;
	else if (keycode == KEY_MINUS)
		if (mlx_data->view.z_scale >= incr)
			mlx_data->view.z_scale -= incr;

	incr = 10;

	if (keycode == KEY_W)
		mlx_data->view.offset_y -= incr;
	else if (keycode == KEY_S)
		mlx_data->view.offset_y += incr;

	
	else if (keycode == KEY_A)
		mlx_data->view.offset_x -= incr;
	else if (keycode == KEY_D)
		mlx_data->view.offset_x += incr;

	else if (keycode == CTRL)
		ft_set_view_iso(mlx_data);

	

	ft_apply_proj(mlx_data->tab_point, *mlx_data);
	ft_create_image(mlx_data, mlx_data->tab_point);
	return (0);
}

int	ft_input_mouse(int keycode, int x, int y, t_mlx *mlx_data)
{
	double	incr;
	(void)x;
	(void)y;

	incr = 1;
	if (keycode == SCROLL_UP)
		mlx_data->view.zoom += incr;
	else if (keycode == SCROLL_DOWN)
		if (mlx_data->view.zoom >= incr)
			mlx_data->view.zoom -= incr;
	ft_apply_proj(mlx_data->tab_point, *mlx_data);
	ft_create_image(mlx_data, mlx_data->tab_point);

	return (0);
}