/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:39:04 by algasnie          #+#    #+#             */
/*   Updated: 2025/12/11 17:25:45 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(t_mlx mlx_data, t_img img, t_point_proj point)
{
	void	*pixel;

	if (point.x < 0 || point.x >= (int)mlx_data.windows_size_x || point.y < 0 || point.y >= (int)mlx_data.windows_size_y) //// a changer par map size
		return ;



	pixel = img.img_data + ((int)point.y * img.size_line) + ((int)point.x * (img.bpp /8));

	//point.color = point.color; /////////////////////////////16776960 //16711680
	
	*(unsigned int*)pixel = (unsigned int)point.color;
}

void	ft_put_line(t_mlx mlx_data, t_img img, t_point_proj point_a, t_point_proj point_b)
{
	int		ax;
	int		ay;
	int		bx;
	int		by;
	
	int		dx;
	int		dy;
	int		err;
	int		err2;
	int		sx;
	int		sy;

	ax = (int)point_a.x;
	ay = (int)point_a.y;
	bx = (int)point_b.x;
	by = (int)point_b.y;

	point_a.color = point_b.color;
	if (ax > bx)
	{
		dx = ax - bx;
		sx = -1;
	}
	else
	{
		dx = bx - ax;
		sx = 1;
	}
		
		
	if (ay > by)
	{
		dy = ay - by;
		sy = -1;
	}
	else
	{
		dy = by - ay;
		sy = 1;
	}

	if (dx > dy)
		err = dx / 2;
	else	
		err = -dy / 2;

	while (1)
	{
		ft_put_pixel(mlx_data, img, (t_point_proj){ax, ay, 0, point_b.color});
		if (ax == bx && ay == by)
			break ;

		err2 = err;
		
		if (err2 > -dx)
		{
			err -= dy;
			ax += sx;
		}
		
		if (err2 < dy)
		{
			err += dx;
			ay += sy;
		}

		
	}
}

void	ft_draw(t_mlx mlx_data, t_point **tab_point, t_img img)
{
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
}

void	ft_create_image(t_mlx *mlx_data, t_point **tab_point)
{
	t_img	img;

	
	///creation de l'img
	img.img_ptr = mlx_new_image(mlx_data->addr_init, mlx_data->windows_size_x, mlx_data->windows_size_y);
	img.img_data = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_line, &img.endian);


	mlx_data->img = img;

	ft_draw(*mlx_data, tab_point, img);

	// application de limage
	mlx_put_image_to_window(mlx_data->addr_init, mlx_data->addr_windows, img.img_ptr, 0, 0);
}
