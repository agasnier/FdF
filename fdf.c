/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:36:55 by algasnie          #+#    #+#             */
/*   Updated: 2025/12/02 15:35:12 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_apply_proj(t_point **tab_point, t_mlx mlx_data)
{
	int	y;
	int	x;
	double rad;
	double cos_val;
	double sin_val;
	double proj_x;
	double proj_y;
		
	rad = mlx_data.view.angle * 3.14159265358979323846 / 180;
	cos_val = cos(rad);
	sin_val = sin(rad);
	
	y = 0;
	while (y < mlx_data.map_size_y)
	{
		x = 0;
		while (x < mlx_data.map_size_x)
		{
			proj_x = ((double)tab_point[y][x].x - (double)tab_point[y][x].y) * cos_val * (double)mlx_data.view.zoom;
			proj_y = ((double)tab_point[y][x].x + (double)tab_point[y][x].y) * sin_val * (double)mlx_data.view.zoom - (double)tab_point[y][x].z * (double)mlx_data.view.zoom;
			proj_x += mlx_data.view.offset_x;
			proj_y += mlx_data.view.offset_y;
			tab_point[y][x].proj.x = (int)proj_x;
			tab_point[y][x].proj.y = (int)proj_y;
			x++;
		}
		y++;
	}
}

void	ft_render(t_mlx mlx_data, t_point **tab_point)
{

	t_img	img;

	////////setting view && apply
	ft_set_view(&mlx_data, 20, mlx_data.windows_size_x/2, mlx_data.windows_size_y/2, 30);

	ft_apply_proj(tab_point, mlx_data);

	///creation de l'img
	img.img_ptr = mlx_new_image(mlx_data.addr_init, mlx_data.windows_size_x, mlx_data.windows_size_y);
	img.img_data = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_line, &img.endian);

	///projection of points

	// tab_copy = ft_point_projection(tab_point, mlx_data);

	int	y = 0;
	int	x;
	
	while (y < mlx_data.map_size_y)
	{
		x = 0;
		while (x < mlx_data.map_size_x)
		{
			if (x < mlx_data.map_size_x - 1)
				ft_put_line(mlx_data, img, tab_point[y][x].proj, tab_point[y][x + 1].proj);
			if (y < mlx_data.map_size_y - 1)
				ft_put_line(mlx_data, img, tab_point[y][x].proj, tab_point[y + 1][x].proj);
			x++;
		}
		y++;
	}

	// application de limage
	mlx_put_image_to_window(mlx_data.addr_init, mlx_data.addr_windows, img.img_ptr, 0, 0);

	///boucle event
	mlx_hook(mlx_data.addr_windows, KEY_PRESS, KEY_PRESS_MASK, &ft_input, &mlx_data);
	mlx_loop(mlx_data.addr_init);

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

	///////////////////////////////////creation mlx	

	mlx_data.addr_init = mlx_init();
	if (!mlx_data.addr_init)
	{
		return (1); //////error
	}

	mlx_data.windows_title = "fdf";
	mlx_data.windows_size_x = 1000;
	mlx_data.windows_size_y = mlx_data.windows_size_x;
	

	mlx_data.addr_windows = mlx_new_window(mlx_data.addr_init, mlx_data.windows_size_x, mlx_data.windows_size_y, mlx_data.windows_title);
	if (!mlx_data.addr_windows)
	{
		return (1); //////error
	}

	ft_render(mlx_data, tab_point);


	return (0);
}