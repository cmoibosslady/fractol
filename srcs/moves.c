/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <jlepany@student.42,fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:35:28 by jlepany           #+#    #+#             */
/*   Updated: 2026/05/09 13:52:38 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "includes/moves.h"

void	move_right(t_xserv *server)
{
	mlx_clear_window(server->mlx_ptr, server->win_ptr);
	server->x_min += server->zoom;
	server->x_max += server->zoom;
	server->fract(server);
}

void	move_left(t_xserv *server)
{
	mlx_clear_window(server->mlx_ptr, server->win_ptr);
	server->x_min -= server->zoom;
	server->x_max -= server->zoom;
	server->fract(server);
}

void	move_up(t_xserv *server)
{
	mlx_clear_window(server->mlx_ptr, server->win_ptr);
	server->y_min += server->zoom;
	server->y_max += server->zoom;
	server->fract(server);
}

void	move_down(t_xserv *server)
{
	mlx_clear_window(server->mlx_ptr, server->win_ptr);
	server->y_min -= server->zoom;
	server->y_max -= server->zoom;
	server->fract(server);
}
