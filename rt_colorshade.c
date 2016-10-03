/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_colorshade.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 23:59:45 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/08 02:19:30 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_uint	rt_colorshade(t_uint color, float factor)
{
	t_uint	alpha;
	t_uint	red;
	t_uint	green;
	t_uint	blue;

	alpha = (t_uint)(((color & 0xFF000000) >> 24) * factor);
	red = (t_uint)(((color & 0x00FF0000) >> 16) * factor);
	green = (t_uint)(((color & 0x0000FF00) >> 8) * factor);
	blue = (t_uint)((color & 0x000000FF) * factor);
	if (alpha > 255)
		alpha = 255;
	if (red > 255)
		red = 255;
	if (green > 255)
		green = 255;
	if (blue > 255)
		blue = 255;
	return ((alpha << 24) | (red << 16) | (green << 8) | blue);
}
