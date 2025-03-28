/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:55:22 by jowoundi          #+#    #+#             */
/*   Updated: 2025/03/28 22:30:16 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_start(t_data data, char *str)
{
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, str);
	if (!data.win)
	{
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		return ;
	}
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_key_hook(data.win, handle_intput, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
}
