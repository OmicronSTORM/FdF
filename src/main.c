/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:01:24 by jowoundi          #+#    #+#             */
/*   Updated: 2025/03/28 20:34:10 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_data		data;
	t_map		map;
	char		*src;

	if (check(av) != 1)
		return (0);
	if (ac)
	{
		src = av[1];
		map = stock_point(src);
		ft_projection(&map);
		data.mlx = mlx_init();
		if (!data.mlx)
			return (0);
		data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
		data.address = mlx_get_data_addr(data.img, &data.bits_per_pixel,
				&data.line_lenght, &data.endian);
		drawline(&data, map);
		mlx_start(data, av[1]);
	}
	return (0);
}
