/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_and_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <jlepany@student.42,fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:58:52 by jlepany           #+#    #+#             */
/*   Updated: 2025/02/27 14:11:28 by jlepany          ###   ########.fr       */
/*                                                            :q              */
/* ************************************************************************** */

#include "fract_ol.h"

int	keyhook(int keycode, void *image)
{
	if ((char)keycode == 27)
		end_program(image);
	else if (keycode == 65363)
		move_right(image);
	else if (keycode == 65361)
		move_left(image);
	else if (keycode == 65364)
		move_up(image);
	else if (keycode == 65362)
		move_down(image);
	else if (keycode == 32)
		back_to_center(image);
	else
		ft_printf("not supported, use mouse roll or arrows\n");
	return (0);
}

int	end_program(t_img *image)
{
	mlx_destroy_image(image->mlx, image->img);
	mlx_destroy_window(image->mlx, image->win);
	mlx_destroy_display(image->mlx);
	free(image->mlx);
	free(image);
	exit(0);
}

int	mousehook(int mousecode, int x, int y, void *image)
{
	if (mousecode == 4)
		zoom(image, x, y, 1);
	if (mousecode == 5)
		zoom(image, x, y, 0);
	return (0);
}

void	events(t_img *image, void *win_ptr)
{
	mlx_key_hook(win_ptr, keyhook, image);
	mlx_mouse_hook(win_ptr, mousehook, image);
	mlx_hook(win_ptr, 17, 0, end_program, image);
}
