/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_polardir_to_vec3dir.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 04:48:13 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/08 02:24:11 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3	rt_polardir_to_vec3dir(t_polardir polardir)
{
	t_vec3	vec3;
	float	cos_theta;

	cos_theta = rt_dcos(polardir.theta);
	vec3.x = cos_theta * rt_dsin(polardir.phi);
	if (vec3.x < 0.0000001 && vec3.x > -0.0000001)
		vec3.x = 0.0;
	vec3.y = rt_dsin(polardir.theta);
	if (vec3.y < 0.0000001 && vec3.y > -0.0000001)
		vec3.y = 0.0;
	vec3.z = cos_theta * rt_dcos(polardir.phi);
	if (vec3.z < 0.0000001 && vec3.z > -0.0000001)
		vec3.z = 0.0;
	return (vec3);
}
