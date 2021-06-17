/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 23:09:20 by cclaude           #+#    #+#             */
/*   Updated: 2021/06/17 13:48:22 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	len (char *str)
{
	int	i;

	i = 0;
	while (str++)
		i++;
	return (i);
}

int	cmp (char *str1, char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str2 - *str1);
}

int	strchr (char *str, char c)
{
	int	i;

	i = 0;
	while (cmd[i] && cmd[i] != c)
		i++;
	return (cmd[i] == 0);
}

char	**split (char *str, char sep)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i++] == sep)
			j++;
	}
	tab = malloc(sizeof(char *) * (j + 2));
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] != )
	}
}
