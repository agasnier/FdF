/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:47:27 by algasnie          #+#    #+#             */
/*   Updated: 2025/12/17 09:26:13 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ressources/minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "struct.h"
# include "fdf_bonus.h"

//define_bonus
# ifndef BONUS
#  define BONUS 0
# endif

//manda_angle
# define ISO_ANGLE_X 0.9550
# define ISO_ANGLE_Y 0.7854

//mada_keycode
# define KEY_ESC	0xFF1B

//keyboard_events
# define KEY_PRESS	2
# define KEY_PRESS_MASK 1

//ft_projection.c
void	ft_proj(t_point point, t_point_proj *point_proj,
			t_view view, t_mlx mlx_data);
void	ft_apply_proj(t_point **tab_point, t_mlx mlx_data);
void	ft_set_view_iso(t_mlx *mlx_data);

//ft_initialization.c
void	ft_free_all(t_mlx *mlx_data, int error);
void	ft_init_tab(t_point **tab_point, t_mlx mlx_data, char *argv);
t_point	**ft_create_tab(t_mlx mlx_data);

//ft_helper.c
int		ft_take_color(char *line, int *i);
int		ft_size_map(char *argv, t_mlx *mlx_data);
int		ft_atoi(char *line, int *j);

// ft_control.c
int		ft_input_key(int keycode, t_mlx *mlx);
int		ft_input_mouse(int keycode, int x, int y, t_mlx *mlx);

//ft_draw.c
void	ft_put_pixel(t_mlx mlx_data, t_point point);
void	ft_put_line(t_mlx mlx_data, t_point_proj point_a, t_point_proj point_b);
void	ft_draw(t_mlx mlx_data, t_point **tab_point);
void	ft_create_image(t_mlx *mlx_data);

//ft_put_line_helper.c
void	ft_put_line_draw(t_mlx mlx_data, t_line line,
			t_point bress_a, t_point bress_b);
void	ft_put_line_err(int *err, int dx, int dy);
void	ft_put_line_direc_y(t_point bress_a, t_point bress_b, int *dy, int *sy);
void	ft_put_line_direc_x(t_point bress_a, t_point bress_b, int *dx, int *sx);
void	ft_line_put_to_int(t_point *bress_a, t_point *bress_b,
			t_point_proj point_a, t_point_proj point_b);

#endif