/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:22:15 by avillar           #+#    #+#             */
/*   Updated: 2022/05/30 17:29:34 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	ft_closing(int f1, int f2)
{
	if (f1 >= 0)
		close(f1);
	if (f2 >= 0)
		close(f2);
}

void	childpro1(int *fd, t_arg *data, int *end)
{
	int		i;
	char	*cmd;

	i = -1;
	if (dup2(fd[0], STDIN_FILENO) < 0 || dup2(end[1], STDOUT_FILENO) < 0)
		return (perror("Dup2: "));
	ft_closing(end[0], end[1]);
	ft_closing(fd[0], fd[1]);
	if (access(data->cmd1_arg[0], X_OK) == 0)
		execve(data->cmd1_arg[0], data->cmd1_arg, data->envp);
	else
	{
		while (data->path[++i] && data->path != NULL)
		{
			cmd = ft_strjoin(data->path[i], data->cmd1_arg[0]);
			if (!cmd)
				break ;
			if (access(cmd, X_OK) == 0)
				execve(cmd, data->cmd1_arg, data->envp);
			free(cmd);
		}
	}
	ft_cmdnotf("command not found: ", data->cmd1_arg[0]);
	free_arg(data);
	exit (EXIT_FAILURE);
}

//check leaks child 2

void	childpro2(int *fd, t_arg *data, int *end)
{
	int		i;
	char	*cmd;

	i = -1;
	if (dup2(fd[1], STDOUT_FILENO) < 0 || dup2(end[0], STDIN_FILENO) < 0)
		return (perror("Dup2: "));
	ft_closing(end[0], end[1]);
	ft_closing(fd[0], fd[1]);
	if (access(data->cmd2_arg[0], X_OK) == 0)
		execve(data->cmd2_arg[0], data->cmd2_arg, data->envp);
	else
	{
		while (data->path[++i])
		{
			cmd = ft_strjoin(data->path[i], data->cmd2_arg[0]);
			if (!cmd)
				break ;
			if (access(cmd, X_OK) == 0)
				execve(cmd, data->cmd2_arg, data->envp);
			free(cmd);
		}
	}
	ft_cmdnotf("command not found: ", data->cmd2_arg[0]);
	free_arg(data);
	exit (EXIT_FAILURE);
}

void	pipex(int *fd, t_arg *data)
{
	int		end[2];
	int		status;
	pid_t	child1;
	pid_t	child2;

	if (pipe(end) == -1)
		return (perror("Pipe: "));
	if (fd[0] > 0)
	{
		child1 = fork();
		if (child1 < 0)
			return (perror("Fork: "));
		if (child1 == 0)
			childpro1(fd, data, end);
	}
	child2 = fork();
	if (child2 < 0)
		return (perror("Fork: "));
	if (child2 == 0)
		childpro2(fd, data, end);
	close(end[0]);
	close(end[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
}

void	b_pipex(int *fd, t_arg *data, int nb)
{
	int		end[2];
	int		status;
	pid_t	child1;
	pid_t	child2;

	if (pipe(end) == -1)
	    return (perror("Pipe: "));
	if (fd[0] > 0)
	{
	    child1 = fork();
	    if (child1 < 0)
	    	return (perror("Fork: "));
	    if (child1 == 0)
	    	childpro1(fd, data, end);
	}
    while (nb-- > 0)
    {
	    child2 = fork();
	    if (child2 < 0)
	    	return (perror("Fork: "));
	    if (child2 == 0)
	    	childpro2(fd, data, end);
        data->
    }
	close(end[0]);
	close(end[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	t_arg	data;

	if (argc < 5 || argc > 5 || !envp)
	{
		ft_printf("Error, wrong number of argumet\n");
		ft_printf("or cannot reach environnemnt variable PATH.\n");
		return (1);
	}
	fd[0] = check_fds(argv, 1);
	fd[1] = check_fds(argv, 2);
	if ((fd[0] < 0 && fd[1] < 0) || fd[1] < 0)
	{
		ft_closing(fd[0], fd[1]);
		return (1);
	}
	data = init_arg(&data, envp, argv);
	if (check_path_access(&data) == 0)
		pipex(fd, &data);
	ft_closing(fd[0], fd[1]);
	free_arg(&data);
	return (0);
}
