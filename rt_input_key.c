/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_input_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 06:51:05 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/09 05:16:26 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_handle_camera_pos(int keycode, t_camera *cam)
{
	t_vec3		dir;
	t_polardir	pdir;

	if (keycode == KC_W || keycode == KC_S)
	{
		dir = rt_polardir_to_vec3dir(cam->pdir);
		cam->pos = keycode == KC_W ?
			m_vec3add(&(cam->pos), &dir) : m_vec3sub(&(cam->pos), &dir);
	}
	if (keycode == KC_A || keycode == KC_D)
	{
		pdir = cam->pdir;
		pdir.phi -= 90.0f;
		dir = rt_polardir_to_vec3dir(pdir);
		cam->pos = keycode == KC_A ?
			m_vec3add(&(cam->pos), &dir) : m_vec3sub(&(cam->pos), &dir);
	}
	if (keycode == KC_SPACE || keycode == KC_LCTRL)
	{
		pdir = cam->pdir;
		pdir.theta -= 90.0f;
		dir = rt_polardir_to_vec3dir(pdir);
		cam->pos = keycode == KC_LCTRL ?
			m_vec3add(&(cam->pos), &dir) : m_vec3sub(&(cam->pos), &dir);
	}
}

void	rt_handle_camera_orientation(int keycode, t_env *env)
{
	if (keycode == KC_ARR_UP)
		rt_set_camera(env->main->camera->pos,
					rt_polardir(env->main->camera->pdir.phi,
								env->main->camera->pdir.theta + 4.0f),
					env->main->camera);
	if (keycode == KC_ARR_RIGHT)
		rt_set_camera(env->main->camera->pos,
					rt_polardir(env->main->camera->pdir.phi,
								env->main->camera->pdir.theta - 4.0f),
					env->main->camera);
	if (keycode == KC_ARR_LEFT)
		rt_set_camera(env->main->camera->pos,
					rt_polardir(env->main->camera->pdir.phi - 4.0f,
								env->main->camera->pdir.theta),
					env->main->camera);
	if (keycode == KC_ARR_DOWN)
		rt_set_camera(env->main->camera->pos,
					rt_polardir(env->main->camera->pdir.phi + 4.0f,
								env->main->camera->pdir.theta),
					env->main->camera);
}

int		rt_input_key(int keycode, t_env **env_ptr)
{
	t_env		*env;

	env = *env_ptr;
	if (keycode == KC_ESCAPE)
		rt_exit(NULL, env_ptr);
	if (keycode >= KC_ARR_LEFT && keycode <= KC_ARR_UP)
		rt_handle_camera_orientation(keycode, env);
	if (keycode == KC_W || (keycode >= KC_A && keycode <= KC_D) ||
		keycode == KC_LCTRL || keycode == KC_SPACE)
		rt_handle_camera_pos(keycode, env->main->camera);
	rt_expose(env_ptr);
	return (0);
}
