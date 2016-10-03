/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_objectdata.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 13:10:11 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/08 02:23:26 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_objectdata	rt_objectdata(float size, t_uint color, t_vec3 normal,
	float angle)
{
	t_objectdata	objdat;

	objdat.size = size;
	objdat.color = color;
	objdat.normal = m_vec3nrm(normal);
	objdat.angle = angle;
	return (objdat);
}
