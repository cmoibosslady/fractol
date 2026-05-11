/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <jlepany@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 13:58:18 by jlepany           #+#    #+#             */
/*   Updated: 2026/05/11 10:57:14 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JULIA_H
# define JULIA_H

# include "main.h"
# include "complex_nb.h"

void	init_julia(t_xserv *server, int ac, char *av[]);
bool	inside_circle(t_cnb *z);
int		inside_julia(t_cnb *z, t_cnb *seed);
void	generate_julia(t_xserv *server);
void	put_julia(t_xserv *server, t_cnb *seed, t_cnb *z);

#endif
