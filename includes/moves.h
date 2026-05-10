/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <jlepany@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 12:03:25 by jlepany           #+#    #+#             */
/*   Updated: 2026/05/10 17:19:29 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_H
# define MOVES_H

# include "main.h"

void	move_right(t_xserv *server);
void	move_left(t_xserv *server);
void	move_up(t_xserv *server);
void	move_down(t_xserv *server);
void	back_to_center(t_xserv *server);

#endif
