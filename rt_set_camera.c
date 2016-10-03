/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_set_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 10:45:44 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/07 02:44:57 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_bool	rt_set_camera(t_vec3 pos, t_polardir dir, t_camera *camera)
{
	t_polardir	tmp;

	if (!camera)
		return (FALSE);
	camera->pos = pos;
	camera->pdir = dir;
	tmp = dir;
	camera->dir = rt_polardir_to_vec3dir(tmp);
	tmp.phi = dir.phi;
	tmp.theta = dir.theta + 90.0f;
	camera->up = rt_polardir_to_vec3dir(tmp);
	tmp.phi = dir.phi + 90.0f;
	tmp.theta = 0.0f;
	camera->right = rt_polardir_to_vec3dir(tmp);
	return (TRUE);
}
