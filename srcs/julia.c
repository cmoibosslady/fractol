/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <jlepany@student.42,fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:24:32 by jlepany           #+#    #+#             */
/*   Updated: 2026/05/10 16:23:44 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "julia.h"
#include "mandelbrot.h"
#include "minilibx-linux/mlx.h"

bool	inside_circle(t_cnb *z)
{
	double	tmp1;
	double	tmp2;

	tmp1 = z->real + 1.0f;
	tmp1 = sqrt(tmp1);
	tmp1 += sqrt(z->unreal);
	tmp2 = 0.0645f;
	if (tmp1 < tmp2)
		return (true);
	tmp1 = z->real - 0.25f;
	tmp1 = sqrt(tmp1) + sqrt(z->unreal);
	tmp2 = sqrt(tmp1) - 2 * tmp1 + 0.25f;
	if (z->real < tmp2 - 0.01f)
		return (true);
	return (false);
}

int	inside_julia(t_cnb *z, t_cnb *seed)
{
	int	i;

	i = 0;
	while (inside_mandelbrot(z, i) && i++ < 200 && !complex_nan(z))
		z = add_complex(square_complex(z), *seed);
	return (i);
}

void	put_julia(t_xserv *server, t_cnb *seed, t_cnb *z)
{
	int		x;
	int		y;
	int		limit;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			z->real = conversion(x, img->x_min, img->x_max, WIDTH);
			z->unreal = conversion(y, img->y_min, img->y_max, HEIGHT);
			limit = julia(z, seed);
			put_pixel_image(server, adjust_color(limit, img), x, y);
		}
	}
	free(z);
}

void	julia(t_xserv *server, t_cnb *seed)
{
	t_cnb	z;

	z.real = 0;
	z.unreal = 0;
	put_julia(server, seed, &z);
	mlx_put_image_to_window(server->mlx_ptr, server->win_ptr, server->img_ptr, 0, 0);
}

void	init_julia(t_xserv *server, int ac, char **av)
{
	t_cnb seed;
	if (ac == 4)
	{
		seed.real = ft_atod(argv[2]);
		seed.unreal = ft_atod(argv[3]);
		if (complex_nan(&seed) == true)
			stop_mlx(server);
	}
	events(image, image->win);
	mlx_loop(image->mlx);
}
