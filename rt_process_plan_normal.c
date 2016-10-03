/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_process_plan_normal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 07:55:15 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/09 10:47:02 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3	rt_process_plan_normal(t_ray *ray, t_vec3 hit, double dist,
	t_object *plan)
{
	(void)hit;
	(void)dist;
	(void)ray;
	if (m_vec3dot(&(ray->dir), &(plan->normal)) < 0.0)
		return (plan->normal);
	return (m_vec3scl(&(plan->normal), -1.0));
}
