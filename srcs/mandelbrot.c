/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <marvin@42.f>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:57:25 by jlepany           #+#    #+#             */
/*   Updated: 2026/06/07 17:06:20 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "colors.h"
#include "complex_nb.h"
#include "libft.h"
#include "main.h"
#include "mandelbrot.h"
#include "mlx.h"

void	generate_mandelbrot(t_xserv *server)
{
	t_cnb	seed;

	seed.real = 0.1; 
	seed.unreal = 0.1;
	put_mandelbrot(server, &seed);
	mlx_put_image_to_window(server->mlx_ptr, server->win_ptr, server->img_ptr, 0, 0);
	write(1, "Done\n", 5);
}

bool	inside_circle(t_cnb *z)
{
	double	cmp;

	cmp = (z->real + 1) * (z->real + 1) + z->unreal * z->unreal;
	if (cmp < 1/16.0) 
		return (true);
	else
		return (false);
}

bool	inside_mandelbrot(t_cnb *z)
{
	if ((z->unreal * z->unreal) > 4.0)
		return (false);
	else if ((z->unreal * z->unreal) <= 4.0 && (z->real * z->real) >= 4.0)
		return (false);
	else if (abs_complex(z) > 2.0)
		return (false);
	else
		return (true);
}

int	mandelbrot_limit(t_cnb *seed)
{
	t_cnb	z;
	int		i;

	i = 0;
	ft_bzero(&z, sizeof(z));
	while (inside_mandelbrot(&z) && i++ < 200 && !complex_nan(&z))
		z = *add_complex(square_complex(&z), *seed);
	return (i - 1);
}

void	put_mandelbrot(t_xserv *server, t_cnb *seed)
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
			seed->real = conversion(x, server->x_min, server->x_max, WIDTH);
			seed->unreal = conversion(y, server->y_min, server->y_max, HEIGHT);
			if (inside_circle(seed))
				limit = 200;
			else
				limit = mandelbrot_limit(seed);
			put_pixel_image(server, give_nuance(limit), x, y);
		}
	}
}
