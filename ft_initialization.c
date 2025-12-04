/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:09:40 by algasnie          #+#    #+#             */
/*   Updated: 2025/12/04 16:02:07 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_proj(t_point point, t_point_proj *point_proj, t_view view)
{
	double	xt;
	double	yt;
	double	zt;
	double tmp_y;
	double tmp_x;

	xt = (double)point.x;
	yt = (double)point.y;
	zt = (double)point.z;
	
	/////rotate x
	tmp_y = yt;
	yt = tmp_y * cos(view.angle_x) - zt * sin(view.angle_x);
	zt = tmp_y * sin(view.angle_x) + zt * cos(view.angle_x);

	//rotate y
	tmp_x = xt;
	xt = tmp_x * cos(view.angle_y) + zt * sin(view.angle_y);
	zt = -tmp_x * sin(view.angle_y) + zt * cos(view.angle_y);

	//rotate z
	tmp_x = xt;
	tmp_y = yt;
	xt = tmp_x * cos(view.angle_z) - tmp_y * sin(view.angle_z);
	yt = tmp_x * sin(view.angle_z) + tmp_y * cos(view.angle_z);

	point_proj->x = (int)((xt * view.zoom) + view.offset_x);
	point_proj->y = (int)((yt * view.zoom) + view.offset_y);
	point_proj->z = (int)(zt * view.zoom);
	point_proj->color = point.color;
	
	
}

void ft_apply_proj(t_point **tab_point, t_mlx mlx_data)
{
	int	y;
	int	x;
	
	y = 0;
	while (y < mlx_data.map_size_y)
	{
		x = 0;
		while (x < mlx_data.map_size_x)
		{
			ft_proj(tab_point[y][x], &tab_point[y][x].proj, mlx_data.view);
			x++;
		}
		y++;
	}
}

void	ft_set_view(t_mlx *mlx_data, int zoom, int offset_x, int offset_y, int angle)
{
	t_view view;

	view.zoom = zoom;
	view.offset_x = offset_x;
	view.offset_y = offset_y;

	angle = 0;

	view.angle_x = 0;
	view.angle_y = 35 * 3.14159265358979323846 / 180;
	view.angle_z = 45 * 3.14159265358979323846 / 180;

	mlx_data->view = view;	
}

#include <stdio.h>

int	ft_hexa_to_int(char *color)
{
	int	i;

	i = 2;
	color[i] = 'x';
	

	return (0);

	
}

int	ft_take_color(char *line, int *i)
{
	char	color[7];
	char	base[] = "0123456789abcdef";
	int		y;

	y = 0;
	(*i) += 3;
	while (ft_in_base(&line[*i], base) < 0)
	{
		color[y] = line[*i];
		(*i)++;
		y++;
		
	}
	color[y] = '\0';
	return (ft_atoi_base(color, base));

}



void	ft_fill_tab(t_point *tab_point, int y, t_mlx mlx_data, char *line)
{
	int x;
	int i;
	
	i = 0;
	x = 0;
	while (x < mlx_data.map_size_x)
	{
		tab_point[x].y = y;
		tab_point[x].x = x;
		tab_point[x].z = ft_atoi(line, &i);
		if (line[i] == ',')
		{
			tab_point[x].color = ft_take_color(line, &i);
			// while (line[i] && (line[i] != ' ' || line[i] != '\n'))
			// 	i++;
		}
		else
			tab_point[x].color = 16711680; /////////////////////////////16776960 //16711680
		x++;

	}
}

int	ft_init_tab(t_point **tab_point, t_mlx mlx_data, char *argv)
{
	int		fd;
	char	*line;
	int		y;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (1);

	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		ft_fill_tab(tab_point[y], y, mlx_data, line);
		free(line);
		y++;
	}
	close(fd);
	return (0);
}

t_point	**ft_create_tab(t_mlx mlx_data)
{
	t_point **tab_point;
	int		i;
	
	tab_point = malloc(sizeof(t_point*) * (mlx_data.map_size_y + 1));
	if (!tab_point)
		return (NULL);

	i = 0;
	while (i < mlx_data.map_size_y)
	{
		tab_point[i] = malloc(sizeof(t_point) * (mlx_data.map_size_x + 1));
		if (!tab_point[i])
			return (NULL); /////////////////////////////////// + free all 
		i++;
	}
	return (tab_point);	
}