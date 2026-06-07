/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:13:29 by jlepany           #+#    #+#             */
/*   Updated: 2026/06/07 18:03:33 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "libft.h"
#include "main.h"

void	put_pixel_image(t_xserv *serv, int color, int x, int y)
{
	int	index;

	index = x * serv->bit / 8 + y * serv->size;
	*(unsigned int *)(serv->data + index) = color;
}

int	combine_color(t_rgb *color)
{
	int	res;

	res = (color->t << 24 | color->red << 16 | color->green << 8 | color->blue);
	return (res);
}

int	give_nuance(int escape_count)
{
	t_rgb color;
	double normalized_count;
	const double frequency = 25.0;

	if (escape_count == MAX_ITERATIONS) {
        return 0x000000;
    }
	ft_bzero(&color, sizeof(t_rgb));
	normalized_count = (double)escape_count / MAX_ITERATIONS;

	color.red = (int)(sin(frequency * normalized_count + 1.0) / 2.0 * 255.0);
	color.blue = (int)((cos(frequency * normalized_count * 0.8) + 1.0) / 2.0 * 255.0);
	color.green = (int)((sin(frequency * normalized_count * 1.5) + 1.0) / 2.0 * 255.0);
	if (color.red > 255)
		color.red = 255;
	if (color.green > 255)
		color.green = 255;
	if (color.blue > 255)
		color.blue = 255;
	return (combine_color(&color));
}
