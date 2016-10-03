/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_process_intersection_cylinder.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 12:13:22 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/09 08:09:36 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_bool	rt_process_intersection_cylinder(t_ray *ray, t_object *cylinder,
	double *dist)
{
	t_vec3	x;
	t_cart	n;
	double	delta;

	x = m_vec3sub(&(ray->pos), &(cylinder->pos));
	n.a = m_vec3dot(&(ray->dir), &(cylinder->normal));
	n.a = m_vec3dot(&(ray->dir), &(ray->dir)) - n.a * n.a;
	n.b = 2.0 * (m_vec3dot(&(ray->dir), &x) - m_vec3dot(&(ray->dir),
		&(cylinder->normal)) * m_vec3dot(&x, &(cylinder->normal)));
	n.c = m_vec3dot(&x, &(cylinder->normal));
	n.c = m_vec3dot(&x, &x) - n.c * n.c - rt_sq(cylinder->size);
	delta = rt_sq(n.b) - (4.0 * n.a * n.c);
	if ((delta < 0.0000001) || ((*dist = rt_process_dist(delta, &n)) == 0.0))
		return (FALSE);
	return (TRUE);
}
