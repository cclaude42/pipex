/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 22:08:23 by cclaude           #+#    #+#             */
/*   Updated: 2021/06/15 23:22:04 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int openfile (char *filename)
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

void exec (char *cmd)
{
	
	execve(cmd, NULL, NULL);
}

void redir (char *cmd, int fdin, int fdout)
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


int main (int ac, char **av)
{
	int	fdin;
	int	fdout;

	if (ac == 5)
	{
		fdin = openfile(av[1]);
		fdout = openfile(av[4]);
		redir(av[2], fdin, 0);
		redir(av[3], 0, fdout);
	}
	else
		return (1);
	return (0);
}
