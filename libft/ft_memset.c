/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:17:34 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/09 09:16:45 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	if (b == NULL)
		return (NULL);
	while (len)
		((unsigned char *)b)[--len] = (unsigned char)c;
	return (b);
}
