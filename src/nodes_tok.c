#include "minishell.h"

t_tok	*new_node_tok(int type, char *content, int flag)
{
	t_tok	*tok;

	tok = (t_tok *)malloc(sizeof(t_tok));
	if (!tok)
		return (NULL);
	tok->content = ft_strdup(content);
	tok->type = type;
	tok->flag = flag;
	tok->next = NULL;
	return (tok);
}

void	add_back_tok(t_tok **tok, t_tok *aux)
{
	t_tok	*node;

	if (!*tok)
		return ;
	else
	{
		node = *tok;
		while ((*tok)->next != NULL)
			*tok = (*tok)->next;
		(*tok)->next = aux;
		*tok = node;
	}
}

void	tok_list(t_tok **tok, int type, char *content, int flag)
{
	t_tok	*aux;
	if (!*tok)
		*tok = new_node_tok(type, content, flag);
	else
	{
		aux = new_node_tok(type, content, flag);
		add_back_tok(tok, aux);
	}
	free(content);
}
