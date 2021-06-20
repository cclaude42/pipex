/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 23:03:54 by cclaude           #+#    #+#             */
/*   Updated: 2021/06/20 20:46:00 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef ARGMAX
#  define ARGMAX 5
# endif

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define INFILE 0
# define OUTFILE 1

# define CREATE_TRUNC O_CREAT | O_WRONLY | O_TRUNC
# define CREATE_APPEND O_CREAT | O_WRONLY | O_APPEND
# define DEFAULT_MODE S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

char	*path_join (char *path, char *bin);
int		str_ncmp (char *str1, char *str2, int n);
int		str_ichr (char *str, char c);
char	*str_ndup (char *str, unsigned int n);
char	**str_split (char *str, char sep);

#endif
