/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_basic_utils.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:13:44 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/02/20 23:37:57 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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