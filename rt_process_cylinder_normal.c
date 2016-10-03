/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_process_cylinder_normal.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 07:56:02 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/09 10:43:44 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3	rt_process_cylinder_normal(t_ray *ray, t_vec3 hit, double dist,
	t_object *cylinder)
{
	double	m;
	t_vec3	x;
	t_vec3	tmp;

	x = m_vec3sub(&(ray->pos), &(cylinder->pos));
	m = m_vec3dot(&(ray->dir), &(cylinder->normal)) * dist + m_vec3dot(&x,
		&(cylinder->normal));
	x = m_vec3sub(&hit, &(cylinder->pos));
	tmp = m_vec3scl(&(cylinder->normal), m);
	return (m_vec3nrm(m_vec3sub(&x, &tmp)));
}
