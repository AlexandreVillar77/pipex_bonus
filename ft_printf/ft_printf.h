/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 12:42:19 by avillar           #+#    #+#             */
/*   Updated: 2021/09/29 11:58:08 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_list{
	int			printedchar;
	va_list		tab;
	int			error;
}				t_list;

int		ft_secure_troll(const char *str);
int		checkarg(const char *str);
int		ft_intsize(long int n, int c);
void	init_list(t_list *list);
int		ft_strlen(char *str);
int		ft_countarg(const char *str);
int		ft_putchar_pf(char c);
void	ft_putnbr(long int n);
int		ft_putstr_pf(char *str);
int		ft_printf(const char *s, ...);
int		ft_read(va_list list, const char *str);
int		ft_print(va_list list, char *str);
int		ft_flag(va_list list, char *str);
void	ft_putunbr(unsigned int n);
int		ft_Unbflag(unsigned int n);
int		ft_nblen(unsigned long int nb, int basel);
int		ft_base(char *base);
int		basevalue(char *base, char c);
int		inbase(char *base, char c);
int		ft_atoi_base(char *str, char *base);
void	ft_revtab(char *str);
void	ft_putnbr_base(unsigned long int nb, char *base, char *dest);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		ft_putvoid(unsigned long int nb);
int		ft_print_hexa(unsigned long nb);
int		ft_print_minhexa(unsigned long nb);

#endif