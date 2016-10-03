/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_process_sphere_normal.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 07:50:04 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/09 10:42:50 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3	rt_process_sphere_normal(t_ray *ray, t_vec3 hit, double dist,
	t_object *sphere)
{
	(void)ray;
	(void)dist;
	return (m_vec3nrm(m_vec3sub(&hit, &(sphere->pos))));
}
