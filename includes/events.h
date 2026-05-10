/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <jlepany@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 11:47:19 by jlepany           #+#    #+#             */
/*   Updated: 2026/05/10 19:05:51 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "main.h"

void	events(t_xserv *server);
int		keyhook(int keycode, void *server);
int		mousehook(int mousecode, int x, int y, void *server);

#endif
