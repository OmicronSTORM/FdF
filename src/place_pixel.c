/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:03:50 by jowoundi          #+#    #+#             */
/*   Updated: 2025/02/17 18:43:49 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	place_pixel(t_img_data *data, int x, int y)
{
	char	*dst;
	int	color;
	
	color = 0x00FFFFFF;
	dst = data->address + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
