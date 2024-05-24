#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	t_msh msh;
    (void)argc;
    (void)argv;
    organization_env(envp,&msh);
    return (0);
}