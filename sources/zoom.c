/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <jlepany@student.42,fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:58:10 by jlepany           #+#    #+#             */
/*   Updated: 2025/02/28 11:24:38 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	zoom_out(t_img *image)
{
	image->x_min -= (image->x_max - image->x_min) * 0.25f;
	image->y_min -= (image->y_max - image->y_min) * 0.25f;
	image->x_max += (image->x_max - image->x_min) * 0.25f;
	image->y_max += (image->y_max - image->y_min) * 0.25f;
}

void	zoom(t_img *img, int x, int y, bool zoom)
{
	double	tmp;

	mlx_clear_window(img->mlx, img->win);
	tmp = img->x_min;
	img->x_min = conversion(x - WIDTH / 2, img->x_min, img->x_max, WIDTH);
	img->x_max = conversion(x + WIDTH / 2, tmp, img->x_max, WIDTH);
	tmp = img->y_min;
	img->y_min = conversion(y - HEIGHT / 2, img->y_min, img->y_max, HEIGHT);
	img->y_max = conversion(y + HEIGHT / 2, tmp, img->y_max, HEIGHT);
	if (zoom)
	{
		img->x_min += (img->x_max - img->x_min) * 0.25f;
		img->x_max -= (img->x_max - img->x_min) * 0.25f;
		img->y_min += (img->y_max - img->y_min) * 0.25f;
		img->y_max -= (img->y_max - img->y_min) * 0.25f;
		img->zoom *= 0.5f;
	}
	else
	{
		zoom_out(img);
		img->zoom *= 1.5f;
	}
	img->fract(img);
}

void	back_to_center(t_img *image)
{
	image->x_min = -2.5f;
	image->y_min = -2.5f;
	image->x_max = 2.5f;
	image->y_max = 2.5f;
	image->zoom = 1.0f;
	image->fract(image);
}
