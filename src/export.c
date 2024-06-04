#include "minishell.h"

void	ft_swap(char **a, char **b)
{
	char *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void printenv(t_env *env)
{
	while(env)
	{
		printf("NAME: %s\n",env->name);
		printf("CONTENT: %s\n",env->content);
		printf("------------------------------\n");
		env = env->next;
	}
}

void	ft_sort_expt(t_msh *msh)
{
	t_env	*one;
	t_env	*other;
	
	one = msh->export;
	while (one && one->next)
	{
		other = msh->export;
		while(other->next)
		{
			if(ft_strncmp(other->name, other->next->name, ft_strlen(other->name)) > 0)
			{
				ft_swap(&other->name, &other->next->name);
				ft_swap(&other->content, &other->next->content);
			}
			other = other->next;
		}
		one = one->next;
	}
}

static void	ft_addback(t_env **export, t_env *aux)
{
	t_env	*actual;

	if (!*export)
		*export = aux;
	else
	{
		actual = *export;
		while (actual->next != NULL)
			actual = actual->next;
		actual->next = aux;
	}
}

t_env	*new_node(int i)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->content = NULL;
	new->name = malloc(sizeof(char) * i + 1);
	new->next = NULL;
	return (new);
}

void	ft_add_expt(t_msh *msh, int i, int j, t_env **env)
{
	char 	**str;
	t_env	*aux;

	aux = *env;
	str = msh->cmd->argv;
	while(str[++i])
	{
		j = 0;
		while(str[i][j])
		{
			if (str[i][j] == '=')
				break;
			j++;
		}
        aux = new_node(j);
		ft_strlcpy(aux->name, str[i], ++j);
		if (str[i][j - 1] != '=')
 			aux->content = ft_strdup("");
 		else
			aux->content = ft_strdup(&str[i][j]);
        ft_addback(env, aux);
		aux->next = NULL;
	}			
}

void	ft_export(t_msh *msh)
{
	if(msh->cmd->len_argv > 0)
	{
		ft_add_expt(msh, 0, 0, &msh->export);
		ft_add_expt(msh, 0, 0, &msh->env);
	}
	ft_sort_expt(msh);
    //printenv(msh->export);
}