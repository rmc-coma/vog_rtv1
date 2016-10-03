/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_add_object_to_scene.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 06:38:29 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/24 08:25:03 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_bool	rt_add_object_to_scene(t_scene *scene, t_object *object)
{
	t_uint	i;

	i = 0;
	while (scene->objects[i] != NULL)
		if (++i >= scene->n_objects)
			return (FALSE);
	scene->objects[i] = object;
	return (TRUE);
}
