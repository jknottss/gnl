/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:49:19 by                   #+#    #+#             */
/*   Updated: 2021/10/27 17:49:19 by                  ###   ########.fr       */
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
	static char	*save[10240];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save[fd] = ft_read_and_save(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	res = ft_new_line(save[fd]);
	save[fd] = ft_new_save(save[fd]);
	return (res);
}
