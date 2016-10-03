/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_fragment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 00:59:39 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/09 11:09:42 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_uint	rt_process_specular_light(t_ray *ray, t_object *object,
	t_lightdata *ld)
{
	t_vec3		light_reflect;

	if (ld->diffuse > 0.0 && object->spec > 0.0)
	{
		light_reflect = m_vec3scl(&(ld->obj_nrm), 2.0 * m_vec3dot(
			&(ld->obj_nrm), &(ld->obj_to_light.dir)));
		light_reflect = m_vec3sub(&light_reflect, &(ld->obj_to_light.dir));
		return (rt_colorshade(ld->light->color,
			pow(m_vec3dot(&(ray->dir), &light_reflect),
				round(32.0 * object->spec))));
	}
	return (0);
}

static t_uint	rt_process_diffuse_light(t_scene *scene, t_ray *ray,
	t_object *object, t_lightdata *ld)
{
	t_uint		i;
	double		tmp;

	ld->diffuse = m_vec3dot(&(ld->obj_to_light.dir), &(ld->obj_nrm));
	if (ld->diffuse > 0.0)
	{
		ld->obj_to_light_dist = rt_vec3dist(&(ld->obj_to_light.pos),
			&(ld->light->pos));
		i = 0;
		while (i < scene->n_objects)
		{
			if (scene->objects[i]->inter_func(&(ld->obj_to_light),
				scene->objects[i], &tmp) && tmp <= ld->obj_to_light_dist)
				return (ld->pixel_color);
			++i;
		}
		return (rt_coloradd(rt_coloradd(ld->pixel_color, rt_colorshade((
			object->color & ld->light->color), ld->diffuse *
			ld->light->intensity)), rt_process_specular_light(ray, object,
			ld)));
	}
	return (ld->pixel_color);
}

static t_uint	rt_process_ambient_light(t_scene *scene, t_object *object,
	t_lightdata *ld)
{
	if (scene->camera->ambient > 0.0 && scene->camera->ambient <= 1.0)
	{
		return (rt_coloradd(ld->pixel_color, rt_colorshade(object->color,
			scene->camera->ambient)));
	}
	return (ld->pixel_color);
}

t_uint			rt_fragment(t_ray *ray, t_scene *scene, t_object *object,
	double hit_dist)
{
	t_lightdata	ld;
	t_uint		i;

	ld.pixel_color = 0;
	ld.obj_to_light.pos = rt_ray_to_pos(ray, hit_dist - 0.0000001);
	ld.obj_nrm = object->normal_func(ray, rt_ray_to_pos(ray, hit_dist),
		hit_dist, object);
	i = 0;
	while (i < scene->n_lights)
	{
		ld.light = scene->lights[i];
		ld.obj_to_light.dir = rt_lookat(&(ld.obj_to_light.pos),
			&(ld.light->pos));
		ld.pixel_color = rt_process_ambient_light(scene, object, &ld);
		ld.pixel_color = rt_process_diffuse_light(scene, ray, object, &ld);
		++i;
	}
	return (ld.pixel_color);
}
