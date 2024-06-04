#include "minishell.h"

void    ft_cd(t_cmd *cmd)
{
	// char *cwd;

	// cwd = 
    ft_pwd();
    // getcwd(NULL, 0);
	// if(!cwd)
	// 	perror("error");
	if (chdir(cmd->argv[1]) < 0)
		perror("erroooooor");
    ft_pwd();
}