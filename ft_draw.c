/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:39:04 by algasnie          #+#    #+#             */
/*   Updated: 2025/12/12 14:10:15 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_put_pixel(t_mlx mlx_data, t_point_proj point)
{
	void	*pixel;

	if (point.x < 0 || (int)point.x >= mlx_data.windows_size_x || point.y < 0 || (int)point.y >= mlx_data.windows_size_y)
		return ;
	pixel = mlx_data.img.img_data + ((int)point.y * mlx_data.img.size_line) + ((int)point.x * (mlx_data.img.bpp /8));	
	*(unsigned int*)pixel = (unsigned int)point.color;
}

static void	ft_put_line(t_mlx mlx_data, t_point_proj point_a, t_point_proj point_b)
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

	int 	max;
	int		step;

	ax = (int)point_a.x;
	ay = (int)point_a.y;
	bx = (int)point_b.x;
	by = (int)point_b.y;

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
	{
		err = dx / 2;
		max = dx;
	}
	else
	{
		err = -dy / 2;
		max = dy;
	}

	step = 0;
	while (1)
	{
		ft_put_pixel(mlx_data, (t_point_proj){ax, ay, 0, point_b.color});
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
		step++;
		
	}
}

static void	ft_draw(t_mlx mlx_data, t_point **tab_point)
{
	int	y = 0;
	int	x;
	
	while (y < mlx_data.map_size_y)
	{
		x = 0;
		while (x < mlx_data.map_size_x)
		{
			if (x < mlx_data.map_size_x - 1)
				ft_put_line(mlx_data, tab_point[y][x].proj, tab_point[y][x + 1].proj);
			if (y < mlx_data.map_size_y - 1)
				ft_put_line(mlx_data, tab_point[y][x].proj, tab_point[y + 1][x].proj);
			x++;
		}
		y++;
	}
}

void	ft_create_image(t_mlx *mlx_data, t_point **tab_point)
{
	mlx_data->img.img_ptr = mlx_new_image(mlx_data->addr_init, mlx_data->windows_size_x, mlx_data->windows_size_y);
	mlx_data->img.img_data = mlx_get_data_addr(mlx_data->img.img_ptr, &mlx_data->img.bpp, &mlx_data->img.size_line, &mlx_data->img.endian);
	ft_draw(*mlx_data, tab_point);
	mlx_put_image_to_window(mlx_data->addr_init, mlx_data->addr_windows, mlx_data->img.img_ptr, 0, 0);
}
