/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:32:49 by jowoundi          #+#    #+#             */
/*   Updated: 2025/02/12 15:44:00 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_dot	count(char *line, t_dot dot)
{
	int	i;

	i = 0;
	dot.x = 0;
	while (line[i])
		{
			while (line[i] && line[i] != ' ')
				i++;
			dot.x++;
			while (line[i] && line[i] == ' ')
				i++;
		}
	return (dot);
}

t_dot	stock_point(char *src)
{
	t_dot 	dot;
	char	*line;
	int		j;
	int		fd;

	fd = open(src, O_RDONLY);
	j = 0;
	dot.y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		dot = count(line, dot);
		dot.y++;
		j++;
		free(line);
	}
	printf("x: %d\ny: %d\n", dot.x, dot.y);
	close(fd);
	return (dot);
}
