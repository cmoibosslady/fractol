/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <jlepany@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 14:44:16 by jlepany           #+#    #+#             */
/*   Updated: 2026/05/09 15:31:10 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDELBROT_H
# define MANDELBROT_H

# include "main.h"
# include "complex_nb.h"

void	generate_mandelbrot(t_xserv *server);
bool	inside_mandelbrot(t_cnb *z, int limit);
void	init_mandelbrot(t_xserv *server, int ac, char *av[]);
int		mandelbrot_limit(t_cnb *seed);
void	put_mandelbrot(t_xserv *server, t_cnb *seed);

#endif
