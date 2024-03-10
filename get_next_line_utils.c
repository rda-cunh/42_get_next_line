/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:06:00 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/03/10 00:50:12 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	altc;
	char	*alts;

	altc = c;
	alts = (char *)s;
	while (*alts != '\0')
	{
		if (*alts == altc)
			return (alts);
		alts++;
	}
	if (altc == 0)
		return (alts);
	return (NULL);
}

void	ft_bzero(void *b, size_t len)
{
	ft_memset(b, 0, len);
}

static void	*ft_memset(void *s, int c, size_t len)
{
	size_t			i;
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	i = 0;
	while (i < len)
	{
		tmp[i] = c;
		i++;
	}
	return (s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, s1_len);
	ft_memcpy(str + s1_len, s2, s2_len);
	str[s1_len + s2_len] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*dtemp;
	unsigned char	*stemp;

	dtemp = (unsigned char *)dst;
	stemp = (unsigned char *)src;
	if (!dtemp && !stemp)
		return (dst);
	while (len > 0)
	{
		*dtemp = *stemp;
		dtemp++;
		stemp++;
		len--;
	}
	return (dst);
}
