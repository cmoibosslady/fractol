/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_nb.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <jlepany@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 14:06:33 by jlepany           #+#    #+#             */
/*   Updated: 2026/05/09 15:32:50 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_NB_PATH
# define COMPLEX_NB_PATH

# include <stdbool.h>

typedef struct complex_nb {
	double	real;
	double	unreal;
}			t_cnb;

t_cnb	*add_complex(t_cnb *a, t_cnb b);
t_cnb	*mul_complex(t_cnb *a, t_cnb b);
t_cnb	*square_complex(t_cnb *z);
double	abs_complex(t_cnb *z);
bool	complex_nan(t_cnb *z);

#endif
