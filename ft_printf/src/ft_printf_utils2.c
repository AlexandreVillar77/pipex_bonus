/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 15:10:08 by avillar           #+#    #+#             */
/*   Updated: 2021/09/29 11:38:09 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_intsize(long int n, int c)
{
	if (n < 0)
		return (ft_intsize(n * -1, c += 1));
	else if (n > 9)
		return (ft_intsize(n / 10, c += 1));
	else
		return (c);
}

int	ft_nbflag(int nb)
{
	ft_putnbr(nb);
	return (ft_intsize(nb, 1));
}

int	ft_unbflag(unsigned int n)
{
	ft_putunbr(n);
	return (ft_intsize(n, 1));
}

int	ft_print_hexa(unsigned long nb)
{
	char	*n;
	int		rtn;

	n = malloc(sizeof(char) * ft_nblen(nb, 16) + 1);
	if (!n)
		return (0);
	ft_putnbr_base(nb, "0123456789ABCDEF", n);
	ft_revtab(n);
	rtn = ft_strlen(n);
	ft_putstr_pf(n);
	free(n);
	return (rtn);
}

int	ft_flag(va_list list, char *str)
{
	if (str[1] == 'c')
		return (ft_putchar_pf(va_arg(list, int)));
	if (str[1] == 's')
		return (ft_putstr_pf(va_arg(list, char *)));
	if (str[1] == 'p')
		return (ft_putvoid((unsigned long int)(va_arg(list, void *))));
	if (str[1] == 'd' || str[1] == 'i')
		return (ft_nbflag(va_arg(list, int)));
	if (str[1] == 'u')
		return (ft_unbflag(va_arg(list, unsigned int)));
	if (str[1] == 'x')
		return (ft_print_minhexa((unsigned long)va_arg(list, unsigned int)));
	if (str[1] == 'X')
		return (ft_print_hexa((unsigned long)va_arg(list, unsigned int)));
	if (str[1] == '%')
		ft_putchar_pf(str[1]);
	return (0);
}
