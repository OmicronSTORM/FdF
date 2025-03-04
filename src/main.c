/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:01:24 by jowoundi          #+#    #+#             */
/*   Updated: 2025/03/04 16:46:14 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_data		data;
	t_img_data	img;
	t_map		map;
	char		*src;

	if (check(av) != 1)
		return(0);
	if (ac)
	{	
		src = av[1];
		map = stock_point(src);
		data.mlx = mlx_init();
		if (!data.mlx)
			return (0);
		img.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
		img.address = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
		drawline(&img, map);
		mlx_start(data, img);
	}
	return (0);
}
