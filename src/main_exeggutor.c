#include "minishell.h"

void    init_stack(t_cmd *cmd, t_msh *mock_msh, char **envp)
{
    char **mock_args = malloc(sizeof(char*) * 10);
    mock_args[0] = "cd";
    mock_args[1] = "-";
    //mock_args[2] = "z2=";
    // mock_args[2] = "caca";
    // mock_args[3] = "-n";
    // mock_args[4] = "hola";
    // mock_args[5] = "AAAA";
    ///////////////T_CMD///////////////
        cmd->argv = mock_args;
        cmd->len_argv = 1;
    ///////////////T_MSH///////////////
        mock_msh->cmd = cmd;
        mock_msh->len_cmds = 1;
        mock_msh->envp = envp;
        mock_msh->fdin = -1;
        mock_msh->fdout = -1;
}

void jarre_stack(t_msh *msh, int argc, char **argv, char **envp)
{
    t_cmd *cmd = malloc(sizeof(t_cmd));
    cmd->argv = argv;
    cmd->len_argv = argc;
    cmd->next = NULL;
    msh->cmd = cmd;
    msh->len_cmds = 1;
    msh->envp = envp;
    msh->fdin = -1;
    msh->fdout = -1;
}

void jarre_pipes(t_msh *msh, int argc, char **argv, char **envp)
{
    t_cmd *cmd = malloc(sizeof(t_cmd) * argc);
    for (int i=0; i < argc; i++) {
        char **args = malloc(sizeof(char *) * 2);
        args[0] = argv[i];
        args[1] = NULL;
        cmd[i].argv = args;
        cmd[i].len_argv = 1;
        cmd[i].next = ((i < argc - 1) ? &cmd[i+1] : NULL);
    }
    msh->cmd = cmd;
    msh->len_cmds = argc;
    msh->envp = envp;
    msh->fdin = -1;
    msh->fdout = -1;
}

int main(int argc, char **argv, char **envp)
{
    //t_cmd cmd;
    t_msh mock_msh;
    //init_stack(&cmd, &mock_msh, envp);
    //jarre_stack(&mock_msh, argc - 1, &argv[1], envp);
    jarre_pipes(&mock_msh, argc - 1, &argv[1], envp);
    organization_env(envp, &mock_msh.env);
    organization_env(envp, &mock_msh.export);
    ft_exeggutor(&mock_msh);

    //ft_echo(&cmd);
    // ft_pwd();
	// ft_cd(&cmd);
    //ft_pwd();
	//ft_env(&cmd);
    //ft_export(&mock_msh);
    //ft_unset(&mock_msh);
   	//printenv(mock_msh.export);
    //printf("\n\n\n\n\n\n\n\n");
   	//printenv(mock_msh.env);
    //ft_env(&cmd);
    
    
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