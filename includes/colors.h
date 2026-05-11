/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <jlepany@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 11:35:09 by jlepany           #+#    #+#             */
/*   Updated: 2026/05/11 11:16:16 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include "main.h"

typedef struct colors_rgb {
	unsigned char	t;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
} 	t_rgb;

int		combine_color(t_rgb *color);
int		give_nuance(int limit);
void	put_pixel_image(t_xserv *serv, int color, int x, int y);

#endif
