/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:44:23 by                   #+#    #+#             */
/*   Updated: 2021/10/26 21:29:25 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_read_and_save(int fd, char *save)
{
	int		bts;
	char	*buf;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bts = 1;
	while (bts)
	{
		bts = read(fd, buf, BUFFER_SIZE);
		if (bts == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[bts] = '\0';
		if (!save)
			save = ft_strdup("");
		save = ft_strjoin(save, buf);
		if (ft_strchr(save, '\n'))
			break ;
	}
	free(buf);
	return (save);
}

char	*ft_new_line(char *save)
{
	int		count;
	char	*res;

	count = 0;
	if (!save[count])
		return (NULL);
	while (save[count] && save[count] != '\n')
		count++;
	res = malloc(sizeof(char) * count + 2);
	if (!res)
		return (NULL);
	count = 0;
	while (save[count] && save[count] != '\n')
	{
		res[count] = save[count];
		count++;
	}
	if (save[count] == '\n')
	{
		res[count] = save[count];
		count++;
	}
	res[count] = '\0';
	return (res);
}

char	*ft_new_save(char *save)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	res = malloc(sizeof(char) * ft_strlen(save) - i + 1);
	if (!res)
		return (NULL);
	i += 1;
	while (save[i])
		res[j++] = save[i++];
	res[j] = '\0';
	free(save);
	return (res);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_read_and_save(fd, save);
	if (!save)
		return (NULL);
	res = ft_new_line(save);
	save = ft_new_save(save);
	return (res);
}
