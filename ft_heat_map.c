/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heat_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:50:17 by algasnie          #+#    #+#             */
/*   Updated: 2025/12/13 17:54:33 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_color_heat(t_point *point, t_mlx *mlx_data)
{
	float	z_scale;
	int		r;
	int		g;
	int		b;

	if (mlx_data->z_max == mlx_data->z_min)
		z_scale = 0.0;
	else
		z_scale = (float)(point->z - mlx_data->z_min)
			/ (float)(mlx_data->z_max - mlx_data->z_min);
	r = ((HEATMAP_MIN >> 16) & 0xFF) + (int)((((HEATMAP_MAX >> 16) & 0xFF)
				- ((HEATMAP_MIN >> 16) & 0xFF)) * z_scale);
	g = ((HEATMAP_MIN >> 8) & 0xFF) + (int)((((HEATMAP_MAX >> 8) & 0xFF)
				- ((HEATMAP_MIN >> 8) & 0xFF)) * z_scale);
	b = (HEATMAP_MIN & 0xFF) + (int)(((HEATMAP_MAX & 0xFF)
				- (HEATMAP_MIN & 0xFF)) * z_scale);
	point->color_heat = (r << 16) | (g << 8) | b;
}

static void	ft_search_z_min_max(t_mlx *mlx_data, t_point **tab_point)
{
	int	i;
	int	j;

	j = 0;
	mlx_data->z_min = tab_point[0][0].z;
	mlx_data->z_max = tab_point[0][0].z;
	while (j < mlx_data->map_size_y)
	{
		i = 0;
		while (i < mlx_data->map_size_x)
		{
			if (tab_point[j][i].z < mlx_data->z_min)
				mlx_data->z_min = tab_point[j][i].z;
			else if (tab_point[j][i].z > mlx_data->z_max)
				mlx_data->z_max = tab_point[j][i].z;
			i++;
		}
		j++;
	}
}

void	ft_create_heat(t_mlx *mlx_data, t_point **tab_point)
{
	int	i;
	int	j;

	ft_search_z_min_max(mlx_data, mlx_data->tab_point);
	j = 0;
	while (j < mlx_data->map_size_y)
	{
		i = 0;
		while (i < mlx_data->map_size_x)
		{
			ft_color_heat(&tab_point[j][i], mlx_data);
			i++;
		}
		j++;
	}
}
