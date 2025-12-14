/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:57:20 by algasnie          #+#    #+#             */
/*   Updated: 2025/12/14 14:59:03 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_line
{
	int	dx;
	int	dy;
	int	err;
	int	sx;
	int	sy;
}	t_line;

typedef struct s_view
{
	double	zoom;
	double	offset_x;
	double	offset_y;
	double	z_scale;
	double	angle_x;
	double	angle_y;
	double	angle_z;
}	t_view;

typedef struct s_point_proj
{
	double	x;
	double	y;
	double	z;
	int		color;
	int		color_heat;
}	t_point_proj;

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	t_point_proj	proj;
	int				color;
	int				color_heat;
}	t_point;

typedef struct s_img
{
	void	*img_ptr;
	void	*img_data;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*addr_init;
	void	*addr_windows;
	char	*windows_title;
	int		windows_size_x;
	int		windows_size_y;
	int		map_size_x;
	int		map_size_y;
	int		z_min;
	int		z_max;
	int		heat;
	t_img	img;
	t_view	view;
	t_point	**tab_point;
}	t_mlx;

#endif