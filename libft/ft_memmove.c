/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:14:35 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/09 09:16:36 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*tmpstr;

	tmpstr = malloc(sizeof(char) * len);
	ft_memcpy(tmpstr, src, len);
	ft_memcpy(dst, tmpstr, len);
	free(tmpstr);
	return (dst);
}
