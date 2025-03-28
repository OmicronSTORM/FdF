/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:34:21 by jowoundi          #+#    #+#             */
/*   Updated: 2025/03/28 22:22:11 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH			1920
# define HEIGHT			1080
# define PI				3.141592653589

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*address;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}		t_data;

typedef struct s_node
{
	char			*line;
	struct s_node	*next;
}		t_node;

typedef struct s_dot
{
	int	x;
	int	y;
	int	z;
	int	projected_x;
	int	projected_y;
}		t_dot;

typedef struct s_projection
{
	float	center_x;
	float	center_y;
	float	scale;
	float	scale_x;
	float	scale_y;
	float	x_range;
	float	y_range;
}		t_projection;

typedef struct s_map
{
	int		size_lines;
	int		nbr_lines;
	t_dot	*point;
	int		total_points;
	int		color;
	float	inc_x;
	float	inc_y;
	int		scale;
	int		x_max;
	int		y_max;
	int		x_min;
	int		y_min;
	int		caract;
}		t_map;

int		handle_intput(int keysym, t_data *data);
t_map	stock_point(char *src);
void	place_pixel(t_data *data, int x, int y);
void	drawline(t_data *img, t_map info);
void	mlx_start(t_data data, char *str);
int		close_window(t_data *data);
int		check(char **av);
void	ft_projection(t_map *info);

#endif