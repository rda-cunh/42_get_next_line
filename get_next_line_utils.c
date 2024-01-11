/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:06:00 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/01/11 18:46:53 by codespace        ###   ########.fr       */
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

static void	ft_bzero(void *b, size_t len)
{
	ft_memset(b, 0, len);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = malloc(nmemb * size);
	if (p == 0)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}