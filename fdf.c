/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:36:55 by algasnie          #+#    #+#             */
/*   Updated: 2025/12/13 12:05:05 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_close_windows(t_mlx *mlx_data)
{
	ft_free_all(mlx_data, 0);	
	exit(0);
	return (0);
}

static void	ft_render(t_mlx *mlx_data, t_point **tab_point)
{
	ft_set_view_iso(mlx_data);
	mlx_data->img.img_ptr = NULL;
	ft_create_image(mlx_data, tab_point);
	mlx_hook(mlx_data->addr_windows, 17, 0, &ft_close_windows, mlx_data);
	mlx_hook(mlx_data->addr_windows, KEY_PRESS, KEY_PRESS_MASK, &ft_input_key, mlx_data);
	mlx_hook(mlx_data->addr_windows, MOUSE, MOUSE_MASK, &ft_input_mouse, mlx_data);
	mlx_loop(mlx_data->addr_init);
}

static int	ft_new_windows(t_mlx *mlx_data)
{
	mlx_data->windows_title = "fdf";
	mlx_get_screen_size(mlx_data->addr_init, &mlx_data->windows_size_x, &mlx_data->windows_size_y);	
	mlx_data->addr_windows = mlx_new_window(mlx_data->addr_init, mlx_data->windows_size_x, mlx_data->windows_size_y, mlx_data->windows_title);
	if (!mlx_data->addr_windows)
	{
		ft_free_all(mlx_data, 1);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{	
	t_mlx	mlx_data;

	if (argc <= 1)
		return (0);

	if (ft_size_map(argv[1], &mlx_data))
	{
		ft_free_all(&mlx_data, 1);
		return (1);
	}
	mlx_data.tab_point = ft_create_tab(mlx_data);
	if (mlx_data.tab_point == NULL)
		return (1);
	ft_init_tab(mlx_data.tab_point, mlx_data, argv[1]);
	mlx_data.addr_init = mlx_init();
	if (!mlx_data.addr_init)
	{
		ft_free_all(&mlx_data, 1);
		return (1);
	}
	if (ft_new_windows(&mlx_data))
	{
		ft_free_all(&mlx_data, 1);
		return (1);
	}
	ft_render(&mlx_data, mlx_data.tab_point);
	return (0);
}