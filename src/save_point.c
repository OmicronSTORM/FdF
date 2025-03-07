/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:32:49 by jowoundi          #+#    #+#             */
/*   Updated: 2025/03/04 13:39:23 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	count(char *line, t_map map)
{
	int	i;

	i = 0;
	map.size_lines = 0;
	char **spl = NULL;
	spl = ft_split(line, ' ');
	while (i++, spl[i])
		;
	map.size_lines = i;
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
	line = NULL;
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
	close(fd);
	return (map);
}