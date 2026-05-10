/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <jlepany@student.42,fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:13:58 by jlepany           #+#    #+#             */
/*   Updated: 2026/05/10 19:17:56 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

double	conversion(int value, double x_min, double x_max, int v_max)
{
	return ((double)(value * (x_max - x_min) / (double)v_max) + x_min);
}
