/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:01:24 by jowoundi          #+#    #+#             */
/*   Updated: 2025/02/07 14:17:21 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int	handle_intput(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		ft_printf("the %d key (ESC) has been pressed \n\n", keysym);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		exit(1);
	}
	ft_printf("the %d key has been pressed\n\n", keysym);
	return (0);
}

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;
	
	dst = data->address + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	t_data		data;
	t_img_data	img;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (0);
	img.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Fil De Fer");
	if (!data.win)
	{
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		return (0);
	}
	img.address = mlx_get_data_addr(img.img, &img.bits_per_pixel, img.line_lenght, img.endian);
	mlx_key_hook(data.win, handle_intput, &data);
	mlx_loop(data.mlx);
}
