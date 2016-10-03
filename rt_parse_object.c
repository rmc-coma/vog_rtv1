/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 03:34:49 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/09 08:24:14 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	*rt_parse_object(char **args)
{
	t_uint	object_type;

	object_type = 0;
	if (rt_arrlen(args) != OBJ_N_ARGS)
		return (NULL);
	if (ft_strequ(args[0], "SPHERE"))
		object_type = OT_SPHERE;
	else if (ft_strequ(args[0], "PLAN"))
		object_type = OT_PLAN;
	else if (ft_strequ(args[0], "CONE"))
		object_type = OT_CONE;
	else if (ft_strequ(args[0], "CYLINDER"))
		object_type = OT_CYLINDER;
	else
		return (NULL);
	return (rt_new_object(object_type, m_vec3val(rt_atof(args[1]),
		rt_atof(args[2]), rt_atof(args[3])), rt_atof(args[12]), rt_objectdata(
		rt_atof(args[4]), ((ft_atoi(args[5]) << 16) + (ft_atoi(args[6]) << 8) +
		(ft_atoi(args[7]))), m_vec3val(rt_atof(args[8]), rt_atof(args[9]),
		rt_atof(args[10])), rt_atof(args[11]))));
}
