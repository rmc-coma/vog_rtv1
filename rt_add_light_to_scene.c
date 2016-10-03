/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_add_light_to_scene.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 06:41:30 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/24 08:24:55 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_bool	rt_add_light_to_scene(t_scene *scene, t_light *light)
{
	t_uint	i;

	i = 0;
	while (scene->lights[i] != NULL)
		if (++i >= scene->n_lights)
			return (FALSE);
	scene->lights[i] = light;
	return (TRUE);
}
