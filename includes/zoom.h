/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <jlepany@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 13:52:58 by jlepany           #+#    #+#             */
/*   Updated: 2026/05/10 17:31:48 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOOM_H
# define ZOOM_H

# include "main.h"

void	zoom_in(t_xserv *server, int x, int y);
void	zoom_out(t_xserv *server, int x, int y);

#endif
