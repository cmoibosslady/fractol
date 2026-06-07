/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <jlepany@student.42,fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:58:10 by jlepany           #+#    #+#             */
/*   Updated: 2026/06/07 18:01:45 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "zoom.h"

void perform_zoom(t_xserv *server, int x, int y, double factor)
{
    // 1. Trouver le point cible mondial (Wx, Wy) correspondant au pixel (x, y).
    double world_x = conversion(x, server->x_min, server->x_max, WIDTH);
    double world_y = conversion(y, server->y_min, server->y_max, HEIGHT);

    // 2. Calculer le Span actuel (S_old).
    double current_span_x = server->x_max - server->x_min;
    double current_span_y = server->y_max - server->y_min;

    // 3. Calculer le Nouveau Span (S_new) en appliquant le facteur.
    double new_span_x = current_span_x * factor;
    double new_span_y = current_span_y * factor;

    // 4. Définir les nouvelles limites en centrant autour de Wx, Wy.
    server->x_min = world_x - new_span_x / 2.0;
    server->x_max = world_x + new_span_x / 2.0;
    
    server->y_min = world_y - new_span_y / 2.0;
    server->y_max = world_y + new_span_y / 2.0;

    // 5. Mise à jour du facteur de zoom global (si utilisé ailleurs)
    server->zoom *= factor;
}

void zoom_out(t_xserv *server, int x, int y) {
    perform_zoom(server, x, y, ZOOM_FACTOR_OUT);
}

void zoom_in(t_xserv *server, int x, int y) {
    perform_zoom(server, x, y, ZOOM_FACTOR_IN);
}
