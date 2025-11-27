/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:36:55 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/27 16:19:18 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	ft_line_put(t_point *start, t_point *end, t_mlx *mlx)
// {
	
// }

int	ft_input(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(mlx->addr_init, mlx->addr_windows);
		exit(0);
	}
	if (keycode == KEY_UP)
	{
		
	}
	return (0);
}	

int	main(int argc, char **argv)
{
	///////////////////////////////////parsing
	
	if (argc <= 1)
		return (0);

	int fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("errir");
	}

	char *line;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);

	}	


	
	return (0);
	
	





	///////////////////////////////////creation mlx	
	t_mlx	mlx;

	
	
	mlx.addr_init = mlx_init();
	if (!mlx.addr_init)
	{
		return (1); //////error
	}

	mlx.windows_title = "fdf";
	mlx.windows_size_x = 500;
	mlx.windows_size_y = mlx.windows_size_x;
	

	mlx.addr_windows = mlx_new_window(mlx.addr_init, mlx.windows_size_x, mlx.windows_size_y, mlx.windows_title);
	if (!mlx.addr_windows)
	{
		return (1); //////error
	}


	mlx_hook(mlx.addr_windows, KEY_PRESS, KEY_PRESS_MASK, &ft_input, &mlx);
	
	mlx_loop(mlx.addr_init);

	return (0);
}