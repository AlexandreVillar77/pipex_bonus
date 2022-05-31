/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:03:48 by avillar           #+#    #+#             */
/*   Updated: 2022/05/31 16:12:34 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_BONUS_H
# define INCLUDES_BONUS_H

# include <fcntl.h>
# include "includes.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <ft_printf.h>
# include <sys/types.h>
# include <sys/wait.h>

//fichier utils_bonus.c
void	init_pipe(t_arg *data, int numpipe);
void	child_manager(t_arg *data, int j, int *fd, int n);
void	childpro_bonus(t_arg *data, int j, int *fd, int n);

//fichier pipex_bonus.c
void	childpro1_bonus(int *fd, t_arg *data, int *end, int n);
void	childpro2_bonus(int *fd, t_arg *data, int n, int j);

#endif