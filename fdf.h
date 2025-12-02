/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:47:27 by algasnie          #+#    #+#             */
/*   Updated: 2025/12/02 13:54:36 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ressources/minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"

# include <stdio.h>

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define KEY_ESC 0xFF1B
# define KEY_UP    0xFF52
# define KEY_DOWN  0xFF54
# define KEY_LEFT  0xFF51
# define KEY_RIGHT 0xFF53
# define KEY_PRESS 2
# define KEY_PRESS_MASK (1L<<0)

typedef struct s_view
{
	int	zoom;
	int	offset_x;
	int	offset_y;
	int	angle;
} t_view;

typedef struct s_mlx
{
	void	*addr_init;
	void	*addr_windows;
	char	*windows_title;
	int		windows_size_x;
	int		windows_size_y;
	int		map_size_x;
	int		map_size_y;
	t_view	view;
} t_mlx;

typedef struct s_point_proj
{
	double	x;
	double	y;
	double	z;
	int	color;
} t_point_proj;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	t_point_proj proj;
	int	color;
} t_point;

typedef struct s_img
{
	void	*img_ptr;
	void	*img_data;
	int		bpp;
	int		size_line;
	int		endian;
	
} t_img;



//ft_initialization.c
void	ft_set_view(t_mlx *mlx_data, int zoom, int offset_x, int offset_y, int angle);
void	ft_fill_tab(t_point *tab_point, int y, t_mlx mlx_data, char *line);
int		ft_init_tab(t_point **tab_point, t_mlx mlx_data, char *argv);
t_point	**ft_create_tab(t_mlx mlx_data);

//ft_helper.c
int	ft_size_map(t_mlx *mlx_data, char *argv);
int	ft_atoi(char *line, int *j);


// ft_control.c
int	ft_input(int keycode, t_mlx *mlx);

//ft_draw.c
void	ft_put_pixel(t_mlx mlx_data, t_img img, t_point_proj point);
void	ft_put_line(t_mlx mlx_data, t_img img, t_point_proj point_a, t_point_proj point_b);














#endif