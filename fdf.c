/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:36:55 by algasnie          #+#    #+#             */
/*   Updated: 2025/12/08 16:45:16 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	ft_render(t_mlx *mlx_data, t_point **tab_point)
{

	////////setting view && apply
	ft_set_view(mlx_data, 5, mlx_data->windows_size_x/2, mlx_data->windows_size_y/2);
	ft_apply_proj(tab_point, *mlx_data);

	//// draw
	ft_create_image(mlx_data, tab_point);


	//boucle event
	mlx_hook(mlx_data->addr_windows, KEY_PRESS, KEY_PRESS_MASK, &ft_input, mlx_data);
	mlx_loop(mlx_data->addr_init);

}


int	main(int argc, char **argv)
{	
	t_mlx	mlx_data;
	t_point **tab_point;

	if (argc <= 1)
		return (0);

	if (ft_size_map(&mlx_data, argv[1]))
	{
		write(2, "error\n", 6);
		return (1);
	}

	////////////////////////////////creatin tab map

	tab_point = ft_create_tab(mlx_data);
	if (tab_point == NULL)
		return (1);
	ft_init_tab(tab_point, mlx_data, argv[1]);
	mlx_data.tab_point = tab_point;
	///////////////////////////////////creation mlx	

	mlx_data.addr_init = mlx_init();
	if (!mlx_data.addr_init)
	{
		return (1); //////error
	}

	mlx_data.windows_title = "fdf";
	mlx_data.windows_size_x = 1920;
	mlx_data.windows_size_y = 1080;
	

	mlx_data.addr_windows = mlx_new_window(mlx_data.addr_init, mlx_data.windows_size_x, mlx_data.windows_size_y, mlx_data.windows_title);
	if (!mlx_data.addr_windows)
	{
		return (1); //////error
	}

	ft_render(&mlx_data, tab_point);


	return (0);
}