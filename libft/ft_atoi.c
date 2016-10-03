/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:37:40 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/09 09:13:06 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int	ft_atoi(const char *str)
{
	int		n;
	char	s;

	while (*str && (*str == '\n' || *str == ' ' || *str == '\t' \
				|| *str == '\r' || *str == '\v' || *str == '\f'))
		str++;
	s = (*str == 45 ? 1 : 0);
	if (*str == 43 || *str == 45)
		str++;
	n = 0;
	while (*str)
	{
		if (*str > 47 && *str < 58)
			n = n * 10 + ((int)(*str++) - 48);
		else
			break ;
	}
	return (s ? -n : n);
}
