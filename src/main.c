/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:01:24 by jowoundi          #+#    #+#             */
/*   Updated: 2025/02/05 17:41:19 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int	handle_intput(int keysym, t_data *data)
{
	if(keysym == XK_Escape)
	{
		ft_printf("the %d key (ESC) has been pressed \n\n", keysym);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		exit(1);
	}
	ft_printf("the %d key has been pressed\n\n", keysym);
	return (0);
}

int main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (0);
	data.mlx_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "Fil De Fer");
	if (!data.win_ptr)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (0);
	}
	// mlx_key_hook(data.win_ptr, handle_intput, &data);
	mlx_loop(data.mlx_ptr);
}
