/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:08:53 by jlepany           #+#    #+#             */
/*   Updated: 2025/02/27 16:13:22 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# define HEIGHT 1000
# define WIDTH 1000

# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"

# include <math.h>
# include <stdbool.h>

typedef struct complexNumber
{
	double	real;
	double	unreal;
}	t_num;

typedef struct color
{
	int	t;
	int	red;
	int	green;
	int	blue;
}	t_rgb;

typedef struct image
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	double	julx;
	double	july;
	double	zoom;
	void	(*fract)(struct image *image);
	int		bit;
	int		size;
	int		e;
}	t_img;

bool	ft_isnan(t_num *z);
double	abs_complex(t_num *z);
t_num	*square_complex(t_num *z);
t_num	*add_complex(t_num *a, t_num b);
t_num	*mul_complex(t_num *a, t_num b);

t_num	*init_complex(double a, double b);
t_img	*init_img(void *mlx_ptr, void *win_ptr);

double	ft_atod(char *str);
double	ft_sqrt(double z);
double	ft_abs(double value);
double	conversion(int value, double x_min, double x_max, int v_max);
double	ft_square(double a, int b);

bool	inside_circle(t_num *seed);
int		julia(t_num *z, t_num *seed);
void	put_julia(t_img *image, t_num *seed, t_num *z);
void	init_julia(t_img *image);
void	julia_frac(t_img *image, int argc, char **argv);

void	zoom(t_img *image, int x, int y, bool zoom);
void	zoom_out(t_img *image);
void	back_to_center(t_img *image);

bool	inside_mandelbrot(t_num *z, int i);
int		mandelbrot(t_num *seed);
void	put_mandelbrot(t_img *image, t_num *seed);
void	mandelbrot_frac(t_img *image);

void	put_pixel_image(t_img *image, int color, int x, int y);
int		adjust_color(int limit, t_img *image);

void	move_left(t_img *image);
void	move_right(t_img *image);
void	move_up(t_img *image);
void	move_down(t_img *image);

int		keyhook(int keycode, void *image);
int		end_program(t_img *image);
void	events(t_img *image, void *win_ptr);
void	close_and_exit(void *mlx_ptr, void *win_ptr, void *image);

#endif
