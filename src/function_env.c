#include "minishell.h"

static void	create_first_node(char **envp, t_env *node)
{
	int	i;

	i = 0;
	while (envp[0][i])
	{
		if (envp[0][i] == '=')
			break ;
		i++;
	}
	node->name = malloc(sizeof(char ) * i + 1);
	if (!node->name)
		return ;
	ft_strlcpy(node->name, envp[0], i);
	node->content = ft_strdup(&envp[0][++i]);
	node->next = NULL;
}
// static void printenv(t_env *env)
// {
// 	while(env)
// 	{
// 		printf("NAME: %s\n",env->name);
// 		printf("CONTENT: %s\n",env->content);
// 		printf("--------------------------------\n");
// 		env = env->next;
// 	}
// }

static void	take_env(t_env *aux, char **envp)
{
	int	i;
	int	j;

	i = 0;
	while (envp[++i])
	{
		aux->next = malloc(sizeof(t_env));
		if (!aux->next)
			return ;
		aux = aux->next;
		j = -1;
		while (envp[i][++j])
		{
			if (envp[i][j] == '=')
				break ;
		}
		aux->name = malloc(sizeof(char) * j + 1);
		if (!aux->name)
			return ;
		ft_strlcpy(aux->name, envp[i], ++j);
		aux->content = ft_strdup(&envp[i][j]);
		aux->next = NULL;
	}
}

void    organization_env(char **envp,t_env **env)
{
	t_env	*aux;

	*env = malloc(sizeof(t_env));
	if (!*env)
		return ;
	aux = *env;
	create_first_node(envp,aux);
	take_env(aux,envp);
	//printenv(msh->env);
}
