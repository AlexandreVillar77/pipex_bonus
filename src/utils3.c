/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:32:13 by avillar           #+#    #+#             */
/*   Updated: 2022/05/31 16:14:47 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	ft_closing(int *fd, int i)
{
	while (i > 0)
	{
		close(fd[i - 1]);
		i--;
	}
}

int	count_p(char **str)
{
	int	i;
	int	n;

	i = 0;
	n = -3;
	while (str[i])
	{
		i++;
	}
	return (n + i);
}
