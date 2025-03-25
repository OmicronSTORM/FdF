/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:31:49 by jowoundi          #+#    #+#             */
/*   Updated: 2025/03/25 18:07:45 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_project_iso(t_dot *point, int scale)
{
	point->projected_x = (point->x - point->y) * cos(0.523599) * scale;
	point->projected_y = (point->x + point->y) * sin(0.523599) * scale - point->z * scale;
	point->projected_x += WIDTH / 4;
	point->projected_y += HEIGHT / 3.5;
}

void	ft_compute_scale(t_map *info)
{
	t_projection	proj;
	
	proj.x_range = info->x_max - info->x_min;
	proj.y_range = info->y_max - info->y_min;

	if (proj.x_range == 0)
		proj.x_range = 1;
	if (proj.y_range == 0)
		proj.y_range = 0;
	proj.scale_x = (WIDTH * 0.6) / proj.x_range;
	proj.scale_y = (HEIGHT * 0.6) / proj.y_range;
	info->scale = fmin(proj.scale_x, proj.scale_y);
}

void	ft_size(t_map *info)
{
	int	i;

	i = 1;
	info->x_max = info->point[0].projected_x;
	info->y_max = info->point[0].projected_y;
	info->x_min = info->x_max;
	info->y_min = info->y_max;
	while (i < info->total_points)
	{
		if (info->x_max < info->point[i].projected_x)
			info->x_max = info->point[i].projected_x;
		if (info->x_min > info->point[i].projected_x)
			info->x_min = info->point[i].projected_x;
		if (info->y_max < info->point[i].projected_y)
			info->y_max = info->point[i].projected_y;
		if (info->y_min > info->point[i].projected_y)
			info->y_max = info->point[i].projected_y;
		i++;
	}
	// ft_extend(info);
}

void	ft_rescale_point(t_map *info)
{
	int				i;
	t_projection	proj;

	i = 0;
	proj.center_x = (info->x_max + info->x_min) / 2;
	proj.center_y = (info->y_max + info->y_min) / 2;
	while (i < info->total_points)
	{
		info->point[i].projected_x = WIDTH / 2.4 + (info->point[i].projected_x - proj.center_x);
		info->point[i].projected_y = HEIGHT / 2.6 + (info->point[i].projected_y - proj.center_y);
		i++;
	}
}

void	ft_projection(t_map *info)
{
	int	i;

	i = 0;
	while (i < info->total_points)
	{
		ft_project_iso(&info->point[i], 1);
		i++;
	}
	ft_size(info);
	ft_compute_scale(info);
	i = 0;
	while (i < info->total_points)
	{
		ft_project_iso(&info->point[i], info->scale);
		i++;
	}
	ft_rescale_point(info);
}
