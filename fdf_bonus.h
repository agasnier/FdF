/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:13:10 by algasnie          #+#    #+#             */
/*   Updated: 2025/12/14 14:58:02 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "struct.h"

//bonus_angle
# define PARA_ANGLE_X 0
# define PARA_ANGLE_Y 0

//bonus_keyboard_events
# define MOUSE 4
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define MOUSE_MASK 4

//bonus_keycode
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
# define HEATMAP_MIN 0x111111
# define HEATMAP_MAX 0xFFFFFF

//ft_control_bonus.c
void	ft_rotation(int keycode, t_mlx *mlx_data);
void	ft_translation(int keycode, t_mlx *mlx_data);
void	ft_manip_view(int keycode, t_mlx *mlx_data);
void	ft_set_view_para(t_mlx *mlx_data);

//ft_heat_map_bonus.c
void	ft_create_heat(t_mlx *mlx_data, t_point **tab_point);

#endif
