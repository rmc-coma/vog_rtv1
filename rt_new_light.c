/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_new_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 06:53:53 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/22 06:54:57 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_light	*rt_new_light(t_vec3 pos, t_uint color, float intensity)
{
	t_light	*new;

	new = (t_light *)malloc(sizeof(t_light));
	new->pos = pos;
	new->color = color;
	new->intensity = intensity;
	return (new);
}
