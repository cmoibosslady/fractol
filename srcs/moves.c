/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <jlepany@student.42,fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:35:28 by jlepany           #+#    #+#             */
/*   Updated: 2026/05/11 11:47:55 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "moves.h"

void	move_right(t_xserv *server)
{
	server->x_min += server->zoom;
	server->x_max += server->zoom;
}

void	move_left(t_xserv *server)
{
	server->x_min -= server->zoom;
	server->x_max -= server->zoom;
}

void	move_up(t_xserv *server)
{
	server->y_min += server->zoom;
	server->y_max += server->zoom;
}

void	move_down(t_xserv *server)
{
	server->y_min -= server->zoom;
	server->y_max -= server->zoom;
}

void	back_to_center(t_xserv *server)
{
	server->y_min = -2.5;
	server->x_min = -2.5;
	server->y_max = 2.5;
	server->x_max = 2.5;
}
