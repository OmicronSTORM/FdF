/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:55:41 by jowoundi          #+#    #+#             */
/*   Updated: 2025/03/04 18:06:28 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_line(t_img_data *img, t_map info, t_dot start, t_dot end)
{
	int		i;

	i = 0;
	info.dx = abs(end.x - start.x);
	info.dy = abs(end.y - start.y);
	info.inc_x = info.dx / info.dist;
	info.inc_y = info.dy / info.dist;
	while (i < info.dist)
	{
		place_pixel(img, start.x, start.y);
		start.x += info.inc_x;
		start.y -= info.inc_y;
		i++;
	}
	// s = (float)info.dy / (float)info.dx;
	// printf("%f\n", s);
}

void	drawline(t_img_data *img, t_map info)
{
	int		i;
	t_dot	a;
	t_dot	b;

	i = 0;
	a.x = WIDTH / 4;
	a.y = HEIGHT / 3;
	info.dist = 20;
	while (i < info.size_lines)
	{
		b.x = a.x + info.dist;
		b.y = a.y + info.dist;
		add_line(img, info, a, b);
		i++;
		a.x += info.dist;
		a.y += info.dist;
	}
}
