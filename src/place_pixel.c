/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:03:50 by jowoundi          #+#    #+#             */
/*   Updated: 2025/02/12 15:29:06 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color, t_dot point, int dist)
{
	char	*dst;
	int		i;
	int		j;
	int		tmp_x;
	int		tmp_y;

	i = 0;
	j = 0;
	tmp_x = x + dist;
	tmp_y = y - dist / 2;
	while (i++ < point.x)
	{
		dst = data->address + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
		x += dist;
		y -= dist;
		if (i == point.x && j < point.y - 1)
		{
			y = tmp_y;
			x = tmp_x;
			tmp_x += dist;
			tmp_y += dist / 2;
			y += dist;
			dst = data->address + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
			*(unsigned int *)dst = color;
			i = 0;
			j++;
		}
	}
}
