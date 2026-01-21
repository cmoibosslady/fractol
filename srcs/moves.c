/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <jlepany@student.42,fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:35:28 by jlepany           #+#    #+#             */
/*   Updated: 2025/02/27 11:07:33 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	move_right(t_img *image)
{
	mlx_clear_window(image->mlx, image->win);
	image->x_min += image->zoom;
	image->x_max += image->zoom;
	image->fract(image);
}

void	move_left(t_img *image)
{
	mlx_clear_window(image->mlx, image->win);
	image->x_min -= image->zoom;
	image->x_max -= image->zoom;
	image->fract(image);
}

void	move_up(t_img *image)
{
	mlx_clear_window(image->mlx, image->win);
	image->y_min += image->zoom;
	image->y_max += image->zoom;
	image->fract(image);
}

void	move_down(t_img *image)
{
	mlx_clear_window(image->mlx, image->win);
	image->y_min -= image->zoom;
	image->y_max -= image->zoom;
	image->fract(image);
}
