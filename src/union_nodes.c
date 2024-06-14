# include "minishell.h"
void	change_type(t_msh *msh)
{
	t_tok *aux;

	aux = msh->tok;
	while (aux)
	{
		if (aux->type == T_SIMPLE_QUOTE || aux->type == T_DOUBLE_QUOTE)
			aux->type = T_WORD;
		aux = aux->next;
	}
}

static t_tok *delete_next_node(t_tok *tok)
{
	t_tok *aux;

	aux = NULL;
	if (tok->next)
		aux = tok->next;
	free(tok->content);
	free(tok);
	if (aux)
		return (aux);
	else
		return (NULL);
}

void	union_tok(t_msh *msh, int flag_next)
{
	t_tok	*aux;
	char	*content_next;
	char	*content;

	aux = msh->tok;
	while(aux)
	{
		if (aux->flag == 1 && aux->next != NULL && flag_next == 1)
		{
			content_next = ft_strdup(aux->next->content);
			flag_next = aux->next->flag;
			content = ft_strdup(aux->content);
			free(aux->content);
			aux->content = ft_strjoin(content,content_next);
			free(content);
			free(content_next);
			aux->next = delete_next_node(aux->next);
		}
		else
		{
			flag_next = 1;
			aux = aux->next;
		}
	}
}
