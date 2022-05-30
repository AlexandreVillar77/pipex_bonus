/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 16:57:58 by avillar           #+#    #+#             */
/*   Updated: 2021/09/20 10:46:35 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_nblen(unsigned long int nb, int basel)
{
	if (nb < (unsigned long int)basel)
		return (1);
	return (1 + (ft_nblen(nb / basel, basel)));
}

int	ft_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[j])
	{
		if (base[j] == '-' || base[j] == '+' || base[j] == ' '
			|| base[j] <= 32 || base[j] > 126)
			return (0);
		i = j + 1;
		while (base[i])
		{
			if (base[i] == base[j])
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	basevalue(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i] != c)
	{
		i++;
	}
	return (i);
}

void	ft_putnbr_base(unsigned long int nb, char *base, char *dest)
{
	int			i;

	i = 0;
	if (nb == 0)
	{
		dest[i] = base[0];
		i++;
	}
	while (nb > 0)
	{
		dest[i] = base[nb % ft_strlen(base)];
		nb /= ft_strlen(base);
		i++;
	}
	dest[i] = '\0';
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	int		size;
	char	*newnb;
	int		sign;

	if (ft_base(base_from) == 0 || ft_base(base_to) == 0)
		return (0);
	nb = ft_atoi_base(nbr, base_from);
	size = ft_nblen(nb, ft_strlen(base_to));
	sign = 0;
	if (nb < 0)
		sign = 1;
	newnb = malloc(sizeof(char) * size + 1 + sign);
	if (!newnb)
		return (0);
	ft_putnbr_base(nb, base_to, newnb);
	ft_revtab(newnb);
	return (newnb);
}
