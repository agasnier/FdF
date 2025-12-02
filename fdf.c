/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:36:55 by algasnie          #+#    #+#             */
/*   Updated: 2025/12/02 11:46:44 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(t_mlx mlx_data, t_img img, t_point point)
{
	void	*pixel;

	if (point.x < 0 || point.x > mlx_data.windows_size_x || point.y < 0 || point.y > mlx_data.windows_size_x) //// a changer par map size
		return ;



	pixel = img.img_data + (point.y * img.size_line) + (point.x * (img.bpp /8));

	point.color = 0xFF0000; /////////////////////////////
	
	*(unsigned int*)pixel = point.color;
}

void	ft_put_line(t_mlx mlx_data, t_img img, t_point point_a, t_point point_b)
{
	float	y;
	float	slope;
	
	if (point_a.x > point_b.x)
		ft_put_line(mlx_data, img, point_b, point_a);

	else
	{
		slope = ((float)point_b.y - (float)point_a.y)/((float)point_b.x - (float)point_a.x);

		if (point_a.x == point_b.x)
			while (point_a.y != point_b.y)
			{
				ft_put_pixel(mlx_data, img, point_a);
				point_a.y++;
			}
		else
		{
			while (point_a.x != point_b.x)
			{
				ft_put_pixel(mlx_data, img, point_a);
				y += slope;
				if (y >= 1)
				{
					point_a.y++;
					y = 0;
				}
				else if (y <= -1)
				{
					point_a.y--;
					y = 0;
				}
				point_a.x++;

			}
		}
	}
}

void	ft_render(t_mlx mlx_data, t_point **tab_point)
{

	t_img	img;



	////////setting view
	ft_set_view(&mlx_data, 10, 0, 0, 30);

	
	///creation de l'img
	img.img_ptr = mlx_new_image(mlx_data.addr_init, mlx_data.windows_size_x, mlx_data.windows_size_y);
	img.img_data = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_line, &img.endian);


	///projection of points
	// t_point	**tab_copy;

	// tab_copy = ft_point_projection(tab_point, mlx_data);
	
	t_point test;
	t_point test2;

	test.x = 100;
	test.y = 0;

	test2.x = 100;
	test2.y = 100;

	tab_point = NULL;
	
	ft_put_line(mlx_data, img, test, test2);

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



	tab_point = ft_create_tab(mlx_data);
	if (tab_point == NULL)
		return (1);
	ft_init_tab(tab_point, mlx_data, argv[1]);





	///////////////////////print map
	// int x;
	// int y;


	// y = 0;
	// printf("\n");
	// while (y < mlx_data.map_size_y)
	// {
	// 	x = 0;
	// 	while (x < mlx_data.map_size_x)
	// 	{
	// 		printf("%d ", tab_point[y][x].z);
			
	// 		x++;
	// 	}
	// 	printf("\n");
	// 	y++;
	// }


	
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


	////////////////////////////debut de rendu

	//fait une copie de la map et modifie les valeurs / boucle pour chaque touches ?
	ft_render(mlx_data, tab_point);


	return (0);
}