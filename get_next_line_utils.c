/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:45:25 by                   #+#    #+#             */
/*   Updated: 2021/10/26 20:35:56 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strcp(char *dest, char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		dest[count] = str[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}

char	*ft_strdup(char *str)
{
	int		count;
	char	*dest;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	dest = malloc (count + 1);
	if (dest == NULL)
		return (dest);
	dest = ft_strcp(dest, str);
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	len;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(sizeof(char) * len + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[len] = '\0';
	while (s1[++i])
		ptr[i] = s1[i];
	while (s2[++j])
	{
		ptr[i] = s2[j];
		i++;
	}
	free(s1);
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*str;
	unsigned char	ch;

	str = (unsigned char *) s;
	ch = (unsigned char) c;
	if (c == 0)
		return ((char *)&str[ft_strlen(s)]);
	while (*str)
	{
		if (*str == ch)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}
