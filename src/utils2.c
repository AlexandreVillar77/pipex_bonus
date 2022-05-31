/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:17:20 by avillar           #+#    #+#             */
/*   Updated: 2022/05/31 16:23:34 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	ft_cmdnotf(char *str, char *name)
{
	write(STDERR_FILENO, str, ft_strlen(str));
	write(STDERR_FILENO, name, ft_strlen(name));
	write(STDERR_FILENO, "\n", 1);
}

int	check_path_access(t_arg *data)
{
	if (data->path == NULL && ((access(data->cmd_arg[0][0], X_OK) == -1)
		&& (access(data->cmd_arg[1][0], X_OK) == -1)))
	{
		perror(data->cmd_arg[0][0]);
		perror(data->cmd_arg[1][0]);
		return (1);
	}
	if (data->path == NULL && (access(data->cmd_arg[0][0], X_OK) == -1))
	{
		perror(data->cmd_arg[0][0]);
		return (1);
	}
	if (data->path == NULL && (access(data->cmd_arg[1][0], X_OK) == -1))
	{
		perror(data->cmd_arg[1][0]);
		return (1);
	}
	return (0);
}

int	check_fds(char **argv, int n, int argc)
{
	int	fd;

	fd = 0;
	if (n == 1)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			perror(argv[1]);
			return (-1);
		}
	}
	else if (n == 2)
	{
		fd = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (fd < 0)
		{
			perror(argv[argc -1]);
			return (-1);
		}
	}
	return (fd);
}
