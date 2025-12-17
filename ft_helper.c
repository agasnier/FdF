/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:10:29 by algasnie          #+#    #+#             */
/*   Updated: 2025/12/17 09:58:10 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_convert_color(char *color)
{
	int		i;
	int		j;
	int		color_dec;

	color_dec = 0;
	i = 0;
	while (color[i])
	{
		color_dec *= 16;
		j = 0;
		while ("0123456789ABCDEFabcdef"[j] != '\0')
		{
			if (color[i] == "0123456789ABCDEFabcdef"[j])
			{
				if (j > 16)
					j -= 6;
				color_dec += j;
				break ;
			}
			j++;
		}
		i++;
	}
	return (color_dec);
}

int	ft_take_color(char *line, int *i)
{
	char	color[7];
	int		y;

	y = 0;
	(*i) += 3;
	while (y < 6 && line[*i] && line[*i] != ' ' && line[*i] != '\n')
	{
		color[y] = line[*i];
		(*i)++;
		y++;
	}
	color[y] = '\0';
	while (line[*i] && line[*i] != ' ' && line[*i] != '\n')
		(*i)++;
	return (ft_convert_color(color));
}

static void	ft_size_map_gnl(int fd, t_mlx *mlx_data)
{
	char	*line;
	int		i;

	i = 0;
	mlx_data->map_size_x = 0;
	mlx_data->map_size_y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		mlx_data->map_size_y++;
		while (mlx_data->map_size_y == 1 && line[i])
		{
			while (line[i] == ' ')
				i++;
			if (line[i] != '\n' && line[i] != '\0')
				mlx_data->map_size_x++;
			while (line [i] && line[i] != ' ')
				i++;
		}
		free(line);
	}
}

int	ft_size_map(char *argv, t_mlx *mlx_data)
{
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		write(2, "error\n", 6);
		return (1);
	}
	ft_size_map_gnl(fd, mlx_data);
	close(fd);
	return (0);
}

int	ft_atoi(char *line, int *j)
{
	int		number;
	int		sign;

	number = 0;
	sign = 1;
	while (line[*j] == ' ')
		(*j)++;
	if (line[*j] == '-' || line[*j] == '+')
	{
		if (line[*j] == '-')
			sign = -1;
		(*j)++;
	}
	while (line[*j] >= '0' && line[*j] <= '9')
	{
		number *= 10;
		number += line[*j] - '0';
		(*j)++;
	}
	number *= sign;
	return (number);
}
