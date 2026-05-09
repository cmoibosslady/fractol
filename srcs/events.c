/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <jlepany@student.42,fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:58:52 by jlepany           #+#    #+#             */
/*   Updated: 2026/05/09 15:38:01 by jlepany          ###   ########.fr       */
/*                                                            	              */
/* ************************************************************************** */

#include "includes/events.h"
#include "includes/main.h"
#include "includes/moves.h"
#include "includes/zoom.h"
#include "minilibx-linux/mlx.h"

int	keyhook(int keycode, t_xserv *server)
{
	if ((char)keycode == 27)
		stop_mlx(server);	
	else if (keycode == 65363)
		move_right(server->img_ptr);
	else if (keycode == 65361)
		move_left(server->img_ptr);
	else if (keycode == 65364)
		move_up(server->img_ptr);
	else if (keycode == 65362)
		move_down(server->img_ptr);
	else if (keycode == 32)
		back_to_center(server->img_ptr);
	else
		printf("not supported, use mouse roll or arrows\n");
	return (0);
}

int	mousehook(int mousecode, int x, int y, t_xserv *server)
{
	if (mousecode == 4)
		zoom_in(server->img_ptr, x, y);
	if (mousecode == 5)
		zoom_out(server->img_ptr, x, y);
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
