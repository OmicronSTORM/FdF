/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:31:49 by jowoundi          #+#    #+#             */
/*   Updated: 2025/03/12 17:56:37 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_center(t_map *info)
{
	int	center_x;
	int	center_y;

	center_x = WIDTH / 2;
	center_y = HEIGHT / 2;
	center_x = center_x - (((float)info->size_lines / 2) * info->dist);
	center_y = center_y + (((float)info->nbr_lines / 2) * info->dist);
	
}

t_map	ft_projection(t_map info)
{
	int	i;

	i = 0;
	ft_center(&info)
}