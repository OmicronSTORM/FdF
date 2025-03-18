/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:55:41 by jowoundi          #+#    #+#             */
/*   Updated: 2025/03/18 17:59:14 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_line(t_img_data *img, t_dot a, t_dot b, t_map info)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	info.dx = b.projected_x - a.projected_x;
	info.dy = b.projected_y - a.projected_y;
	if (info.dx > info.dy)
		info.dist = info.dx;
	else
		info.dist = info.dy;
	info.inc_x = info.dx / (float)info.dist;
	info.inc_y = info.dy / (float)info.dist;
	x = a.projected_x;
	y = a.projected_y;
	while (i <= info.dist)
	{
		if ((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT))
			place_pixel(img, x, y);
		x += info.inc_x;
		y += info.inc_y;
		i++;
	}
}

void	drawline(t_img_data *img, t_map info)
{
	int	i;
	int	j;
	
	i = 0;
	j = -1;

	while (i < info.total_points - 1)
	{
		j++;
		if (j >= info.size_lines - 1)
			j = -1;
		else
			add_line(img, info.point[i], info.point[i + 1], info);
		if (i + info.size_lines < info.total_points)
			add_line(img, info.point[i], info.point[i + info.size_lines], info);
		i++;
	}
}
