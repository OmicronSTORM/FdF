/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:01:24 by jowoundi          #+#    #+#             */
/*   Updated: 2025/02/11 19:12:03 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_data		data;
	t_img_data	img;
	t_dot		map;
	int			fd;

	if (!av[1])
		return (ft_printf("Il manque un truc bg\n"), 0);
	while (ac)
	{	
		fd = open("maps/test_maps/42.fdf", O_RDONLY);
		map = stock_point(fd);
		data.mlx = mlx_init();
		if (!data.mlx)
			return (0);
		data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Fil De Fer");
		if (!data.win)
		{
			mlx_destroy_display(data.mlx);
			free(data.mlx);
			return (0);
		}
		img.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
		img.address = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
		my_mlx_pixel_put(&img, WIDTH/4, HEIGHT/4, 0x0000FF00, map);
		mlx_put_image_to_window(data.mlx, data.win, img.img, 0, 0);
		mlx_key_hook(data.win, handle_intput, &data);
		mlx_loop(data.mlx);
	}
	return (0);
}
