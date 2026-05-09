/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <jlepany@student.42,fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:57:25 by jlepany           #+#    #+#             */
/*   Updated: 2026/05/09 15:35:47 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/complex_nb.h"
#include "includes/main.h"
#include "includes/mandelbrot.h"

bool	inside_mandelbrot(t_cnb *z, int i)
{
	if (sqrt(z->unreal) > 4)
		return (false);
	else if (sqrt(z->unreal) <= 4 && sqrt(z->real) >= 4)
		return (false);
	else if (i && abs_complex(z) > 2)
		return (false);
	else
		return (true);
}

int	mandelbrot_limit(t_cnb *seed)
{
	t_cnb	z;
	int		i;

	i = 0;
	while (inside_mandelbrot(&z, i) && i++ < 200 && !complex_nan(&z))
		z = *add_complex(square_complex(&z), *seed);
	return (i);
}

void	put_mandelbrot(t_xserv *server, t_num *seed)
{
	int	limit;
	int	x;
	int	y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			seed->real = conversion(x, img->x_min, img->x_max, WIDTH);
			seed->unreal = conversion(y, img->y_min, img->y_max, HEIGHT);
			if (inside_circle(seed))
				limit = 200;
			else
				limit = mandelbrot(seed);
			if (limit < 0)
				end_program(img);
			put_pixel_image(img, adjust_color(limit, img), x, y);
		}
	}
}

void	init_mandelbrot(t_xserv *server)
{
	t_cnb	seed;

	seed.real = 0.1; 
	seed.unreal = 0.1;
	put_mandelbrot(server, &seed);
	mlx_put_image_to_window(server->mlx_ptr, server->win_ptr, server->img_ptr, 0, 0);
}

void	mandelbrot_frac(t_img *image)
{
	image->fract = init_mandelbrot;
	init_mandelbrot(image);
}
