/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:39:04 by algasnie          #+#    #+#             */
/*   Updated: 2025/12/03 10:35:37 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(t_mlx mlx_data, t_img img, t_point_proj point)
{
	void	*pixel;

	if (point.x < 0 || point.x >= mlx_data.windows_size_x || point.y < 0 || point.y >= mlx_data.windows_size_y) //// a changer par map size
		return ;



	pixel = img.img_data + ((int)point.y * img.size_line) + ((int)point.x * (img.bpp /8));

	point.color = 0xFF0000; /////////////////////////////
	
	*(unsigned int*)pixel = point.color;
}

void	ft_put_line(t_mlx mlx_data, t_img img, t_point_proj point_a, t_point_proj point_b)
{
	int		dx;
	int		dy;
	int		err;
	int		err2;
	int		sx;
	int		sy;

	if (point_a.x > point_b.x)
	{
		dx = point_a.x - point_b.x;
		sx = -1;
	}
	else
	{
		dx = point_b.x - point_a.x;
		sx = 1;
	}
		
		
	if (point_a.y > point_b.y)
	{
		dy = point_a.y - point_b.y;
		sy = -1;
	}
	else
	{
		dy = point_b.y - point_a.y;
		sy = 1;
	}

	if (dx > dy)
		err = dx / 2;
	else	
		err = -dy / 2;

	while (1)
	{
		ft_put_pixel(mlx_data, img, point_a);
		if (point_a.x == point_b.x && point_a.y == point_b.y)
			break ;

		err2 = err;
		
		if (err2 > -dx)
		{
			err -= dy;
			point_a.x += sx;
		}
		
		if (err2 < dy)
		{
			err += dx;
			point_a.y += sy;
		}

		
	}
}