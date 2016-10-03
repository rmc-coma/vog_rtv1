/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:38:13 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/09 09:19:50 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	size_t	slen;
	char	*str;

	if (s != NULL && f != NULL)
	{
		slen = ft_strlen(s);
		str = (char *)malloc(sizeof(char) * (slen + 1));
		if (str == NULL)
			return (NULL);
		str[slen] = 0;
		while (slen-- && s[slen])
		{
			str[slen] = f(s[slen]);
		}
		return (str);
	}
	return (NULL);
}
