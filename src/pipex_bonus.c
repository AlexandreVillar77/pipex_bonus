/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:06:39 by avillar           #+#    #+#             */
/*   Updated: 2022/05/31 17:13:32 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_bonus.h"

void	childpro1_bonus(int *fd, t_arg *data, int *end, int n)
{
	int		i;
	char	*cmd;

	i = -1;
	if (dup2(fd[0], STDIN_FILENO) < 0 || dup2(end[1], STDOUT_FILENO) < 0)
		return (perror("Dup2: "));
	ft_closing(end, data->size * 2);
	ft_closing(fd, 2);
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
	exit(EXIT_FAILURE);
}

void	childpro2_bonus(int *fd, t_arg *data, int n, int j)
{
	int		i;
	char	*cmd;

	i = -1;
	if (dup2(fd[1], STDOUT_FILENO) < 0 || dup2(data->end[j - 2], 0) < 0)
		return (perror("Dup2: "));
	ft_closing(data->end, data->size * 2);
	ft_closing(fd, 2);
	if (access(data->cmd_arg[n][0], X_OK) == 0)
		execve(data->cmd_arg[n][0], data->cmd_arg[n], data->envp);
	else
	{
		while (data->path[++i])
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
	exit(EXIT_FAILURE);
}

void	pipex_bonus(int *fd, t_arg *data, int numpipe)
{
	int		status;
	pid_t	pid;
	int		j;
	int		n;

	j = 0;
	n = 0;
	init_pipe(data, numpipe);
	while (data->cmd_arg[n])
	{
		pid = fork();
		if (pid == 0)
			child_manager(data, j, fd, n);
		else if (pid < 0)
		{
			perror("error");
			exit(EXIT_FAILURE);
		}
		n++;
		j += 2;
	}
	ft_closing(data->end, data->size * 2);
	j = -1;
	while (++j < data->size + 1)
		wait(&status);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	t_arg	data;

	if (argc < 5 || !envp)
	{
		ft_printf("Error, wrong number of argumet\n");
		ft_printf("or cannot reach environnemnt variable PATH.\n");
		return (1);
	}
	fd[0] = check_fds(argv, 1, argc);
	fd[1] = check_fds(argv, 2, argc);
	if ((fd[0] < 0 && fd[1] < 0) || fd[1] < 0)
	{
		ft_closing(fd, 2);
		return (1);
	}
	data = init_arg(&data, envp, argv);
	if (data.cmd_arg && check_path_access(&data) == 0)
		pipex_bonus(fd, &data, count_p(argv));
	ft_closing(fd, 2);
	free_arg(&data);
	free(data.end);
	return (0);
}
