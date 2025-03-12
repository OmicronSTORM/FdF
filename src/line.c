/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:55:41 by jowoundi          #+#    #+#             */
/*   Updated: 2025/03/12 17:28:31 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	add_line(t_img_data *img, t_dot a, t_dot b, t_map info)
// {
// 	int	i;

// 	i = 0;
// }

// void	drawline(t_img_data *img, t_map info)
// {
// 	int	i;
// 	int	j;
	
// 	i = 0;
// 	j = -1;

// 	while (i < info.total_points - 1)
// 	{
// 		j++;
// 		if (j >= info.size_lines - 1)
// 			j = -1;
// 		else
// 			add_line(img, info.point[i], info.point[i + 1], info);
// 		if (i + info.size_lines < info.total_points)
// 			add_line(img, info.point[i], info.point[i + info.size_lines], info);
// 		i++;
// 	}
// }

void	add_line(t_img_data *img, t_map info, t_dot start, t_dot end)
{
	int		i;

	i = 0;
	info.dx = abs(end.x - start.x);
	info.dy = abs(end.y - start.y);
	info.inc_x = info.dx / info.dist;
	info.inc_y = info.dy / info.dist;
	while (i < info.dx)
	{
		place_pixel(img, start.x, start.y);
		start.x += info.inc_x;
		i++;
	}
	i = 0;
	while (i < info.dy)
	{
		place_pixel(img, start.x, start.y);
		start.y += info.inc_y;
		i++;
	}
	// s = (float)info.dy / (float)info.dx;
	// printf("%f\n", s);
}

void	drawline(t_img_data *img, t_map info)
{
	int		i;
	int		j;
	int		tmp_i;
	t_dot	a;
	t_dot	b;

	i = 0;
	j = 0;
	a.x = WIDTH / 4;
	a.y = HEIGHT / 3;
	info.dist = 20;
	tmp_i = a.x;
	while (i < info.size_lines)
	{
		b.x = a.x + info.dist;
		b.y = a.y + info.dist;
		add_line(img, info, a, b);
		i++;
		a.x += info.dist;
		if (i == info.size_lines && j < info.nbr_lines)
		{
			a.y += info.dist;
			j++;
			a.x = tmp_i;
			i = 0;
		}
	}
}
