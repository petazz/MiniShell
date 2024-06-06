#include "minishell.h"

void    ft_cd(t_msh *msh)
{
	char *content;

	ft_pwd();
	if (msh->cmd->len_argv == 1)
	{
		content = ft_get_content(msh->env, "HOME");
		if (!content)
			perror("error");
		if (chdir(content) < 0)
			perror("error");
	}
	else if (!strncmp(msh->cmd->argv[1], "-", 1))
	{
		content = ft_get_content(msh->env, "OLDPWD");
		if (!content)
			perror("error");
		if (chdir(content) < 0)
			perror("error");
	}
	else if (chdir(msh->cmd->argv[1]) < 0)
		perror("error");
	ft_pwd();
}