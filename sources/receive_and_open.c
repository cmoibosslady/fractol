/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_and_open.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <jlepany@student.42,fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:03:19 by jlepany           #+#    #+#             */
/*   Updated: 2025/02/26 14:06:43 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_num	*init_complex(double a, double b)
{
	t_num	*z;

	z = ft_calloc(1, sizeof(t_num));
	if (!z)
		return (0);
	z->real = a;
	z->unreal = b;
	return (z);
}

double	ft_atod(char *str)
{
	double	res;
	int		i;
	int		j;
	double	neg;

	i = 0;
	neg = 1.0f;
	res = 0.0f;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			neg = -1.0f;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10.0f + (double)(str[i++] - '0');
	if (!str[i])
		return (res * neg);
	if (str[i] != '.')
		return (0.0 / 0.0);
	j = i;
	while (str[++i] >= '0' && str[i] <= '9')
		res += (double)(str[i] - '0') *ft_square(0.1f, i - j);
	res = res * neg;
	return (res);
}

t_img	*init_img(void *mlx_ptr, void *win_ptr)
{
	t_img	*img;

	img = ft_calloc(1, sizeof(t_img));
	if (!img)
		return (0);
	img->mlx = mlx_ptr;
	img->win = win_ptr;
	img->img = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	if (!img->img)
		return (0);
	img->data = mlx_get_data_addr(img->img, &img->bit, &img->size, &img->e);
	if (!img->data)
	{
		mlx_destroy_image(mlx_ptr, img->img);
		return (0);
	}
	img->x_min = -2.5f;
	img->x_max = 2.5f;
	img->y_min = -2.5f;
	img->y_max = 2.5f;
	img->zoom = 1.0f;
	return (img);
}

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*image;

	if (argc == 1)
		return (ft_printf("parameters:\nJulia\nMandelbrot\n"));
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (0);
	win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Mandelbrot");
	if (!win_ptr)
		return (0);
	image = init_img(mlx_ptr, win_ptr);
	if (!image)
		return (mlx_destroy_window(mlx_ptr, win_ptr));
	if (!ft_strncmp(argv[1], "Julia", 5))
		julia_frac(image, argc, argv);
	else if (!ft_strncmp(argv[1], "Mandelbrot", 10))
		mandelbrot_frac(image);
	else
		ft_printf("invalid args\nparameters:\nJulia\nMandelbrot\n");
}
