/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:13:29 by jlepany           #+#    #+#             */
/*   Updated: 2026/05/11 11:37:01 by jlepany          ###   ########.fr       */
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

int	give_nuance(int limit)
{
	t_rgb color;

	ft_bzero(&color, sizeof(t_rgb));
	color.blue += 20 * limit;
	if (limit > 3)
		color.green += 15 * limit;
	if (limit > 10)
		color.red += 15 * limit;
	if (limit > 25)
		color.blue += 10 * limit;
	if (limit > 50)
		color.green += 10 * limit;
	if (limit > 75)
		color.red += 10 * limit;
	if (limit > 100) 
		return (give_nuance(limit - 100));
	return (combine_color(&color));
	// previously add taken out this line to make
}
