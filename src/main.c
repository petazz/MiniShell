#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	t_msh msh;
    (void)argc;
    (void)argv;
    (void)envp;
    int i = 0;
    msh.prompt = ft_strdup("ls -la < << | > >> hola");
    //organization_env(envp,&msh);
    check_lexer(&msh, i);
    return (0);
}