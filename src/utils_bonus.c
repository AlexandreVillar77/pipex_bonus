/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:16:40 by avillar           #+#    #+#             */
/*   Updated: 2022/05/31 16:41:26 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_bonus.h"

void	init_pipe(t_arg *data, int numpipe)
{
	int	i;

	i = -1;
	data->end = malloc(sizeof(int) * (numpipe * 2));
	if (!data->end)
		return ;
	while (++i < numpipe)
	{
		if (pipe(data->end + i * 2) < 0)
		{
			perror ("couldn't pipe");
			exit (EXIT_FAILURE);
		}
	}
}

void	child_manager(t_arg *data, int j, int *fd, int n)
{
	if (j == 0)
	{
		childpro1_bonus(fd, data, data->end, 0);
		exit(EXIT_SUCCESS);
	}
	else if (data->cmd_arg[n + 1])
	{
		childpro_bonus(data, j, fd, n);
		exit(EXIT_SUCCESS);
	}
	else
	{
		childpro2_bonus(fd, data, n, j);
		exit(EXIT_SUCCESS);
	}
}

void	childpro_bonus(t_arg *data, int j, int *fd, int n)
{
	int		i;
	char	*cmd;

	i = 0;
	if ((dup2(data->end[j + 1], 1) < 0) || (dup2(data->end[j - 2], 0) < 0))
		return (perror("Dup2: "));
	ft_closing(fd, 2);
	ft_closing(data->end, data->size * 2);
	if (access(data->cmd_arg[n][0], X_OK) == 0)
		execve(data->cmd_arg[n][0], data->cmd_arg[n], data->envp);
	else
	{
		while (data->path[++i] && data->path != NULL)
		{
			cmd = ft_strjoin(data->path[i], data->cmd_arg[n][0]);
			if (!cmd)
				break ;
			if (access(cmd, X_OK) == 0)
				execve(cmd, data->cmd_arg[n], data->envp);
			free(cmd);
		}
	}
	ft_cmdnotf("command not found: ", data->cmd_arg[n][0]);
	free_arg(data);
	exit (EXIT_FAILURE);
}
