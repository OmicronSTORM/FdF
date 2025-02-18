/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:32:49 by jowoundi          #+#    #+#             */
/*   Updated: 2025/02/18 17:41:11 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	count(char *line, t_map map)
{
	int	i;

	i = 0;
	map.size_lines = 0;
	while (line[i])
		{
			while (line[i] && line[i] != ' ')
				i++;
			map.size_lines++;
			while (line[i] && line[i] == ' ')
				i++;
		}
	return (map);
}

t_map	stock_point(char *src)
{
	t_map	map;
	char	*line;
	int		j;
	int		fd;

	fd = open(src, O_RDONLY);
	j = 0;
	map.nbr_lines = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		map = count(line, map);
		map.nbr_lines++;
		j++;
		free(line);
	}
	printf("x: %d\ny: %d\n", map.size_lines, map.nbr_lines);
	close(fd);
	return (map);
}
