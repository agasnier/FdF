/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:39:04 by algasnie          #+#    #+#             */
/*   Updated: 2025/12/13 14:21:23 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(t_mlx mlx_data, t_point point)
{
	void	*pixel;

	if (point.x < 0 || point.x >= mlx_data.windows_size_x || point.y < 0 || point.y >= mlx_data.windows_size_y)
		return ;
	pixel = mlx_data.img.img_data + (point.y * mlx_data.img.size_line) + (point.x * (mlx_data.img.bpp /8));	
	*(unsigned int*)pixel = (unsigned int)point.color;
}


void	ft_put_line(t_mlx mlx_data, t_point_proj point_a, t_point_proj point_b)
{
	t_line	line;
	t_point	bress_a;
	t_point bress_b;
	
	ft_line_put_to_int(&bress_a, &bress_b, point_a, point_b);
	ft_put_line_direc_x(bress_a, bress_b, &line.dx, &line.sx);
	ft_put_line_direc_y(bress_a, bress_b, &line.dy, &line.sy);
	ft_put_line_err(&line.err, line.dx, line.dy);
	ft_put_line_draw(mlx_data, line, bress_a, bress_b);

}

void	ft_draw(t_mlx mlx_data, t_point **tab_point)
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
	ft_apply_proj(tab_point, *mlx_data);
	if (mlx_data->img.img_ptr != NULL)
		mlx_destroy_image(mlx_data->addr_init, mlx_data->img.img_ptr);
	mlx_data->img.img_ptr = mlx_new_image(mlx_data->addr_init, mlx_data->windows_size_x, mlx_data->windows_size_y);
	mlx_data->img.img_data = mlx_get_data_addr(mlx_data->img.img_ptr, &mlx_data->img.bpp, &mlx_data->img.size_line, &mlx_data->img.endian);
	ft_draw(*mlx_data, tab_point);
	mlx_put_image_to_window(mlx_data->addr_init, mlx_data->addr_windows, mlx_data->img.img_ptr, 0, 0);
}
