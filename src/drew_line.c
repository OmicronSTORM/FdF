/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drew_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 05:35:42 by jowoundi          #+#    #+#             */
/*   Updated: 2025/02/14 08:56:21 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drawline(t_img_data *data, t_dot a, t_dot b, t_lines line)
{
	t_lines	line;
	int			i;

	line.dist_x = b.x - a.x;
	line.dist_y = b.y - a.y;
	if (abs(line.dist) > abs(line.dist_y))
		line.dist = abs(line.dist_x);
	else
		line.dist = abs(line.dist_y);
	line.x_icr = line.dist_x / (float)line.dist;
	line.y_icr = line.dist_y / (float)line.dist;
	line.x = a.point_x;
	line.y = a.point_y;
	i = 0;
	while (i <= line.dist)
	{
		if ((line.x > 0 && line.x < WIDTH) && (line.y > 0 && line.y < HEIGHT))
			my_mlx_pixel_put(data, line.x, line.y, a.color);
		line.x += line.x_icr;
		line.y += line.y_icr;
		i++;
	}
}

void	ft_linkpoints(t_img_data *data, t_dot map, t_lines line)
{
	int	i;
	int	k;
	int	tab_limit;

	i = 0;
	k = -1;
	tab_limit = map.x * map.y;
	while (i < tab_limit - 1)
	{
		k++;
		if (k >= map.x - 1)
			k = -1;
		else
			ft_drawline(data, map.points[i], map.points[i + 1], line);
		if (i + map.line_size < tab_limit)
			ft_drawline(data, map.points[i], map.points[i + map.line_size], line);
		i++;
	}
}