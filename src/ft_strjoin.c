/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:40:36 by avillar           #+#    #+#             */
/*   Updated: 2022/04/11 15:21:49 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	init_split(t_split *split, const char *s, char c, int mode)
{
	split->i = skipc(s, c, 0);
	split->j = 0;
	split->len = 0;
	split->mode = mode;
}

size_t	ft_strlcat(char *restrict dst,
			const char *restrict src, size_t dstsize)
{
	int		i;
	int		di;
	int		si;

	i = 0;
	si = ft_strlen((char *)src);
	di = ft_strlen(dst);
	if (dstsize > 0)
	{
		while (((char *)src)[i] && ((di + i) < ((int)dstsize - 1)))
		{
			dst[di + i] = ((char *)src)[i];
			i++;
		}
		dst[di + i] = '\0';
	}
	if ((int)dstsize >= di)
		return (si + di);
	return (dstsize + si);
}

size_t	ft_strlcpy(char *restrict dst,
			const char *restrict src, size_t dstsize)
{
	int		i;

	i = 0;
	if (!(src))
		return (0);
	if (dstsize > 0)
	{
		while (((char *)src)[i] && (i < ((int)dstsize - 1)))
		{
			dst[i] = ((char *)src)[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen((char *)src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*rtn;
	size_t		s1s;
	size_t		s2s;

	if (s1 == 0 || s2 == 0)
		return (0);
	s1s = ft_strlen((char *)s1);
	s2s = ft_strlen((char *)s2);
	rtn = malloc(sizeof(char) * s1s + s2s + 1);
	if (!rtn)
		return (0);
	ft_strlcpy(rtn, s1, s1s + 1);
	ft_strlcat(rtn, s2, s1s + s2s + 1);
	return (rtn);
}
