/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:13:35 by avillar           #+#    #+#             */
/*   Updated: 2021/09/08 12:35:11 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putchar_pf(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_pf(char *str)
{
	int		i;

	i = 0;
	if (!str)
	{
		i = 6;
		ft_putstr_pf("(null)");
	}
	else
	{
		write(1, str, ft_strlen(str));
	}
	return (i);
}

void	ft_putnbr(long int n)
{
	if (n < 0)
	{
		ft_putchar_pf('-');
		n = n * -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar_pf(n % 10 + 48);
	}
	else
	{
		ft_putchar_pf(n + 48);
	}	
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_print(va_list list, char *str)
{
	int	rtn;

	rtn = ft_flag(list, str);
	return (rtn);
}
