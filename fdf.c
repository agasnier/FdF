/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:36:55 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/28 16:37:38 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	ft_line_put(t_point *start, t_point *end, t_mlx *mlx)
// {
	
// }


void	ft_render(t_mlx mlx_data, t_point **tab_point)
{

	void	*img_ptr;
	void	*img_data;

	int		bpp;
	int		size_line;
	int		endian;
	
	img_ptr = mlx_new_image(mlx_data.addr_init, mlx_data.map_size_x, mlx_data.map_size_y);
	img_data = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);

	









	
	// t_point	**tab;

	// tab = tab_point;
	
	// int	center;
	// center = 100;

	// int i = 0;
	// int j;
	// while (i < mlx_data.map_size_y)
	// {
	// 	j = 0;
	// 	while (j < mlx_data.map_size_x)
	// 	{
	// 		tab[i][j].x += zoom;
	// 		tab[i][j].y += zoom;
	// 		tab[i][j].z += zoom;
	// 		j++;
	// 	}
	// 	i++;
	// }
	


	
	// //double	angle;
	// //angle = 30;

	// i = 0;
	
	// //x' = (x - y) * cos(angle);
	// //y' = (x + y) * sin(angle) - z;




	
	// while (i < mlx_data.map_size_y)
	// {
	// 	j = 0;
	// 	while (j < mlx_data.map_size_x)
	// 	{
	// 		printf("%d\n", tab[i][j].z);
	// 		mlx_pixel_put(mlx_data.addr_init, mlx_data.addr_windows, tab[i][j].x, tab[i][j].y, 0xF00000);
	// 		j++;
	// 	}
	// 	i++;
	// }


	// mlx_hook(mlx_data.addr_windows, KEY_PRESS, KEY_PRESS_MASK, &ft_input, &mlx_data);
	
	// mlx_loop(mlx_data.addr_init);


	
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
	mlx_data.windows_size_x = 500;
	mlx_data.windows_size_y = mlx_data.windows_size_x;
	

	mlx_data.addr_windows = mlx_new_window(mlx_data.addr_init, mlx_data.windows_size_x, mlx_data.windows_size_y, mlx_data.windows_title);
	if (!mlx_data.addr_windows)
	{
		return (1); //////error
	}

	ft_render(mlx_data, tab_point);

	return (0);
}