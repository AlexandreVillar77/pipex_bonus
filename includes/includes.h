/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:18:33 by avillar           #+#    #+#             */
/*   Updated: 2022/05/31 09:33:01 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <ft_printf.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_arg{
	char	**path;
	char	***cmd_arg;
	char	**envp;
	char	**argv;
	int		size;
}				t_arg;

typedef struct s_split{
	int		i;
	int		j;
	int		len;
	int		mode;
}				t_split;

//fichier ft_split.c
int		countcase(char const *s, char c);
int		sizel(char const *s, int i, char c);
void	fill_tab(char const *s, char c, t_split *split, char *dst);
int		skipc(const char *s, char c, int i);
char	**ft_split(char const *s, char c, int mode);

//fichier ft_strjoin.c
void	init_split(t_split *split, const char *s, char c, int mode);
size_t	ft_strlcat(char *restrict dst,
			const char *restrict src, size_t dstsize);
size_t	ft_strlcpy(char *restrict dst,
			const char *restrict src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);

//fichier utils1.c
int		ft_strcmp(char *s1, char *s2);
int		ft_search(char *str);
char	*ft_substr(char **envp);
t_arg	init_arg(t_arg *arg, char **envp, char **argv);
void	free_arg(t_arg *arg);

//fichier utils2.c
int		check_path_access(t_arg *data);
int		check_fds(char**argv, int n);
void	ft_cmdnotf(char *str, char *name);

//fichier utils3.c
int count_p(char **str);

#endif