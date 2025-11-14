/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obakri <obakri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 19:55:21 by obakri            #+#    #+#             */
/*   Updated: 2025/11/13 20:12:07 by obakri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_checknewline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}

char	*ft_leftc(char *line)
{
	int		n;
	char	*left;

	n = ft_checknewline(line);
	if (n == -1)
		return (NULL);
	left = ft_substr(line, n, ft_strlen(line) - n);
	if (!left || !left[0])
		return (NULL);
	ft_bzero(line + n, ft_strlen(line) - n);
	return (left);
}

char	*ft_returned_ligne(char *buffer, char *left, int fd)
{
	ssize_t	r;
	char	*line;

	while (ft_checknewline(buffer) < 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == -1)
		{
			free(left);
			return (NULL);
		}
		if (r == 0)
			break ;
		if (!left)
			left = ft_strdup("");
		line = left;
		left = ft_strjoin(line, buffer);
		free(line);
		line = NULL;
	}
	return (left);
}

char	*get_next_line(int fd)
{
	static char	*left[MAX_FD];
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + sizeof(char)) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = ft_returned_ligne(buffer, left[fd], fd);
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
	left[fd] = ft_leftc(line);
	free(buffer);
	return (line);
}
