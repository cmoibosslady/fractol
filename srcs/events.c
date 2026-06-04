/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <jlepany@student.42,fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:58:52 by jlepany           #+#    #+#             */
/*   Updated: 2026/06/04 13:11:10 by jlepany          ###   ########.fr       */
/*                                                            	              */
/* ************************************************************************** */

#include "events.h"
#include "main.h"
#include "moves.h"
#include "zoom.h"
#include "mlx.h"

int	keyhook(int keycode, void *ptr)
{
	t_xserv	*server;

	server = (t_xserv *)ptr;
	if ((char)keycode == 27)
		stop_mlx(server);	
	else if (keycode == 65363)
		move_right(server);
	else if (keycode == 65361)
		move_left(server);
	else if (keycode == 65364)
		move_up(server);
	else if (keycode == 65362)
		move_down(server);
	else if (keycode == 32)
		back_to_center(server);
	mlx_clear_window(server->mlx_ptr, server->win_ptr);
	server->generator(server);
	return (0);
}

int	mousehook(int mousecode, int x, int y, void *ptr)
{
	t_xserv	*server;
	
	server = (t_xserv *)ptr;
	if (mousecode == 4)
		zoom_in(server->img_ptr, x, y);
	if (mousecode == 5)
		zoom_out(server->img_ptr, x, y);
	mlx_clear_window(server->mlx_ptr, server->win_ptr);
	server->generator(server);
	return (0);
}

void	events(t_xserv *server)
{	
	mlx_key_hook(server->win_ptr, keyhook, server);
	mlx_mouse_hook(server->win_ptr, mousehook, server);
	mlx_hook(server->win_ptr, 17, 0, stop_mlx, server);
}
