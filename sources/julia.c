/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <jlepany@student.42,fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:24:32 by jlepany           #+#    #+#             */
/*   Updated: 2025/02/28 11:16:38 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

bool	inside_circle(t_num *z)
{
	double	tmp1;
	double	tmp2;

	tmp1 = z->real + 1.0f;
	tmp1 = ft_square(tmp1, 2);
	tmp1 += ft_square(z->unreal, 2);
	tmp2 = 0.0645f;
	if (tmp1 < tmp2)
		return (1);
	tmp1 = z->real - 0.25f;
	tmp1 = ft_square(tmp1, 2) + ft_square(z->unreal, 2);
	tmp2 = ft_sqrt(tmp1) - 2 * tmp1 + 0.25f;
	if (z->real < tmp2 - 0.01f)
		return (1);
	return (0);
}

int	julia(t_num *z, t_num *seed)
{
	int	i;

	i = 0;
	while (inside_mandelbrot(z, i) && i++ < 200 && !ft_isnan(z))
		z = add_complex(square_complex(z), *seed);
	return (i);
}

void	put_julia(t_img *img, t_num *seed, t_num *z)
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
			put_pixel_image(img, adjust_color(limit, img), x, y);
		}
	}
	free(z);
}

void	init_julia(t_img *img)
{
	t_num	*seed;
	t_num	*z;

	seed = init_complex(img->julx, img->july);
	if (!seed)
		end_program(img);
	z = init_complex(0, 0);
	if (!z)
	{
		free(seed);
		end_program(img);
	}
	put_julia(img, seed, z);
	free(seed);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

void	julia_frac(t_img *image, int argc, char **argv)
{
	image->julx = -1.0f;
	if (argc == 4)
	{
		image->julx = ft_atod(argv[2]);
		image->july = ft_atod(argv[3]);
		if (image->julx != image->julx || image->july != image->july)
			end_program(image);
	}
	else
		ft_printf("Switching to default parameters : seed = -1.0 + 0.0i\n");
	image->fract = init_julia;
	init_julia(image);
	events(image, image->win);
	mlx_loop(image->mlx);
}
