/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:09:40 by algasnie          #+#    #+#             */
/*   Updated: 2025/12/14 16:10:20 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_free_all_helper(void)
{
	write(2, "error\n", 6);
	exit(1);
}

void	ft_free_all(t_mlx *mlx_data, int error)
{
	int	i;

	i = 0;
	while (mlx_data->tab_point && mlx_data->tab_point[i])
	{
		free(mlx_data->tab_point[i]);
		i++;
	}
	if (mlx_data && mlx_data->tab_point != NULL)
	{
		free(mlx_data->tab_point);
		mlx_data->tab_point = NULL;
	}
	if (mlx_data && mlx_data->img.img_ptr)
		mlx_destroy_image(mlx_data->addr_init, mlx_data->img.img_ptr);
	if (mlx_data && mlx_data->addr_windows)
		mlx_destroy_window(mlx_data->addr_init, mlx_data->addr_windows);
	if (mlx_data && mlx_data->addr_init)
	{
		mlx_destroy_display(mlx_data->addr_init);
		free(mlx_data->addr_init);
	}
	if (error)
		ft_free_all_helper();
}

static void	ft_fill_tab(t_point *tab_point, int y, t_mlx mlx_data, char *line)
{
	int	x;
	int	i;

	i = 0;
	x = 0;
	while (x < mlx_data.map_size_x)
	{
		tab_point[x].y = y;
		tab_point[x].x = x;
		tab_point[x].z = ft_atoi(line, &i);
		if (line[i] == ',')
			tab_point[x].color = ft_take_color(line, &i);
		else
			tab_point[x].color = 0xFF0000;
		x++;
	}
}

void	ft_init_tab(t_point **tab_point, t_mlx mlx_data, char *argv)
{
	int		fd;
	char	*line;
	int		y;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_free_all(&mlx_data, 1);
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
}

t_point	**ft_create_tab(t_mlx mlx_data)
{
	t_point	**tab_point;
	int		i;

	tab_point = malloc(sizeof(t_point *) * (mlx_data.map_size_y + 1));
	if (!tab_point)
		return (NULL);
	i = 0;
	while (i < mlx_data.map_size_y)
	{
		tab_point[i] = malloc(sizeof(t_point) * (mlx_data.map_size_x + 1));
		if (!tab_point[i])
		{
			while (i > 0)
			{
				i--;
				free(tab_point[i]);
			}
			free(tab_point);
			write(2, "error\n", 6);
			return (NULL);
		}
		i++;
	}
	tab_point[i] = NULL;
	return (tab_point);
}
