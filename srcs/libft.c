/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <jlepany@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 10:19:44 by jlepany           #+#    #+#             */
/*   Updated: 2026/05/09 10:19:46 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

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

