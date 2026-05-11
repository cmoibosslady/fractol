/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <jlepany@student.42,fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:58:10 by jlepany           #+#    #+#             */
/*   Updated: 2026/05/11 11:47:36 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "zoom.h"

void	adjust_zoom(t_xserv *server, int x, int y)
{
	double tmp;

	tmp = server->x_min;
	server->x_min = conversion(x - WIDTH / 2, server->x_min, server->x_max, WIDTH);
	server->x_max = conversion(x + WIDTH / 2, tmp, server->x_max, WIDTH);
	tmp = server->y_min;
	server->y_min = conversion(y - HEIGHT / 2, server->y_min, server->y_max, HEIGHT);
	server->y_max = conversion(y + HEIGHT / 2, tmp, server->y_max, HEIGHT);

}

void	zoom_out(t_xserv *server, int x, int y)
{
	adjust_zoom(server, x, y);
	server->x_min -= (server->x_max - server->x_min) * 0.25f;
	server->y_min -= (server->y_max - server->y_min) * 0.25f;
	server->x_max += (server->x_max - server->x_min) * 0.25f;
	server->y_max += (server->y_max - server->y_min) * 0.25f;
	server->zoom *= 1.5;
}

void	zoom_in(t_xserv *server, int x, int y)
{
	adjust_zoom(server, x, y);
	server->x_min += (server->x_max - server->x_min) * 0.25f;
	server->x_max -= (server->x_max - server->x_min) * 0.25f;
	server->y_min += (server->y_max - server->y_min) * 0.25f;
	server->y_max -= (server->y_max - server->y_min) * 0.25f;
	server->zoom *= 0.5f;
}
