/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_new_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 07:27:55 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/09 08:18:38 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_bool	rt_fetch_intersection_function(int type, t_object *object)
{
	if (type == OT_SPHERE)
	{
		object->inter_func = rt_process_intersection_sphere;
		object->normal_func = rt_process_sphere_normal;
	}
	else if (type == OT_PLAN)
	{
		object->inter_func = rt_process_intersection_plan;
		object->normal_func = rt_process_plan_normal;
	}
	else if (type == OT_CYLINDER)
	{
		object->inter_func = rt_process_intersection_cylinder;
		object->normal_func = rt_process_cylinder_normal;
	}
	else if (type == OT_CONE)
	{
		object->inter_func = rt_process_intersection_cone;
		object->normal_func = rt_process_cone_normal;
	}
	else
		return (FALSE);
	return (TRUE);
}

t_object		*rt_new_object(int type, t_vec3 pos, float spec,
	t_objectdata objdat)
{
	t_object	*new;

	new = (t_object *)malloc(sizeof(t_object));
	if (!rt_fetch_intersection_function(type, new))
	{
		ft_putendl("Object unrecognized");
		return (NULL);
	}
	new->type = type;
	new->pos = pos;
	new->size = objdat.size;
	new->color = objdat.color;
	new->normal = objdat.normal;
	new->angle = objdat.angle;
	new->spec = spec;
	return (new);
}
