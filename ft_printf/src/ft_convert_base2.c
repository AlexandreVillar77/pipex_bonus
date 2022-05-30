/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:03:16 by avillar           #+#    #+#             */
/*   Updated: 2021/09/06 11:53:32 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	inbase(char *base, char c)
{
	int	i;
	int	ok;

	ok = 1;
	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			ok--;
		i++;
	}
	return (ok);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	res;

	res = 0;
	sign = 1;
	if (ft_base(base) == 0)
		return (0);
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (inbase(base, *str) == 0)
	{
		res = res * ft_strlen(base) + basevalue(base, *str);
		str++;
	}
	return (res * sign);
}

void	ft_revtab(char *str)
{
	int		i;
	char	swp;
	int		x;

	x = ft_strlen(str) - 1;
	if (str[0] == '-')
		i = 1;
	else
		i = 0;
	while (i < x)
	{
		swp = str[i];
		str[i] = str[x];
		str[x] = swp;
		x--;
		i++;
	}
}
