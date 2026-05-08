#ifndef MAIN_H
# define MAIN_H

# define HEIGTH 1280
# define WIDTH 1000

# include <math.h>
# include <stdbool.h>

typedef struct color
{
	int t;
	int red;
	int green;
	int blue;
}	t_rgb;

typedef struct x_server
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;

	char	*data;
	int		bit;
	int		size;
	int		e;

}	t_xserv;

int		log_error(const char *str);
bool	init_mlx(t_xserv *server);

#endif
