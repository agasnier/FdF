/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:47:27 by algasnie          #+#    #+#             */
/*   Updated: 2025/12/13 18:20:54 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ressources/minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"

# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

//manda
# define ISO_ANGLE_X 0.9550
# define ISO_ANGLE_Y 0.7854

//bonus

//angle
# define PARA_ANGLE_X 0
# define PARA_ANGLE_Y 0

//keyboard_events
# define KEY_PRESS	2
# define KEY_PRESS_MASK (1L<<0)
# define MOUSE 4
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define MOUSE_MASK (1L<<2)

//keycode
# define KEY_ESC	0xFF1B
# define KEY_UP		0xFF52
# define KEY_DOWN	0xFF54
# define KEY_LEFT	0xFF51
# define KEY_RIGHT	0xFF53
# define KEY_PLUS	0xFFAB
# define KEY_MINUS	0xFFAD
# define CTRL		0xFFE3
# define SHIFT		0xFFE1
# define KEY_H      0x0068
# define KEY_W		0x0077
# define KEY_A      0x0061 
# define KEY_S      0x0073 
# define KEY_D      0x0064

//heatmap
# define HEATMAP_MIN 0xFF0000
# define HEATMAP_MAX 0x0000FF

typedef struct s_line
{
	int	dx;
	int	dy;
	int	err;
	int	sx;
	int	sy;
} t_line;

typedef struct s_view
{
	double	zoom;
	double	offset_x;
	double	offset_y;
	double	z_scale;
	double	angle_x;
	double	angle_y;
	double	angle_z;
} t_view;

typedef struct s_point_proj
{
	double	x;
	double	y;
	double	z;
	int	color;
	int color_heat;
} t_point_proj;

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	t_point_proj	proj;
	int				color;
	int color_heat;
} t_point;

typedef struct s_img
{
	void	*img_ptr;
	void	*img_data;
	int		bpp;
	int		size_line;
	int		endian;
	
} t_img;

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
} t_mlx;

//ft_projection.c
void	ft_proj(t_point point, t_point_proj *point_proj, t_view view, t_mlx mlx_data);
void	ft_apply_proj(t_point **tab_point, t_mlx mlx_data);
void	ft_set_view_iso(t_mlx *mlx_data);
void	ft_set_view_para(t_mlx *mlx_data);

//ft_initialization.c
void	ft_free_all(t_mlx *mlx_data, int error);
void	ft_create_heat(t_mlx *mlx_data, t_point **tab_point);
int		ft_init_tab(t_point **tab_point, t_mlx mlx_data, char *argv);
t_point	**ft_create_tab(t_mlx mlx_data);

//ft_helper.c
int	ft_take_color(char *line, int *i);
int	ft_size_map(char *argv, t_mlx *mlx_data);
int	ft_atoi(char *line, int *j);

// ft_control.c
int	ft_input_key(int keycode, t_mlx *mlx);
int	ft_input_mouse(int keycode, int x, int y, t_mlx *mlx);

//ft_draw.c
void	ft_put_pixel(t_mlx mlx_data, t_point point);
void	ft_put_line(t_mlx mlx_data, t_point_proj point_a, t_point_proj point_b);
void	ft_draw(t_mlx mlx_data, t_point **tab_point);
void	ft_create_image(t_mlx *mlx_data);

//ft_put_line_helper.c
void	ft_put_line_draw(t_mlx mlx_data, t_line line, t_point bress_a, t_point bress_b);
void	ft_put_line_err(int *err, int dx, int dy);
void	ft_put_line_direc_y(t_point bress_a, t_point bress_b, int *dy, int *sy);
void	ft_put_line_direc_x(t_point bress_a, t_point bress_b, int *dx, int *sx);
void	ft_line_put_to_int(t_point *bress_a, t_point *bress_b, t_point_proj point_a, t_point_proj point_b);

#endif