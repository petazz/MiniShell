#include "minishell.h"

static void	init_struck(t_msh *msh)
{
	msh->cmd = NULL;
	msh->fdin = -1;
	msh->fdout = -1;
}

int	main(int argc, char **argv, char **envp)
{
	t_msh	msh;

	(void)argc;
	(void)argv;
	init_struck(&msh);
	organization_env(envp, &msh.env);
	organization_env(envp, &msh.export);
	msh.prompt = readline("prueba mi conchita$ ");
	while (msh.prompt)
	{
		if (!ft_strlen(msh.prompt))
		{
			msh.prompt = readline("prueba mi conchita$ ");
			continue ;
		}
		add_history(msh.prompt);

		if (check_lexer(&msh) == 1)
		{
			struct_cmd(&msh);
		}
		msh.len_cmds = 1;
		msh.envp = envp;
		printf("acaba parser. argc: %s\n", msh.cmd->argv[0]);
		ft_exeggutor(&msh);
		free(msh.prompt);
		msh.prompt = readline("prueba mi conchita$ ");
	}
	return (0);
}
