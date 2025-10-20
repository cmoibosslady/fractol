/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <jlepany@student.42,fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:57:25 by jlepany           #+#    #+#             */
/*   Updated: 2025/02/27 16:13:53 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

bool	inside_mandelbrot(t_num *z, int i)
{
	if (ft_square(z->unreal, 2) > 4)
		return (0);
	else if (ft_square(z->unreal, 2) <= 4 && ft_square(z->real, 2) >= 4)
		return (0);
	else if (i && abs_complex(z) > 2)
		return (0);
	else
		return (1);
}

int	mandelbrot(t_num *seed)
{
	t_num	*z;
	int		i;

	i = 0;
	z = ft_calloc(1, sizeof(t_num));
	if (!z)
	{
		free(seed);
		return (-1);
	}
	while (inside_mandelbrot(z, i) && i++ < 200 && !ft_isnan(z))
		z = add_complex(square_complex(z), *seed);
	free(z);
	return (i);
}

void	put_mandelbrot(t_img *img, t_num *seed)
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

void	init_mandelbrot(t_img *img)
{
	t_num	*seed;

	seed = init_complex(0.1f, 0.1f);
	if (!seed)
		end_program(img);
	put_mandelbrot(img, seed);
	free(seed);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	events(img, img->win);
}

void	mandelbrot_frac(t_img *image)
{
	image->fract = init_mandelbrot;
	init_mandelbrot(image);
	mlx_loop(image->mlx);
}
