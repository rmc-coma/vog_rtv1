/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_vec3to2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 16:00:29 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/02/24 22:45:19 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmatrices.h"

t_vec2	*m_vec3to2(t_vec3 *src, t_vec2 *dst)
{
	dst->x = src->x;
	dst->y = src->y;
	return (dst);
}
