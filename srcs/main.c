/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <jlepany@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 10:18:27 by jlepany           #+#    #+#             */
/*   Updated: 2026/05/09 13:58:01 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "includes/libft.h"
#include "includes/main.h"
#include "minilibx-linux/mlx.h"

int	log_error(const char *str)
{
	return (write(2, str, ft_strlen(str)));
}

bool	init_mlx(t_xserv *server)
{
	server->mlx_ptr = mlx_init();
	if (!server->mlx_ptr)
		return (false);
	server->win_ptr = mlx_new_window(server->mlx_ptr, WIDTH, HEIGHT, "Fractol");
	if (!server->win_ptr)
		return (false);
	server->img_ptr = mlx_new_image(server->mlx_ptr, WIDTH, HEIGHT);
	if (!server->img_ptr)
		return (false);
	server->data = mlx_get_data_addr(server->img_ptr, &server->bit, &server->size, &server->e);
	if (!server->data)
		return (false);
	return (true);
}

void	stop_mlx(t_xserv *server)
{
	if (server->img_ptr)
		mlx_destroy_image(server->mlx_ptr, server->win_ptr);
	if (server->win_ptr)
		mlx_destroy_window(server->mlx_ptr, server->win_ptr);
	if (server->mlx_ptr)
		mlx_destroy_display(server->mlx_ptr);
}

int main(int ac, char *av[])
{
	t_xserv	server;

	if (ac < 2) 
		return (log_error("Too few arguments\n"));
	ft_bzero(&server, sizeof(t_xserv));
	if (!ft_strcmp(av[1], "mandelbrot"))
		server.fract = &mandelbrot(&server);
	else if (!ft_strcmp(av[1], "julia") && ac == 4)
		server.fract = &julia(&server, ac, av);
	else
		return (log_error("Arg must be: mandelbrot or julia [x] [y]\n"));
	if (init_mlx(&server) == false)
		return (log_error("Cannot init mlx\n"));
}
