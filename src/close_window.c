/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:58:11 by jowoundi          #+#    #+#             */
/*   Updated: 2025/04/11 13:11:55 by jowoundi         ###   ########.fr       */
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

int	check_file(char *src)
{
	int	i;

	i = 0;
	if (ft_strchr(src, '.'))
	{
		while (src[i] && src[i] != '.')
			i++;
		if (ft_strncmp(src, "fdf", 3))
			return (1);
		else
			return (0);
	}
	return (0);
}

int	check(char **av)
{
	if (!av[1])
		return (ft_printf("argument is missing\n"), 0);
	if (av[2])
		return (ft_printf("too many arguments\n"), 0);
	if (check_file(av[1]) == 0)
		return (ft_printf("this file doesn't exit\n", 0));
	return (1);
}

void	error_fd()
{
	ft_printf("this file doesn't exit or you can't open it\n");
	exit(1);
}