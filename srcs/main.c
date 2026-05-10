/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <jlepany@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 10:18:27 by jlepany           #+#    #+#             */
/*   Updated: 2026/05/10 19:25:04 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "events.h"
#include "julia.h"
#include "libft.h"
#include "main.h"
#include "mlx.h"

double	conversion(int value, double d_min, double d_max, int v_max) 
	// function to help calculate the value into a graph of a certain pixel
{
	return ((double)(value * (d_max - d_min) / (double)v_max) + d_min);
}

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

int	stop_mlx(t_xserv *server)
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
	{
		init_mandelbrot(&server);
		server.generator = init_mandelbrot;
	}
	else if (!ft_strcmp(av[1], "julia"))
	{
		init_julia(&serv, ac, av);
		server.generator = generate_julia;
	}
	else
		return (log_error("Arg must be: mandelbrot or julia [x] [y]\n"));
	if (init_mlx(&server) == false)
		return (log_error("Cannot init mlx\n"));
	events(&server);
	mlx_loop(server.mlx_ptr);
}
