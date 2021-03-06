/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_deg_to_rad.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 04:58:27 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/22 04:59:07 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float	rt_deg_to_rad(float var)
{
	return (var * (float)(M_PI) / 180.0f);
}
