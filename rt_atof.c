/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 03:37:26 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/08 02:14:51 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float	rt_atof(char *str)
{
	int		tmp;
	int		i;
	t_uint	d;
	float	c;
	char	*dec;

	i = 0;
	while (str[i] && str[i] != '.')
		++i;
	if (str[i] != '.')
		return ((float)ft_atoi(str));
	str[i] = 0;
	dec = &(str[i + 1]);
	tmp = i;
	i = 0;
	while (dec[i])
		++i;
	c = (float)pow(10.0, (double)i);
	i = ft_atoi(str);
	d = ft_atoi(dec);
	str[tmp] = '.';
	return (str[0] != '-' ? (float)i + (float)d / c : (float)i - (float)d / c);
}
