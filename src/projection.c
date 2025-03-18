/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:31:49 by jowoundi          #+#    #+#             */
/*   Updated: 2025/03/18 19:01:02 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	ft_center(t_map info)
{
	int	center_x;
	int	center_y;

	center_x = WIDTH / 2;
	center_y = HEIGHT / 3;
	info.point[0].projected_x = center_x;
	info.point[0].projected_y = center_y - (info.point[0].z * info.dist);
	return (info);
}

// t_map	coord(t_map info, int ini_x, int ini_y, int	line)
// {
// 	int	i;
// 	int	j;

// 	i = line * info.size_lines;
// 	j = 0;
// 	while (j < info.size_lines)
// 	{
// 		info.point[i + 1].projected_x = ini_x + info.dist;
// 		info.point[i + 1].projected_y = ini_y - (info.dist * info.point[i + 1].z);
// 		ini_x += info.dist;
// 		ini_y -= info.dist;
// 		i++;
// 		j++;
// 	}
// 	return (info);
// }

// t_map	ft_set_point(t_map info)
// {
// 	int	i;
// 	int	j;
// 	int	temp_x;
// 	int	temp_y;

// 	i = 0;
// 	j = 0;
// 	temp_x = info.point[0].projected_x;
// 	temp_y = info.point[0].projected_y;
// 	while (i < info.nbr_lines)
// 	{
// 		info = coord(info, temp_x, temp_y, i);
// 		i++;
// 		temp_x += info.dist;
// 		temp_y += info.dist / 2;
// 	}
// 	return (info);
// }

// t_map	ft_projection(t_map info)
// {
// 	info.dist = 20;
// 	info = ft_center(info);
// 	info = ft_set_point(info);
// 	return (info);
// }
t_map	iso_view(t_map info)
{	
}

t_map	ft_projection(t_map info)
{
	info = ft_center(info);
}
