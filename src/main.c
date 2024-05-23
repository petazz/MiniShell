#include "minishell.h"
void	create_first_node(char **envp)
{
	t_msh *node;

	node = malloc(sizeof(t_msh));
	node->env = malloc(sizeof(t_env));
	if (!node)
		return ;
	int i;

	i = 0;
	while(envp[0][i])
	{
		if (envp[0][i] == '=')
			break;
		i++;
	}
	node->env->name = malloc(sizeof(char ) * i);
	ft_strlcpy(node->env->name,envp[0],i);
	node->env->content = ft_strdup(&envp[0][i]);
	printf("%s\n",node->env->name);
	printf("%s\n",node->env->content);
	node->env->next = NULL;
}
void printenv(t_msh *msh)
{
	while(msh->env)
	{
		printf("%s\n",msh->env->content);
		printf("%s\n",msh->env->name);
		msh->env = msh->env->next;
	}
}

void    organization_env(char **envp,t_msh *msh)
{
	int		i;
	int		j;
	t_msh	*aux;

	i = 1;
	j = 0;
	aux = msh;
	create_first_node(envp);
	while(envp[i][j])
	{
		aux->env->next = malloc(sizeof(t_env));
		if (!aux)
			return ;
		aux->env = aux->env->next;
		j = 0;
		while (envp[i][j])
		{
			if (envp[i][j] == '=')
				break;
			aux->env->name[j] = envp[i][j];
			j++;
		}
		aux->env->content = ft_strdup(&envp[i][j]);
		aux->env->next = NULL;
		i++;
	}
	printenv(aux);
}


int main(int argc, char **argv, char **envp)
{
	t_msh msh;
    (void)argc;
    (void)argv;
    organization_env(envp,&msh);
    return (0);
}