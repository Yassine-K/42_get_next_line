/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:08:41 by ykhayri           #+#    #+#             */
/*   Updated: 2022/11/19 17:52:17 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	has_n(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_cutstr(char *s, int k)
{
	int	i;

	i = 0;
	if (k < 0)
	{
		free(s);
		return (0);
	}
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		s[i + 1] = '\0';
	return (s);
}

void	ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = -1;
	if (n < 0)
		n++;
	while (src[++i] && i < n)
		dest[i] = src[i];
	while (i < n || i < BUFFER_SIZE)
	{
		dest[i] = '\0';
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2, int k)
{
	char	*str;
	int		h;

	h = -1;
	k += ft_strlen(s1);
	str = (char *) malloc(k + 1);
	if (!str)
		return (0);
	k = -1;
	while (s1[++k])
		str[k] = s1[k];
	while (s2[++h])
		str[k + h] = s2[h];
	str[k + h] = '\0';
	if (s1[0])
		free((void *)s1);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	str[OPEN_MAX][BUFFER_SIZE + 1];
	char		*f;
	int			k;

	if (fd == 1 || fd == 2 || fd < 0 || B_S < 0)
		return (0);
	k = BUFFER_SIZE;
	if (!str[fd][0] && k > 0)
		k = read(fd, str[fd], BUFFER_SIZE);
	if (k <= 0)
		return (0);
	f = "";
	f = ft_strjoin(f, str[fd], k);
	while (has_n(str[fd]) < 0 && k > 0)
	{
		k = read(fd, str[fd], BUFFER_SIZE);
		if (k < BUFFER_SIZE)
			ft_strncpy(str[fd], str[fd], k);
		if (k > 0)
			f = ft_strjoin(f, str[fd], k);
	}
	f = ft_cutstr(f, k);
	ft_strncpy(str[fd], str[fd] + has_n(str[fd]) + 1, BUFFER_SIZE);
	return (f);
}
