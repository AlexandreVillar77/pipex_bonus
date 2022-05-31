/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:33:23 by avillar           #+#    #+#             */
/*   Updated: 2022/05/31 09:36:21 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (i == 4)
		return (1);
	return (0);
}

int	ft_search(char *str)
{
	int		i;
	char	*s;

	s = "PATH";
	i = 0;
	while (str[i])
	{
		if (str[0] == 'P')
			if (ft_strcmp(str + i, s) == 1)
				return (1);
		i++;
	}
	return (0);
}

char	*ft_substr(char **envp)
{
	int		i;
	int		res;

	i = 0;
	while (envp[i])
	{
		res = ft_search(envp[i]);
		if (res == 1)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

t_arg	init_arg(t_arg *arg, char **envp, char **argv)
{
	int	n;
	int	i;
	int	x;

	i = 2;
	x = 0;
	n = count_p(argv);
	arg->size = n;
	arg->cmd_arg = malloc(sizeof(arg->cmd_arg) * (n + 1));
	if (!(arg->cmd_arg))
		return (*arg);
	while (n > 0)
	{
		arg->cmd_arg[x] = ft_split(argv[i], ' ', 0);
		n--;
		i++;
		x++;
	}
	arg->path = ft_split(ft_substr(envp), ':', 1);
	arg->envp = envp;
	arg->argv = argv;
	return (*arg);
}

void	free_arg(t_arg *arg)
{
	int	i;
	int	x;

	x = 0;
	i = -1;
	while (x < arg->size && arg->cmd_arg[x])
	{
		i = -1;
			while (arg->cmd_arg[x][++i])
				free(arg->cmd_arg[x][i]);
			free(arg->cmd_arg[x]);
		x++;
	}
	free(arg->cmd_arg);
	i = -1;
	if (arg->path)
	{
		while (arg->path[++i])
			free(arg->path[i]);
		free(arg->path);
	}
}
