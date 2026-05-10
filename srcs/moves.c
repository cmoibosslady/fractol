/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <jlepany@student.42,fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:35:28 by jlepany           #+#    #+#             */
/*   Updated: 2026/05/10 17:44:25 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "includes/moves.h"

void	move_right(t_xserv *server)
{
	mlx_clear_window(server->mlx_ptr, server->win_ptr);
	server->x_min += server->zoom;
	server->x_max += server->zoom;
	server->fract(server, 0, 0);
}

void	move_left(t_xserv *server)
{
	mlx_clear_window(server->mlx_ptr, server->win_ptr);
	server->x_min -= server->zoom;
	server->x_max -= server->zoom;
	server->fract(server, 0, 0);
}

void	move_up(t_xserv *server)
{
	mlx_clear_window(server->mlx_ptr, server->win_ptr);
	server->y_min += server->zoom;
	server->y_max += server->zoom;
	server->fract(server, 0, 0);
}

void	move_down(t_xserv *server)
{
	mlx_clear_window(server->mlx_ptr, server->win_ptr);
	server->y_min -= server->zoom;
	server->y_max -= server->zoom;
	server->fract(server, 0, 0);
}

void	back_to_center(t_xserv *server)
{
	mlx_clear_window(server->mlx_ptr, server->win_ptr);
	server->y_min = -2.5;
	server->x_min = -2.5;
	server->y_max = 2.5;
	server->x_max = 2.5;
	server->fract(server, 0, 0);
}
