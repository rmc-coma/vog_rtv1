/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_vec3scl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 13:19:11 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/04 04:23:14 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmatrices.h"

t_vec3	m_vec3scl(t_vec3 *vector, T_MATU scalar)
{
	t_vec3	scaled;

	scaled.x = vector->x * scalar;
	scaled.y = vector->y * scalar;
	scaled.z = vector->z * scalar;
	return (scaled);
}
