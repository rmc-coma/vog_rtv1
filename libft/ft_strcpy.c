/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:47:10 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/09 09:18:41 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char *str;

	str = dst;
	while (*src)
		*str++ = *src++;
	*str = 0;
	return (dst);
}
