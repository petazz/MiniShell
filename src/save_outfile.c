#include "minishell.h"

t_tok	*save_append(t_tok *aux, t_msh *msh)
{
	aux = aux->next;
	msh->fdout = open(aux->content, O_RDWR | O_CREAT | O_APPEND, 0644);
	aux = aux->next;
	return (aux);
}

t_tok	*save_trunc(t_tok *aux, t_msh *msh)
{
	aux = aux->next;
	msh->fdout = open(aux->content, O_RDWR | O_CREAT | O_TRUNC, 0644);
	aux = aux->next;
	return (aux);
}
