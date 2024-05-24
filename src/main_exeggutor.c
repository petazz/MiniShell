#include "minishell.h"

void    init_stack(t_cmd *cmd, t_msh *mock_msh, char **envp)
{
    char **mock_args = malloc(sizeof(char*) * 10);
    mock_args[0] = "cd";
    mock_args[1] = "../../Desktop";
    // mock_args[2] = "-n";
    // mock_args[2] = "caca";
    // mock_args[3] = "-n";
    // mock_args[4] = "hola";
    // mock_args[5] = "AAAA";
    ///////////////T_CMD///////////////
        cmd->path = "ls";
        cmd->argv = mock_args;
        cmd->len_argv = 1;
    ///////////////T_MSH///////////////
        mock_msh->cmd = &cmd;
        mock_msh->len_cmds = 1,
        mock_msh->envp = envp;
        mock_msh->fdin = -1;
        mock_msh->fdout = -1;
}

int main(int argc, char **argv, char **envp)
{
    (void)argc;
    (void)argv;
    t_cmd cmd;
    t_msh mock_msh;
    init_stack(&cmd, &mock_msh, envp);
    organization_env(envp,&mock_msh);

    //ft_echo(&cmd);
    // ft_pwd();
	// ft_cd(&cmd);
    // ft_pwd();
	//ft_env(&cmd);
    ft_export(&mock_msh);

    ///////////READLINE////////////
    // char *line = readline("minishell$ ");
    // while (line)
    // {
    //  add_history(line);
    //  free(line);
    //  line = readline("minishell$ ");
    // }
    return (0);
}