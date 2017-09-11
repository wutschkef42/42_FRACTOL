/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erucquoy <erucquoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 20:07:33 by erucquoy          #+#    #+#             */
/*   Updated: 2017/05/12 09:46:19 by erucquoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


/*
** Fetch a minimal concatenation of buffers containing a \n
** from file descriptor fd into s[fd]
*/
static int	proceed(int const fd, char *buff, char *s[fd])
{
	char	*tmp;
	char	*p;
	int		i;

	// while s[fd] does not contain \n and stream is non-empty
	// append buffers from fd to s[fd]
	i = 0;
	while (!(p = ft_strchr(s[fd], '\n')) &&
		(i = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[i] = '\0';
		tmp = s[fd];
		s[fd] = ft_strjoin(tmp, buff);
		ft_strdel(&tmp);
	}
	// failure on read()
	if (i == -1)
		return (-1);
	// stream is empty
	if (i == 0 && !p)
		return (0);
	return (1);
}



/*
** Fetch a \n delimited line of characters from
** file descriptor fd
*/
int			get_next_line(int const fd, char **line)
{
	static char	*s[OPEN_MAX];
	char		*tmp;
	int			i;
	char		buff[BUFF_SIZE + 1];

	// check validity of file descriptor and memory address of line
	if (fd < 0 || !line)
		return (-1);
	// initialize s[fd] (buffer in which next line from file descriptor fd is assembled)
	if (!s[fd])
		s[fd] = ft_strnew(1);
	// call proceed() to concatenate sufficient buffers into s[fd], the last buffer containing the \n
	if ((i = proceed(fd, buff, &*s)) == -1)
		return (-1);
	// file descriptor is empty 
	if (i == 0)
	{
		*line = s[fd];
		s[fd] = NULL;
		// characters exist after the last \n
		if (*line[0])
			return (1);
		return (0);
	}
	// cut the next line from concatenation of buffers (which is handled by proceed)
	*line = ft_strsub(s[fd], 0, ft_strchr(s[fd], '\n') - s[fd]);
	// copy pointer before overwriting it
	tmp = s[fd];
	// delete next line from s[fd]
	s[fd] = ft_strdup(ft_strchr(s[fd], '\n') + 1);
	ft_strdel(&tmp);
	return (1);
}
