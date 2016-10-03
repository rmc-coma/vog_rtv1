/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_process_intersection_cone.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 12:13:22 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/09 10:26:46 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_bool	rt_process_intersection_cone(t_ray *ray, t_object *cone, double *dist)
{
	t_vec3	x;
	double	k;
	t_cart	n;
	double	delta;

	x = m_vec3sub(&(ray->pos), &(cone->pos));
	k = rt_sq(rt_dtan(cone->angle)) + 1;
	n.a = m_vec3dot(&(ray->dir), &(ray->dir)) - k *
		rt_sq(m_vec3dot(&(ray->dir), &(cone->normal)));
	n.b = 2 * (m_vec3dot(&(ray->dir), &x) - k * m_vec3dot(&(ray->dir),
		&(cone->normal)) * m_vec3dot(&x, &(cone->normal)));
	n.c = m_vec3dot(&x, &x) - k * rt_sq(m_vec3dot(&x, &(cone->normal)));
	delta = rt_sq(n.b) - (4.0 * n.a * n.c);
	if ((delta < 0.0000001) || ((*dist = rt_process_dist(delta, &n)) == 0.0))
		return (FALSE);
	return (TRUE);
}
