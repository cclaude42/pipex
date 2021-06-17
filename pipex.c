/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 22:08:23 by cclaude           #+#    #+#             */
/*   Updated: 2021/06/17 13:48:25 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	openfile (char *filename)
{
	if (access(filename, F_OK))
	{
		write(STDERR, "pipex: ", 7);
		write(STDERR, filename, len(filename));
		write(STDERR, ": No such file or directory\n", 28);
		exit(1);
	}
	return (open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU));
}

char	**getArgs (char *cmd)
{

}

char	*getPath (char *cmd, char **env)
{
	int	i;

	i = 0;

}

void	exec (char *cmd, char **env)
{
	char	**args;
	char	*path;

	args = getArgs(cmd);
	if (strchr(args[0], '/'))
		path = args[0];
	else
		path = getPath(args[0], env);
	execve(path, args, env);
}

void	redir (char *cmd, char **env, int fdin, int fdout)
{
	pid_t	pid;
	int		pipefd[2];

	if (fdin)
		dup2(fdin, STDIN);
	if (fdout)
		dup2(fdout, STDOUT);
	if (!fdout)
	{
		pipe(pipefd);
		pid = fork();
		if (pid)
		{
			close(pipefd[1]);
			dup2(pipefd[0], STDIN);
			return ;
		}
		else
		{
			close(pipefd[0]);
			dup2(pipefd[1], STDOUT);
		}
	}
	exec(cmd);
}

int	main (int ac, char **av, char **env)
{
	int	fdin;
	int	fdout;

	if (ac == 5)
	{
		fdin = openfile(av[1]);
		fdout = openfile(av[4]);
		redir(av[2], env, fdin, 0);
		redir(av[3], env, 0, fdout);
	}
	else
		return (1);
	return (0);
}
