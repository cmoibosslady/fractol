/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <jlepany@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 10:18:59 by jlepany           #+#    #+#             */
/*   Updated: 2026/05/21 03:41:29 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# define HEIGHT 720
# define WIDTH 1280

# include <math.h>
# include <stdbool.h>

# include "complex_nb.h"

typedef struct x_server
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;

	void	(*generator)(struct x_server *server);

	char	*data;
	int		bit;
	int		size;
	int		e;

	double	x_min;
	double	y_min;
	double	x_max;
	double	y_max;

	double	zoom;

	t_cnb	julia_seed;

}	t_xserv;

double	conversion(int value, double x_min, double x_max, int v_max);
bool	init_mlx(t_xserv *server);
int		log_error(const char *str);
int		stop_mlx(t_xserv *server);

#endif
