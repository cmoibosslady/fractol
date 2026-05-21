/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <marvin@42.f>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:24:32 by jlepany           #+#    #+#             */
/*   Updated: 2026/05/21 09:02:23 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <unistd.h>

#include "colors.h"
#include "events.h"
#include "julia.h"
#include "libft.h"
#include "mandelbrot.h"
#include "mlx.h"

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
			z->real = conversion(x, server->x_min, server->x_max, WIDTH);
			z->unreal = conversion(y, server->y_min, server->y_max, HEIGHT);
			limit = inside_julia(z, seed);
			put_pixel_image(server, give_nuance(limit), x, y);
		}
	}
}

void	generate_julia(t_xserv *server)
{
	t_cnb	z;

	z.real = 0;
	z.unreal = 0;
	put_julia(server, &server->julia_seed, &z);
	mlx_put_image_to_window(server->mlx_ptr, server->win_ptr, server->img_ptr, 0, 0);
	write(1, "Done\n", 5);
}

void	init_julia(t_xserv *server, int ac, char **av)
{
	t_cnb seed;
	if (ac == 4)
	{
		seed.real = ft_atod(av[2]);
		seed.unreal = ft_atod(av[3]);
		if (complex_nan(&seed) == true)
			stop_mlx(server);
	}
	else {
		seed.real = 1.0;
		seed.unreal = 0.0;
	}
	server->julia_seed.real = seed.real;
	server->julia_seed.unreal = seed.unreal;
}
