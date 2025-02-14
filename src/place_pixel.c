/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:03:50 by jowoundi          #+#    #+#             */
/*   Updated: 2025/02/14 08:55:00 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	place_pixel(t_img_data *data, int x, int y, int color, t_dot point)
{
	char	*dst;
	
	dst = data->address + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = point.color;
}
