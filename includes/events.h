/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <jlepany@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 11:47:19 by jlepany           #+#    #+#             */
/*   Updated: 2026/05/09 11:56:28 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

void	events(void *server);
int		keyhook(int keycode, void *server);
int		mousehook(int mousecode, int x, int y, void *server);

#endif
