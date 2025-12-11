/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:47:27 by algasnie          #+#    #+#             */
/*   Updated: 2025/12/11 15:46:39 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ressources/minilibx_macos/mlx.h"
# include "get_next_line/get_next_line.h"

# include <fcntl.h>
# include <stdlib.h>
# include <math.h>



# define KEY_PRESS	2
# define KEY_PRESS_MASK (1L<<0)

# define KEY_RELEASE 3
# define KEY_RELEASE_MASK (1L<<1)

# define MOUSE 4
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define MOUSE_MASK (1L<<2)

//linux
# define KEY_ESC	0xFF1B //close
# define KEY_UP		0xFF52 //x
# define KEY_DOWN	0xFF54 //x
# define KEY_LEFT	0xFF51 //y
# define KEY_RIGHT	0xFF53 //y
# define KEY_PLUS	0xFFAB //scale_z
# define KEY_MINUS	0xFFAD //scale_z
# define CTRL		0xFFE3
# define KEY_W		0x0077
# define KEY_A      0x0061 
# define KEY_S      0x0073 
# define KEY_D      0x0064

// MAC
// # define KEY_ESC    53
// # define KEY_LEFT   123
// # define KEY_RIGHT  124
// # define KEY_DOWN   125
// # define KEY_UP     126
// # define KEY_PLUS   69
// # define KEY_MINUS  78

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
	int	x;
	int	y;
	int	z;
	int	color;
} t_point_proj;

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	t_point_proj	proj;
	int				color;
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
	t_img	img;
	t_view	view;
	t_point	**tab_point;
} t_mlx;



//ft_initialization.c
void	ft_proj(t_point point, t_point_proj *point_proj, t_view view, t_mlx mlx_data);
void	ft_apply_proj(t_point **tab_point, t_mlx mlx_data);
void	ft_set_view(t_mlx *mlx_data, double zoom, double offset_x, double offset_y, double z_scale);
int		ft_take_color(char *line, int *i);
void	ft_fill_tab(t_point *tab_point, int y, t_mlx mlx_data, char *line);
int		ft_init_tab(t_point **tab_point, t_mlx mlx_data, char *argv);
t_point	**ft_create_tab(t_mlx mlx_data);

//ft_helper.c
int	ft_size_map(t_mlx *mlx_data, char *argv);
int	ft_atoi(char *line, int *j);


// ft_control.c
int	ft_input_key(int keycode, t_mlx *mlx);
int	ft_input_mouse(int keycode, int x, int y, t_mlx *mlx);

//ft_draw.c
void	ft_put_pixel(t_mlx mlx_data, t_img img, t_point_proj point);
void	ft_put_line(t_mlx mlx_data, t_img img, t_point_proj point_a, t_point_proj point_b);
void	ft_draw(t_mlx mlx_data, t_point **tab_point, t_img img);
void	ft_create_image(t_mlx *mlx_data, t_point **tab_point);

//ft_hex_to_int.c
int	ft_str_len(char *str);
int	ft_verif_base(char *base, int len);
char	*ft_atoi_2(char *str, int *sign);
int	ft_in_base(char *str, char *base);
int	ft_atoi_base(char *str, char *base);










#endif