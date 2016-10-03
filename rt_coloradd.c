/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_coloradd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 00:01:41 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/08 02:16:11 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_uint	rt_coloradd(t_uint color1, t_uint color2)
{
	t_uint	alpha;
	t_uint	red;
	t_uint	green;
	t_uint	blue;

	alpha = ((color1 & 0xFF000000) >> 24) + ((color2 & 0xFF000000) >> 24);
	if (alpha > 255)
		alpha = 255;
	red = ((color1 & 0x00FF0000) >> 16) + ((color2 & 0x00FF0000) >> 16);
	if (red > 255)
		red = 255;
	green = ((color1 & 0x0000FF00) >> 8) + ((color2 & 0x0000FF00) >> 8);
	if (green > 255)
		green = 255;
	blue = (color1 & 0x000000FF) + (color2 & 0x000000FF);
	if (blue > 255)
		blue = 255;
	return ((alpha << 24) | (red << 16) | (green << 8) | blue);
}
