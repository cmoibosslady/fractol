/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <jlepany@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 10:19:44 by jlepany           #+#    #+#             */
/*   Updated: 2026/05/11 11:37:11 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "libft.h"

double	ft_atod(const char *str)
{
	double	res;
	int		i;
	int		j;
	double	neg;

	i = 0;
	neg = 1.0f;
	res = 0.0f;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			neg = -1.0f;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10.0f + (double)(str[i++] - '0');
	if (!str[i])
		return (res * neg);
	if (str[i] != '.')
		return (0.0 / 0.0);
	j = i;
	while (str[++i] >= '0' && str[i] <= '9')
		res += (double)(str[i] - '0') * pow(0.1f, i - j);
	res = res * neg;
	return (res);
}

void	ft_bzero(void *mem, size_t size)
{
	size_t i;
	i = 0;
	if (mem == 0)
		return ;
	while (i < size)
		((char *)mem)[i] = '\0';
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t i;
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

size_t	ft_strlen(const char *str)
{
	size_t i;
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

