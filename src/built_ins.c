/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:53:17 by pgonzal2          #+#    #+#             */
/*   Updated: 2024/05/24 18:29:57 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_echo(t_cmd *cmd)
{
	int	i;
	int	n_flag;

	i = 1;
	n_flag = 0;
	while (cmd->argv[i] && (!ft_strncmp(cmd->argv[i], "-n", 3)))
	{
		n_flag = 1;
		i++;
	}
	while(cmd->argv[i])
	{
		ft_putstr_fd(cmd->argv[i], 1);
		if(i < cmd->len_argv - 1)
			write(1, " ", 1);
		i++;
	}
	if(!n_flag)
		write(1, "\n", 1);
}

void	ft_pwd()
{
	char *cwd;

	cwd = getcwd(NULL, 0);
	if(!cwd)
		perror("error");
	printf("%s\n", cwd);
	free(cwd);
}

void	ft_cd(t_cmd *cmd)
{
	if (chdir(cmd->argv[1]) < 0)
		perror("error");
}

void	ft_env(t_cmd *cmd)
{
	(void)cmd;
	printf("%s\n", getenv("PATH"));
}

static void	ft_swap(char **a, char **b)
{
	char *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void printenv(t_env *env)
{
	while(env)
	{
		printf("NAME: %s\n",env->name);
		printf("CONTENT: %s\n",env->content);
		printf("------------------------------\n");
		env = env->next;
	}
}	

void	ft_export(t_msh *msh)
{
	t_env	*one;
	t_env	*other;
	
	one = msh->env;
	while (one && one->next)
	{
		other = msh->env;
		while(other->next)
		{
			if(ft_strncmp(other->name, other->next->name, ft_strlen(other->name)) > 0)
			{
				ft_swap(&other->name, &other->next->name);
				ft_swap(&other->content, &other->next->content);
			}
			other = other->next;
		}
		one = one->next;
	}
	printenv(msh->env);
}