/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_process_dist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 07:53:23 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/09 08:09:06 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	rt_process_dist(double delta, t_cart *n)
{
	t_vec2	t;

	delta = sqrt(delta);
	n->a *= 2.0;
	n->b = -(n->b);
	t.x = (n->b - delta) / n->a;
	t.y = (n->b + delta) / n->a;
	if (t.x < 0.0 && t.y < 0.0)
		return (0.0);
	if (t.x < 0.0)
		return (t.y);
	else if (t.y < 0.0)
		return (t.x);
	return (t.x < t.y ? t.x : t.y);
}
