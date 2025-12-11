/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:08:04 by algasnie          #+#    #+#             */
/*   Updated: 2025/12/11 15:43:59 by algasnie         ###   ########.fr       */
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
	else if (keycode == KEY_RIGHT || keycode == KEY_LEFT)
	{
		if (keycode == KEY_LEFT)
			incr *= -1;
		mlx_destroy_image(mlx_data->addr_init, mlx_data->img.img_ptr);
		mlx_data->view.angle_x += incr;
		ft_apply_proj(mlx_data->tab_point, *mlx_data);
		ft_create_image(mlx_data, mlx_data->tab_point);
	}
	else if (keycode == KEY_UP || keycode == KEY_DOWN)
	{
		if (keycode == KEY_UP)
			incr *= -1;
		mlx_destroy_image(mlx_data->addr_init, mlx_data->img.img_ptr);
		mlx_data->view.angle_y += incr;
		ft_apply_proj(mlx_data->tab_point, *mlx_data);
		ft_create_image(mlx_data, mlx_data->tab_point);
	}
	else if (keycode == KEY_PLUS || keycode == KEY_MINUS)
	{
		if (keycode == KEY_MINUS)
			incr *= -1;
		mlx_destroy_image(mlx_data->addr_init, mlx_data->img.img_ptr);
		mlx_data->view.z_scale += incr;
		ft_apply_proj(mlx_data->tab_point, *mlx_data);
		ft_create_image(mlx_data, mlx_data->tab_point);
	}
	else if (keycode == KEY_W || keycode == KEY_S)
	{
		incr = 10;
		if (keycode == KEY_W)
			incr *= -1;
		mlx_destroy_image(mlx_data->addr_init, mlx_data->img.img_ptr);
		mlx_data->view.offset_y += incr;
		ft_apply_proj(mlx_data->tab_point, *mlx_data);
		ft_create_image(mlx_data, mlx_data->tab_point);
	}
	else if (keycode == KEY_A || keycode == KEY_D)
	{
		incr = 10;
		if (keycode == KEY_A)
			incr *= -1;
		mlx_destroy_image(mlx_data->addr_init, mlx_data->img.img_ptr);
		mlx_data->view.offset_x += incr;
		ft_apply_proj(mlx_data->tab_point, *mlx_data);
		ft_create_image(mlx_data, mlx_data->tab_point);
	}
	return (0);
}

int	ft_input_mouse(int keycode, int x, int y, t_mlx *mlx_data)
{
	double	incr;
	(void)x;
	(void)y;

	if (keycode == SCROLL_UP || keycode == SCROLL_DOWN)
	{
		incr = 1;
		if (keycode == SCROLL_DOWN)
			incr *= -1;
		mlx_destroy_image(mlx_data->addr_init, mlx_data->img.img_ptr);
		mlx_data->view.zoom += (int)incr;
		ft_apply_proj(mlx_data->tab_point, *mlx_data);
		ft_create_image(mlx_data, mlx_data->tab_point);
	}

	return (0);
}