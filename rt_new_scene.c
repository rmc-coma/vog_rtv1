/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_new_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 06:34:35 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/24 08:30:57 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_scene	*rt_new_scene(t_camera *camera, t_uint n_lights, t_uint n_objects)
{
	t_scene	*new;
	t_uint	i;

	new = (t_scene *)malloc(sizeof(t_scene));
	new->camera = camera;
	new->n_objects = n_objects;
	new->objects = (t_object **)malloc(sizeof(t_object *) * (n_objects + 1));
	i = 0;
	while (i <= n_objects)
		new->objects[i++] = NULL;
	new->n_lights = n_lights;
	new->lights = (t_light **)malloc(sizeof(t_light *) * (n_lights + 1));
	i = 0;
	while (i <= n_lights)
		new->lights[i++] = NULL;
	return (new);
}
