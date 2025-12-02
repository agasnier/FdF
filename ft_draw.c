/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:39:04 by algasnie          #+#    #+#             */
/*   Updated: 2025/12/02 16:53:32 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(t_mlx mlx_data, t_img img, t_point_proj point)
{
	void	*pixel;

	if (point.x < 0 || point.x > mlx_data.windows_size_x || point.y < 0 || point.y > mlx_data.windows_size_x) //// a changer par map size
		return ;



	pixel = img.img_data + ((int)point.y * img.size_line) + ((int)point.x * (img.bpp /8));

	point.color = 0xFF0000; /////////////////////////////
	
	*(unsigned int*)pixel = point.color;
}

void	ft_put_line(t_mlx mlx_data, t_img img, t_point_proj point_a, t_point_proj point_b)
{
	float	y;
	float	slope;
	
	
	if (point_a.x > point_b.x)
		ft_put_line(mlx_data, img, point_b, point_a);

	else
	{
		slope = ((float)point_b.y - (float)point_a.y)/((float)point_b.x - (float)point_a.x);
		y = 0;
		
		if (point_a.x == point_b.x)
			while (point_a.y != point_b.y)
			{
				ft_put_pixel(mlx_data, img, point_a);
				point_a.y++;
			}
		else if (slope <= 1 && slope >= -1)
		{
			while (point_a.x != point_b.x)
			{
				y += slope;
				while (y > 1)
				{
					ft_put_pixel(mlx_data, img, point_a);
					point_a.y++;
					y--;
				}
				ft_put_pixel(mlx_data, img, point_a);
				point_a.x++;
			}
		}
		else if (slope > 1 || slope < -1)
		{
			while (point_a.y != point_b.y)
			{
				if (slope > 1)
				{
					y += slope;
					while (y > 1)
					{
						ft_put_pixel(mlx_data, img, point_a);
						point_a.x++;
						y--;
					}
					ft_put_pixel(mlx_data, img, point_a);
					point_a.y++;
				}
				else
				{
					y -= slope;
					while (y < -1)
					{
						ft_put_pixel(mlx_data, img, point_a);
						point_a.x--;
						y++;
					}
					ft_put_pixel(mlx_data, img, point_a);
					point_a.y++;
				}
			}
		}
		
		
		
	}
}