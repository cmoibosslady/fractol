/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:29:59 by jlepany           #+#    #+#             */
/*   Updated: 2025/02/20 14:55:27 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

bool	ft_isnan(t_num *z)
{
	if (z->real != z->real)
		return (1);
	if (z->unreal != z->unreal)
		return (1);
	return (0);
}

double	abs_complex(t_num *z)
{
	double	res;

	res = z->real * z->real + z->unreal * z->unreal;
	res = ft_sqrt(res);
	return (res);
}

t_num	*square_complex(t_num *z)
{
	double	tmp;

	tmp = z->real;
	z->real = z->real * z->real - z->unreal * z->unreal;
	z->unreal = 2 * tmp * z->unreal;
	return (z);
}

t_num	*add_complex(t_num *a, t_num b)
{
	a->real = a->real + b.real;
	a->unreal = a->unreal + b.unreal;
	return (a);
}

t_num	*mul_complex(t_num *a, t_num b)
{
	a->real = a->real * b.real;
	a->unreal = a->real * b.real;
	return (a);
}
