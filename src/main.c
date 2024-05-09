#include "minishell.h"

void    init_stack(t_cmd *mock_cmd, t_msh *mock_msh, char **envp)
{
    char **mock_args = malloc(sizeof(char*) * 10);
    mock_args[0] = "echo";
    mock_args[1] = "-n";
    mock_args[2] = "hola";
    mock_args[3] = 0;
    ///////////////T_CMD///////////////
        mock_cmd->path = "/bin/ls";
        mock_cmd->argv = mock_args;
        mock_cmd->len_argv = 2;
    ///////////////T_MSH///////////////
        mock_msh->cmd = &mock_cmd;
        mock_msh->len_cmds = 1,
        mock_msh->envp = envp;
        mock_msh->fdin = -1;
        mock_msh->fdout = -1;
}

int main(int argc, char **argv, char **envp)
{
    (void)argc;
    (void)argv;
    t_cmd mock_cmd;
    t_msh mock_msh;
    init_stack(&mock_cmd, &mock_msh, envp);

    //hay que añadir el gnl que se ha borrado y comentado en el makefile
    // y arreglar el include
    ft_echo(mock_cmd.argv);
	//ft_cd(mock_cmd.argv);

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