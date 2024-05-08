int main(int argc, char **argv, char **envp)
{
    (void)argc;
    (void)argv;
    char **mock_args = malloc(sizeof(char*) * 10);
    mock_args[0] = "ls";
    mock_args[1] = "-l";
    mock_args[2] = 0;
    t_cmd mock_ls = {
        .path = "/bin/ls",
        .arg = mock_args,
        .len_arg = 2
    };
    t_msh mock = {
        .cmd = &mock_ls,
        .len_cmds = 1,
        .envp = envp,
        .fdinfile = -1,
        .fdoutfile = -1,
    };
    //(void)mock;
    ft_echo(mock.cmd->arg);
    // char *line = readline("minishell$ ");
    // while (line)
    // {
    //  add_history(line);
    //  free(line);
    //  line = readline("minishell$ ");
    // }
    return (0);
}