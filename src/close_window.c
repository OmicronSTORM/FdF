/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:58:11 by jowoundi          #+#    #+#             */
/*   Updated: 2025/04/01 14:52:52 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(1);
	return (0);
}

int	handle_intput(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		close_window(data);
	}
	return (0);
}

int	checkfile(char *av)
{
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	while (av[i] && !ft_strchr(&av[i], '.'))
		i++;
	if (!av[i])
		return (0);
	while (av[i])
	{
		i++;
		temp++;
	}
	i -= temp;
	if (ft_strncmp(&av[i], "fdf", temp))
		return (1);
	return (0);
}

int	check(char **av)
{
	int	sec;

	sec = 1;
	if (!av[1])
		return (ft_printf("argument is missing\n"), 0);
	if (av[2])
		return (ft_printf("too many arguments\n"), 0);
	sec = checkfile(av[1]);
	if (sec == 0)
		return (ft_printf("incompatible file\n"), 0);
	return (1);
}
