/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:29:55 by tmatias           #+#    #+#             */
/*   Updated: 2022/06/11 17:30:20 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strisdigit(char *c)
{
	int	i;

	i = 0;
	if (c[i] == '-' || c[i] == 0)
		++i;
	while (c[i])
	{
		if (!ft_isdigit(c[i]))
			return (0);
		++i;
	}
	return (1);
}
