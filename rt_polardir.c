/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_polardir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 04:45:25 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/22 05:06:09 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_polardir	rt_polardir(float phi, float theta)
{
	t_polardir	polardir;

	polardir.phi = phi;
	polardir.theta = theta;
	return (polardir);
}
