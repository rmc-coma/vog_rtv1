/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_process_intersection_plan.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 05:54:15 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/09 10:55:52 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_bool	rt_process_intersection_plan(t_ray *ray, t_object *plan, double *dist)
{
	t_vec3	x;
	double	xv;
	double	dv;

	x = m_vec3sub(&(ray->pos), &(plan->pos));
	xv = -(m_vec3dot(&x, &(plan->normal)));
	dv = m_vec3dot(&(ray->dir), &(plan->normal));
	if (dv == 0.0)
		return (FALSE);
	if ((*dist = xv / dv) < 0.0)
		return (FALSE);
	return (TRUE);
}
