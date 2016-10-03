/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_vec2mag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 03:14:37 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/09 09:03:17 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmatrices.h"

double	m_vec2mag(t_vec2 *vector)
{
	return (sqrt(vector->x * vector->x + vector->y * vector->y));
}
