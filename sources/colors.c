/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:13:29 by jlepany           #+#    #+#             */
/*   Updated: 2025/02/27 16:13:00 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	put_pixel_image(t_img *image, int color, int x, int y)
{
	int	index;

	index = x * image->bit / 8 + y * image->size;
	*(unsigned int *)(image->data + index) = color;
}

t_rgb	*init_color(t_rgb *color)
{
	color->t = 0x00;
	color->red = 0x00;
	color->green = 0x00;
	color->blue = 0x00;
	return (color);
}

int	combine_color(t_rgb *color)
{
	int	res;

	res = (color->t << 24 | color->red << 16 | color->green << 8 | color->blue);
	free(color);
	return (res);
}

void	give_nuance(t_rgb *color, int limit)
{
	color = init_color(color);
	color->blue += 20 * limit;
	if (limit > 3)
		color->green += 15 * limit;
	if (limit > 10)
		color->red += 15 * limit;
	if (limit > 25)
		color->blue += 10 * limit;
	if (limit > 50)
		color->green += 10 * limit;
	if (limit > 75)
		color->red += 10 * limit;
	if (limit > 100)
		give_nuance(color, limit - 100);
}

int	adjust_color(int limit, t_img *image)
{
	t_rgb	*color;

	color = ft_calloc(1, sizeof(t_rgb));
	if (!color)
		end_program(image);
	give_nuance(color, limit);
	if (limit >= 200)
		color = init_color(color);
	return (combine_color(color));
}
/*
int	main(int argc, char **argv)
{
	int	limit;
	int	color;

	if (argc == 1)
		return (0);
	limit = ft_atoi(argv[1]);
	color = adjust_color(limit);
	ft_printf("color = %X\n", color);
}*/
