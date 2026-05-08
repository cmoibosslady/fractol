#include <unistd.h>

#include "includes/libft.h"
#include "includes/main.h"
#include "includes/mlx.h"

int	log_error(const char *str)
{
	return (write(2, str, ft_strlen(str)));
}

bool	init_mlx(t_xserv *server)
{
	mlx_ptr = mlx_init()
}

int main(int ac, char *av[])
{
	t_xserv	server;

	if (ac < 2) 
		return (log_error("Too few arguments\n"));
	if (init_mlx(&server) == false)
		return (log_error("Cannot init mlx\n"));
	if (!ft_strcmp(av[1], "mandelbrot"))
	{

	}
	else if (!ft_strcmp(av[1], "julia"))
	{
	}
	else
		return (log_error("Arg must be: mandelbrot or julia\n"));
}
