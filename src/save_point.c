/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:32:49 by jowoundi          #+#    #+#             */
/*   Updated: 2025/03/25 00:54:01 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	count_line(char *line, t_map map)
{
	char	**sep;
	int		i;

	i = 0;
	map.size_lines = 0;
	sep = ft_split(line, ' ');
	while (sep[i])
	{
		map.size_lines++;
		i++;
	}
	return (map);
}

static t_map	read_line(char *line, t_map map, int y)
{
	int		i;
	int		x;
	int		j;
	char	**sep;

	i = 0;
	x = 0;
	y -= 1;
	j = y * map.size_lines;
	sep = ft_split(line, ' ');
	while (sep[i])
	{
		map.point[j].x = x;
		map.point[j].y = y;
		map.point[j].z = ft_atoi(sep[i]);
		x++;
		i++;
		j++;
	}
	return (map);
}

t_map	stock_line(char *src, t_map map)
{
	int		y;
	int		fd;
	char	*line;

	y = 0;
	fd = open(src, O_RDONLY);
	map.total_points = map.size_lines * map.nbr_lines;
	map.point = malloc(sizeof(char *) * map.total_points);
	line = NULL;
	while (1)
	{
		y++;
		line = get_next_line(fd);
		if (!line)
		{
			break;
		}
		map = read_line(line, map, y);
		free(line);
	}
	close(fd);
	return (map);
}

t_map	stock_point(char *src)
{
	char	*line;
	int		fd;
	t_map	map;

	map.nbr_lines = 0;
	line = NULL;
	fd = open(src, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		map = count_line(line, map);
		map.nbr_lines++;
		free(line);
	}
	close(fd);
	map = stock_line(src, map);
	return (map);
}
