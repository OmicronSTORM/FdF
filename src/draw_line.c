/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 05:35:42 by jowoundi          #+#    #+#             */
/*   Updated: 2025/02/18 17:31:14 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	slope_less_than_one(t_img_data *data, int dx, int dy, t_dot *a)
{
	int	p;
	int	i;

	i = 0;
	p = 2 * abs(dy) - abs(dx);
	place_pixel(data, a->x, a->y);
	while (i++ < abs(dx))
	{
		if (dx > 0)
			a->x += 1;
		else
			a->x -= 1;
		if (p < 0)
			p = p + 2 * abs(dy);
		else
		{
			if (dy > 0)
				a->y += 1;
			else
				a->y -= 1;
			p = p + 2 * abs(dx) - 2 * abs(dx);
		}
		place_pixel(data, a->x, a->y);
	}
}

static void	slope_bigger_than_one(t_img_data *data, int dx, int dy, t_dot *a)
{
	int	p;
	int	i;

	i = 0;
	p = 2 * abs(dx) - abs(dy);
	place_pixel(data, a->x, a->y);
	while (i++ < abs(dy))
	{
		if (dy > 0)
			a->y += 1;
		else
			a->y -= 1;
		if (p < 0)
			p = p + 2 * abs(dx);
		else
		{
			if (dx > 0)
				a->x += 1;
			else
				a->x -= 1;
			p = p + 2 * abs(dx) - 2 * abs(dy);
		}
		place_pixel(data, a->x, a->y);
	}
}

void	drawline(t_img_data *data,t_dot *a, t_dot *b)
{
	int	dx;
	int	dy;

	dx = b->x - a->x;
	dy = b->y - a->y;
	if (abs(dx) > abs(dy))
		slope_less_than_one(data, dx, dy, a);
	else
		slope_bigger_than_one(data, dx, dy, a);
}

void	coordonate(t_img_data *data, t_dot maps)
{
	
}