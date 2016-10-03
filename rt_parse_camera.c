/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 03:34:49 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/09 08:23:18 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_camera	*rt_parse_camera(char **args)
{
	if (rt_arrlen(args) != CAM_N_ARGS)
		return (NULL);
	return (rt_new_camera(m_vec3val(rt_atof(args[1]), rt_atof(args[2]),
		rt_atof(args[3])), rt_polardir(rt_atof(args[4]), rt_atof(args[5])),
		rt_atof(args[6])));
}
