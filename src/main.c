/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:01:24 by jowoundi          #+#    #+#             */
/*   Updated: 2025/02/10 19:13:50 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color, int hein)
{
	char	*dst;
	int		i;

	i = 0;
	while (i++ <= hein)
	{
		dst = data->address + (y * data->line_lenght + x++ * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

int	main(int ac, char **av)
{
	t_data		data;
	t_img_data	img;
	t_dot		*map;
	int			fd;
	char		*line;

	if (!av[1])
		return (printf("Il manque un truc chef\n"), 0);
	while (ac)
	{
		fd = open("maps/test_maps/10-2.fdf", O_RDONLY);
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
		my_mlx_pixel_put(&img, WIDTH/2, HEIGHT/2, 0x0000FF00, ft_atoi(av[1]));
		mlx_put_image_to_window(data.mlx, data.win, img.img, 0, 0);
		mlx_key_hook(data.win, handle_intput, &data);
		mlx_loop(data.mlx);
	}
	return (0);
}
