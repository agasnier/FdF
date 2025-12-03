/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:08:04 by algasnie          #+#    #+#             */
/*   Updated: 2025/12/03 11:10:25 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_input(int keycode, t_mlx *mlx_data)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(mlx_data->addr_init, mlx_data->addr_windows); /// + free malloc
		exit(0);
	}
	if (keycode == KEY_RIGHT)
	{
		mlx_destroy_image(mlx_data->addr_init, mlx_data->img.img_ptr);
		mlx_data->view.angle += 5;
		ft_apply_proj(mlx_data->tab_point, *mlx_data);
		ft_create_image(*mlx_data, mlx_data->tab_point);
	}
	return (0);
}