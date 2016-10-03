/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_new_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 06:31:45 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/05 04:37:11 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_camera	*rt_new_camera(t_vec3 pos, t_polardir dir, float ambient)
{
	t_camera	*new;

	new = (t_camera *)malloc(sizeof(t_camera));
	if (!(rt_set_camera(pos, dir, new)))
		ft_putendl("Failed to create new camera");
	new->ambient = ambient;
	return (new);
}
