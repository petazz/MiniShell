#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	t_msh msh;
    (void)argc;
    (void)argv;
    (void)envp;
    msh.prompt = ft_strdup("wc -l | echo -n '|||||'");
    //organization_env(envp,&msh);
    check_lexer(&msh);
    return (0);
}