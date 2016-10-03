/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:10:47 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/09 09:18:33 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int c;

	c = 0;
	while (*s1)
		c += *(unsigned char *)s1++;
	while (*s2)
		c -= *(unsigned char *)s2++;
	return (c);
}
