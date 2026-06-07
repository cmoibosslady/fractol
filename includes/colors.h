/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <jlepany@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 11:35:09 by jlepany           #+#    #+#             */
/*   Updated: 2026/06/07 17:16:48 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include "main.h"

typedef struct colors_rgb {
	unsigned int	t;
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
} 	t_rgb;

int		combine_color(t_rgb *color);
int		give_nuance(int limit);
void	put_pixel_image(t_xserv *serv, int color, int x, int y);

#endif
