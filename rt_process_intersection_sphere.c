/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_process_intersection_sphere.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 07:58:41 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/09 10:05:21 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_bool	rt_process_intersection_sphere(t_ray *ray, t_object *sphere,
	double *dist)
{
	t_cart	n;
	double	delta;

	n.a = rt_sq(ray->dir.x) + rt_sq(ray->dir.y) + rt_sq(ray->dir.z);
	n.b = 2.0 * (ray->dir.x * (ray->pos.x - sphere->pos.x) +
		ray->dir.y * (ray->pos.y - sphere->pos.y) +
		ray->dir.z * (ray->pos.z - sphere->pos.z));
	n.c = (rt_sq(ray->pos.x - sphere->pos.x) +
		rt_sq(ray->pos.y - sphere->pos.y) +
		rt_sq(ray->pos.z - sphere->pos.z)) - rt_sq(sphere->size);
	delta = rt_sq(n.b) - (4.0 * n.a * n.c);
	if ((delta < 0.0000001) || ((*dist = rt_process_dist(delta, &n)) == 0.0))
		return (FALSE);
	return (TRUE);
}
