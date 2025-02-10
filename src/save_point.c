/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:32:49 by jowoundi          #+#    #+#             */
/*   Updated: 2025/02/10 19:29:33 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void static	count(char *line, int j)
{
	t_dot	dot;
	int		i;

	dot.x = 0;
	i = 0;
	while (line[i])
		{
			if (i != ' ')
			{
				dot.x++;
			}
			i++;
			printf("DX: %d\n", dot.x);
		}
}

int	stock_point(int fd)
{
	t_dot 	dot;
	char	*line;
	int		j;

	j = 0;
	dot.y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		count(line, j);
		dot.y++;
		j++;
		free(line);
	}
	printf("x: %d\n y: %d\n", dot.x, dot.y);
}

int	main()
{
	int fd;

	fd = open("../maps/test_maps/10-2.fdf", O_RDONLY);
	stock_point(fd);
	return (0);
}