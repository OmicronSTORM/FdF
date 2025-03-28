/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:03:50 by jowoundi          #+#    #+#             */
/*   Updated: 2025/03/28 19:07:31 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	place_pixel(t_data *d, int x, int y)
{
	char	*dst;
	int		color;

	color = 0x00FFFFFF;
	dst = d->address + (y * d->line_lenght + x * (d->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
