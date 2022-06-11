/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:30:06 by tmatias           #+#    #+#             */
/*   Updated: 2022/06/11 17:30:18 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	ft_strstr(const char *s1, const char *s2)
{
	const char	*p;
	size_t		len;

	p = s1;
	len = strlen(s2);
	while (*p != '\0')
	{
		if (strncmp(p, s2, len) == 0)
			return (1);
		p++;
	}
	return (0);
}
