#include "libft.h"
#include <stdio.h>
#include <string.h>

//int	ft_strstr(const char *s1, const char *s2)
//{
//	const char *p;
//	size_t len;
//
//	p = s1;
//	len = strlen(s2);
//	for(; (p = strchr (p, *s2)) != 0; p++)
//	{
//		if (strncmp(p, s2, len) == 0)
//			return (1);
//	}
//	return (0);
//}

int	ft_strstr(const char *s1, const char *s2)
{
	const char *p;
	size_t len;

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
