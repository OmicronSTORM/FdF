/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:03:50 by jowoundi          #+#    #+#             */
/*   Updated: 2025/02/11 19:04:30 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color, t_dot point)
{
	char	*dst;
	int		i;
	int		j;
	int		dist;
	int		tmp_x;

	i = 0;
	j = 0;
	dist = 20;
	tmp_x = x;
	while (i++ < point.x)
	{
		dst = data->address + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
		x += dist;
		if (i == point.x && j < point.y - 1)
		{
			x = tmp_x;
			y += dist;
			dst = data->address + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
			*(unsigned int *)dst = color;
			i = 0;
			j++;
		}
	}
}
