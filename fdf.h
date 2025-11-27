/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:47:27 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/27 16:11:47 by algasnie         ###   ########.fr       */
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

typedef struct s_mlx
{
	void	*addr_init;
	void	*addr_windows;
	char	*windows_title;
	int		windows_size_x;
	int		windows_size_y;
} t_mlx;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
} t_point;

#endif