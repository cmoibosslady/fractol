/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <jlepany@student.42,fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:13:58 by jlepany           #+#    #+#             */
/*   Updated: 2025/02/27 15:37:54 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

double	ft_abs(double value)
{
	if (value < 0.0)
		return (-value);
	else
		return (value);
}

double	ft_square(double a, int b)
{
	int		i;
	double	res;

	i = 0;
	res = 1.0f;
	while (i++ < b)
		res = res * a;
	return (res);
}

double	ft_sqrt(double square)
{
	double	root;
	int		i;

	i = 0;
	root = 1.0f;
	while (ft_abs(root * root - square) > 0.0001f && i++ < 1000)
		root = 0.5f * (root + square / root);
	return (root);
}

double	conversion(int value, double x_min, double x_max, int v_max)
{
	return ((double)(value * (x_max - x_min) / (double)v_max) + x_min);
}
