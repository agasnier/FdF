/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:08:04 by algasnie          #+#    #+#             */
/*   Updated: 2025/12/14 13:33:19 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_input_key(int keycode, t_mlx *mlx_data)
{
	if (keycode == KEY_ESC)
	{
		ft_free_all(mlx_data, 0);
		exit(0);
	}
	if (BONUS)
	{
		if (keycode == KEY_RIGHT || keycode == KEY_LEFT
			|| keycode == KEY_UP || keycode == KEY_DOWN)
			ft_rotation(keycode, mlx_data);
		else if (keycode == KEY_W || keycode == KEY_S
			|| keycode == KEY_A || keycode == KEY_D)
			ft_translation(keycode, mlx_data);
		else if (keycode == KEY_PLUS || keycode == KEY_MINUS
			|| keycode == CTRL || keycode == SHIFT || keycode == KEY_H)
			ft_manip_view(keycode, mlx_data);
	}
	ft_create_image(mlx_data);
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
	ft_create_image(mlx_data);
	return (0);
}
