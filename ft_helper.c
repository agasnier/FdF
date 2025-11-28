/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:10:29 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/28 15:13:05 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_size_map(t_mlx *mlx_data, char *argv)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (1);

	i = 0;

	mlx_data->map_size_x = 0;
	mlx_data->map_size_y = 0;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		mlx_data->map_size_y++;
		if (mlx_data->map_size_y == 1)
		{
			while (line[i])
			{
				while (line[i] == ' ')
					i++;
				if (line[i] != '\n' && line[i] != '\0')
					mlx_data->map_size_x++;
				while (line [i] && line[i] != ' ')
					i++;
			}
		}
		free(line);
	}
	close(fd);
	return (0);
}

int	ft_atoi(char *line, int *j)
{
	int	number;
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