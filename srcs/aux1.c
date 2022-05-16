/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:44:13 by tmatias           #+#    #+#             */
/*   Updated: 2021/07/24 15:48:09 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_distance(int *xyz1, int *xyz2)
{
	int	c;

	c = sqrt(pow((xyz1[0] - xyz2[0]), 2) + (pow((xyz1[1] - xyz2[1]), 2))
		+ (pow((xyz1[2] - xyz2[2]), 2)));
	return (c);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
