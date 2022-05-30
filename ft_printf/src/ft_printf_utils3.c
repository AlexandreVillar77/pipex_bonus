/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 16:39:17 by avillar           #+#    #+#             */
/*   Updated: 2021/09/29 11:37:51 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putunbr(unsigned int n)
{
	if (n > 9)
	{
		ft_putunbr(n / 10);
		ft_putchar_pf(n % 10 + 48);
	}
	else
	{
		ft_putchar_pf(n + 48);
	}	
}

int	ft_putvoid(unsigned long int nb)
{
	char	*n;
	int		rtn;

	n = malloc(sizeof(char) * ft_nblen(nb, 16) + 1);
	if (!n)
		return (0);
	ft_putstr_pf("0x");
	ft_putnbr_base(nb, "0123456789abcdef", n);
	ft_revtab(n);
	rtn = ft_strlen(n) + 2;
	ft_putstr_pf(n);
	free(n);
	return (rtn);
}

int	ft_print_minhexa(unsigned long nb)
{
	char	*n;
	int		rtn;

	n = malloc(sizeof(char) * ft_nblen(nb, 16) + 1);
	if (!n)
		return (0);
	ft_putnbr_base(nb, "0123456789abcdef", n);
	ft_revtab(n);
	rtn = ft_strlen(n);
	ft_putstr_pf(n);
	free(n);
	return (rtn);
}
