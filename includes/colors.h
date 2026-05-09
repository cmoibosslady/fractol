/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <jlepany@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 11:35:09 by jlepany           #+#    #+#             */
/*   Updated: 2026/05/09 11:46:58 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

typedef struct colors_rgb {
	unsigned char	t;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
} 	t_rgb;

int		combine_color(t_rgb *color);
void	give_nuance(t_rgb *color, int limit);

// void	put_pixel_to_img(t_xserv *serv, int color, int x, int y);

#endif
