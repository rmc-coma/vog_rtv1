/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 03:34:49 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/09 08:23:55 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	*rt_parse_light(char **args)
{
	if (rt_arrlen(args) != LIGHT_N_ARGS)
		return (NULL);
	return (rt_new_light(m_vec3val(rt_atof(args[1]), rt_atof(args[2]),
		rt_atof(args[3])), ((ft_atoi(args[4]) << 16) + (ft_atoi(args[5]) << 8)
		+ (ft_atoi(args[6]))), rt_atof(args[7])));
}
