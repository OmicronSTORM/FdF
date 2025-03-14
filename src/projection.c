/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:31:49 by jowoundi          #+#    #+#             */
/*   Updated: 2025/03/14 19:40:47 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	ft_center(t_map info)
{
	int	center_x;
	int	center_y;

	center_x = WIDTH / 2;
	center_y = HEIGHT / 2;
	center_x = center_x - ((info.size_lines / 2) * info.dist);
	center_y = center_y + ((info.nbr_lines / 2) * info.dist);
	info.point[0].projected_x = center_x;
	info.point[0].projected_y = center_y + (info.point[0].z * info.dist);
	return (info);
}

t_map	ft_set_point(t_map info)
{
	int	i;
	int	j;
	int	k;
	int	temp_x;
	int	temp_y;

	i = 0;
	j = 0;
	k = 1;
	temp_x = info.point[0].x;
	temp_y - info.point[0].y;
	while (i < info.nbr_lines)
	{
		while (j < info.size_lines)
		{
			info.point[k].projected_x = temp_x + info.dist;
			info.point[k].projected_y = temp_y + (info.dist * info.point[k].z);
			temp_x += info.dist;
			temp_y += info.dist;
			k++;
			j++;
		}
		
	}
	return (info);
}

t_map	ft_projection(t_map info)
{
	info.dist = 20;
	info = ft_center(info);
	info = ft_set_point(info);
	return (info);
}