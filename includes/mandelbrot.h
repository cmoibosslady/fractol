/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <jlepany@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 14:44:16 by jlepany           #+#    #+#             */
/*   Updated: 2026/06/04 11:12:37 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDELBROT_H
# define MANDELBROT_H

# include "main.h"
# include "complex_nb.h"

void	generate_mandelbrot(t_xserv *server);
bool	inside_circle(t_cnb *z);
bool	inside_mandelbrot(t_cnb *z);
int		mandelbrot_limit(t_cnb *seed);
void	put_mandelbrot(t_xserv *server, t_cnb *seed);

#endif
