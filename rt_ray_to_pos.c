/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray_to_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 00:46:41 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/08 02:13:12 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3	rt_ray_to_pos(t_ray *ray, double dist)
{
	return (m_vec3val(ray->pos.x + ray->dir.x * dist,
					ray->pos.y + ray->dir.y * dist,
					ray->pos.z + ray->dir.z * dist));
}
