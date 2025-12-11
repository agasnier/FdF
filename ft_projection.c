/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:48:47 by algasnie          #+#    #+#             */
/*   Updated: 2025/12/11 18:58:01 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_proj(t_point point, t_point_proj *point_proj,
	t_view view, t_mlx mlx_data)
{
	double	xt;
	double	yt;
	double	zt;
	double	tmp_y;
	double	tmp_x;

	xt = (double)(point.x - mlx_data.map_size_x / 2);
	yt = (double)(point.y - mlx_data.map_size_y / 2);
	zt = (double)point.z * view.z_scale;
	tmp_y = yt;
	yt = tmp_y * cos(view.angle_x) - zt * sin(view.angle_x);
	zt = tmp_y * sin(view.angle_x) + zt * cos(view.angle_x);
	tmp_x = xt;
	xt = tmp_x * cos(view.angle_y) + zt * sin(view.angle_y);
	zt = -tmp_x * sin(view.angle_y) + zt * cos(view.angle_y);
	tmp_x = xt;
	tmp_y = yt;
	xt = tmp_x * cos(view.angle_z) - tmp_y * sin(view.angle_z);
	yt = tmp_x * sin(view.angle_z) + tmp_y * cos(view.angle_z);
	point_proj->x = xt * view.zoom + view.offset_x;
	point_proj->y = yt * view.zoom + view.offset_y;
	point_proj->z = zt * view.zoom;
	point_proj->color = point.color;
}

void	ft_apply_proj(t_point **tab_point, t_mlx mlx_data)
{
	int	y;
	int	x;

	y = 0;
	while (y < mlx_data.map_size_y)
	{
		x = 0;
		while (x < mlx_data.map_size_x)
		{
			ft_proj(tab_point[y][x], &tab_point[y][x].proj,
				mlx_data.view, mlx_data);
			x++;
		}
		y++;
	}
}

void	ft_set_view(t_mlx *mlx_data, double zoom, double offset_x, double offset_y, double z_scale)
{
	t_view view;

	view.zoom = zoom;
	view.offset_x = offset_x;
	view.offset_y = offset_y;
	view.z_scale = z_scale;


	view.angle_x = 0.615472907;
	view.angle_y = 0;
	view.angle_z = 0.785398163;

	mlx_data->view = view;	
}