/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_and_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <jlepany@student.42,fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:58:52 by jlepany           #+#    #+#             */
/*   Updated: 2026/05/09 11:59:30 by jlepany          ###   ########.fr       */
/*                                                            	              */
/* ************************************************************************** */

#include "includes/events.h"
#include "includes/main.h"
#include "minilibx-linux/mlx.h"

int	keyhook(int keycode, void *server)
{
	t_xserv * serv;

	serv = (t_xserv *)server;
	if ((char)keycode == 27)
		stop_mlx(serv);	
	else if (keycode == 65363)
		move_right(serv->img_ptr);
	else if (keycode == 65361)
		move_left(serv->img_ptr);
	else if (keycode == 65364)
		move_up(serv->img_ptr);
	else if (keycode == 65362)
		move_down(serv->img_ptr);
	else if (keycode == 32)
		back_to_center(serv->img_ptr);
	else
		printf("not supported, use mouse roll or arrows\n");
	return (0);
}

int	mousehook(int mousecode, int x, int y, void *server)
{
	t_xserv *serv;

	serv = (t_xserv *)server;
	if (mousecode == 4)
		zoom(serv->img_ptr, x, y, 1);
	if (mousecode == 5)
		zoom(serv->img_ptr, x, y, 0);
	return (0);
}

void	events(void *server)
{
	t_xserv *serv;
	
	serv = (t_xserv *)server;
	mlx_key_hook(serv->win_ptr, keyhook, serv->img_ptr);
	mlx_mouse_hook(serv->win_ptr, mousehook, serv->img_ptr);
	mlx_hook(serv->win_ptr, 17, 0, stop_mlx(serv), serv);
}
