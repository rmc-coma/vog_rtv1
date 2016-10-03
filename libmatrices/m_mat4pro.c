/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_mat4pro.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 07:27:21 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/02/24 23:50:45 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmatrices.h"

t_mat4	m_mat4pro(double angle, double ratio, double near, double far)
{
	t_mat4	matrix;

	matrix = m_mat4ini();
	angle = angle * M_PI / 180;
	matrix.a.x = 1 / (ratio * tan(angle / 2));
	matrix.b.y = 1 / (tan(angle / 2));
	matrix.c.z = -(-near - far) / (near - far);
	matrix.d.z = 2 * far * near / (near - far);
	matrix.c.w = -1;
	return (matrix);
}
