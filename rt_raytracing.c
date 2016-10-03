/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_raytracing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 07:39:34 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/08 02:12:54 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_uint			rt_raytracing(t_ray *ray, t_scene *scene)
{
	double		shortest_dist;
	double		test_dist;
	int			closest_obj_id;
	t_uint		i;

	shortest_dist = DBL_MAX;
	test_dist = 0.0;
	closest_obj_id = -1;
	i = 0;
	while (i < scene->n_objects)
	{
		if (scene->objects[i]->inter_func(ray, scene->objects[i], &test_dist)
			&& test_dist < shortest_dist)
		{
			shortest_dist = test_dist;
			closest_obj_id = i;
		}
		++i;
	}
	if (shortest_dist != DBL_MAX)
	{
		return (rt_fragment(ray, scene, scene->objects[closest_obj_id],
				shortest_dist));
	}
	return (0);
}
