/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_colorfade.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 23:59:45 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/08 02:18:16 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_uint	rt_colorfade(t_uint color, float fadefactor)
{
	t_uint	alpha;
	t_uint	red;
	t_uint	green;
	t_uint	blue;

	alpha = (t_uint)(((color & 0xFF000000) >> 24) / fadefactor);
	red = (t_uint)(((color & 0x00FF0000) >> 16) / fadefactor);
	green = (t_uint)(((color & 0x0000FF00) >> 8) / fadefactor);
	blue = (t_uint)((color & 0x000000FF) / fadefactor);
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
