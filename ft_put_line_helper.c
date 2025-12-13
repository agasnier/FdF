/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_line_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:16:25 by algasnie          #+#    #+#             */
/*   Updated: 2025/12/13 14:18:39 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_line_draw(t_mlx mlx_data, t_line line, t_point bress_a, t_point bress_b)
{
	int err2;
	
	while (1)
	{
		ft_put_pixel(mlx_data, bress_a);
		if (bress_a.x == bress_b.x && bress_a.y == bress_b.y)
			break ;

		err2 = line.err;
		
		if (err2 > -line.dx)
		{
			line.err -= line.dy;
			bress_a.x += line.sx;
		}
		
		if (err2 < line.dy)
		{
			line.err += line.dx;
			bress_a.y += line.sy;
		}
		
	}
}

void	ft_put_line_err(int *err, int dx, int dy)
{
	if (dx > dy)
		*err = dx / 2;
	else
		*err = -dy / 2;
}
		
void	ft_put_line_direc_y(t_point bress_a, t_point bress_b, int *dy, int *sy)
{
	if (bress_a.y > bress_b.y)
	{
		*dy = bress_a.y - bress_b.y;
		*sy = -1;
	}
	else
	{
		*dy = bress_b.y - bress_a.y;
		*sy = 1;
	}
}



void	ft_put_line_direc_x(t_point bress_a, t_point bress_b, int *dx, int *sx)
{
	if (bress_a.x > bress_b.x)
	{
		*dx = bress_a.x - bress_b.x;
		*sx = -1;
	}
	else
	{
		*dx = bress_b.x - bress_a.x;
		*sx = 1;
	}
}

void	ft_line_put_to_int(t_point *bress_a, t_point *bress_b, t_point_proj point_a, t_point_proj point_b)
{
	bress_a->x = (int)point_a.x;
	bress_a->y = (int)point_a.y;
	bress_b->x = (int)point_b.x;
	bress_b->y = (int)point_b.y;

	bress_a->color = point_b.color;
}