/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:58:11 by jowoundi          #+#    #+#             */
/*   Updated: 2025/03/03 16:50:19 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int	handle_intput(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		exit(1);
	}
	return (0);
}

int	check(char **av)
{
	if (!av[1])
		return (ft_printf("Il manque un truc bg\n"), 0);
	if (av[2])
		return (ft_printf("Trop d'arguments\n"), 0);
	return (1);
}