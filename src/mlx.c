/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:55:22 by jowoundi          #+#    #+#             */
/*   Updated: 2025/03/03 16:52:26 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_start(t_data data, t_img_data img)
{
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Fil De Fer");
	if (!data.win)
	{
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		return ;
	}
	mlx_put_image_to_window(data.mlx, data.win, img.img, 0, 0);
	mlx_key_hook(data.win, handle_intput, &data);
	mlx_loop(data.mlx);
}
