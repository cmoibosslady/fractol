/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <jlepany@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 10:18:59 by jlepany           #+#    #+#             */
/*   Updated: 2026/05/09 15:22:12 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# define HEIGHT 1280
# define WIDTH 720

# include <math.h>
# include <stdbool.h>

typedef struct x_server
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;

	void	(*fract)(struct x_server *server, int ac, char *av[]);

	char	*data;
	int		bit;
	int		size;
	int		e;

	double	x_min;
	double	y_min;
	double	x_max;
	double	y_max;

	double	zoom;

}	t_xserv;

bool	init_mlx(t_xserv *server);
int		log_error(const char *str);
void	stop_mlx(t_xserv *server);

#endif
