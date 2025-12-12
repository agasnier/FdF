/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:36:55 by algasnie          #+#    #+#             */
/*   Updated: 2025/12/12 16:45:29 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_close_windows(t_mlx *mlx_data)
{
	ft_free_all(mlx_data);	
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
	mlx_data->windows_size_x = 1000;
	mlx_data->windows_size_y = 1000;
	
	mlx_data->addr_windows = mlx_new_window(mlx_data->addr_init, mlx_data->windows_size_x, mlx_data->windows_size_y, mlx_data->windows_title);
	if (!mlx_data->addr_windows)
	{
		return (1); //////error
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
		write(2, "error\n", 6);
		return (1);
	}

	////////////////////////////////creatin tab map

	mlx_data.tab_point = ft_create_tab(mlx_data);
	if (mlx_data.tab_point == NULL)
		return (1);
	ft_init_tab(mlx_data.tab_point, mlx_data, argv[1]);
	///////////////////////////////////creation mlx	

	mlx_data.addr_init = mlx_init();
	if (!mlx_data.addr_init)
	{
		return (1); //////error
	}

	if (ft_new_windows(&mlx_data))
	{
		return (1); //////error
	}

	ft_render(&mlx_data, mlx_data.tab_point);


	return (0);
}