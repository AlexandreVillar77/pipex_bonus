/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 12:41:43 by avillar           #+#    #+#             */
/*   Updated: 2021/09/29 12:08:23 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_secure_troll(const char *str)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	while (str[x] == '%')
	{
		x--;
		i++;
	}
	if (i % 2 == 1)
		return (1);
	return (0);
}

int	checkarg(const char *str)
{
	if (str[1] == 'c')
		return (1);
	if (str[1] == 's')
		return (1);
	if (str[1] == 'p')
		return (1);
	if (str[1] == 'd' || str[1] == 'i')
		return (1);
	if (str[1] == 'u')
		return (1);
	if (str[1] == 'x')
		return (1);
	if (str[1] == 'X')
		return (1);
	return (0);
}

int	ft_countarg(const char *str)
{
	int		i;
	int		s;
	int		c;

	i = 0;
	s = 0;
	while (str[s])
	{
		if (str[s] == '%' && checkarg(str + s) == 1
			&& ft_secure_troll(str + s) == 1)
			i++;
		s++;
	}
	s = 0;
	c = 0;
	while (str[s])
	{
		if (str[s] == '%' && str[s + 1] == '%')
		{
			c++;
			s++;
		}
		s++;
	}
	return ((i * 2) + c);
}

int	ft_read(va_list list, const char *str)
{
	int		read;
	int		count;

	count = 0;
	read = 0;
	while (str[read])
	{
		if (str[read] == '%')
		{
			if (str[read] == '%')
			{
				count += ft_print(list, (char *)(str + read));
				read += 2;
			}
		}
		if (str[read] != '%' && str[read])
		{
			ft_putchar_pf(str[read]);
			read++;
		}
	}
	count += ft_strlen((char *)str) - ((ft_countarg(str)));
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		rtn;
	t_list	list;	

	init_list(&list);
	va_start(list.tab, s);
	rtn = ft_read(list.tab, s);
	va_end(list.tab);
	return (rtn);
}
