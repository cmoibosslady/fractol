/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:29:59 by jlepany           #+#    #+#             */
/*   Updated: 2026/06/04 17:37:05 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "complex_nb.h"

bool	complex_nan(t_cnb *z)
{
	if (z->real != z->real)
		return (true);
	if (z->unreal != z->unreal)
		return (true);
	return (false);
}

double	abs_complex(t_cnb *z)
{
	double	res;

	res = z->real * z->real + z->unreal * z->unreal;
	res = sqrt(res);
	return (res);
}

t_cnb	*square_complex(t_cnb *z)
{
	double	tmp;

	tmp = z->real;
	z->real = z->real * z->real - z->unreal * z->unreal;
	z->unreal = 2 * tmp * z->unreal;
	return (z);
}

t_cnb	*add_complex(t_cnb *a, t_cnb b)
{
	a->real = a->real + b.real;
	a->unreal = a->unreal + b.unreal;
	return (a);
}

t_cnb	*mul_complex(t_cnb *a, t_cnb b)
{
	a->real = a->real * b.real;
	a->unreal = a->real * b.real;
	return (a);
}
