/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_process_cone_normal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 07:56:02 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/09 10:43:23 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3	rt_process_cone_normal(t_ray *ray, t_vec3 hit, double dist,
	t_object *cone)
{
	t_vec3	x;
	t_vec3	t;

	x = m_vec3sub(&(ray->pos), &(cone->pos));
	x = m_vec3scl(&(cone->normal), (rt_sq(tan(cone->angle)) + 1) *
		m_vec3dot(&(ray->dir), &(cone->normal)) * dist + m_vec3dot(&x,
		&(cone->normal)));
	t = m_vec3sub(&hit, &(cone->pos));
	return (m_vec3nrm(m_vec3sub(&t, &x)));
}
