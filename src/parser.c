#include "minishell.h"

void	check_lexer(t_msh *msh, int i)
{
	t_tok	*aux;

	msh->tok = malloc(sizeof(t_tok));
	if (!msh->tok)
		return ;
	aux = msh->tok;
	while (msh->prompt[i])
	{
		while (msh->prompt[i] == ' ')
			i++;
		if (msh->prompt[i] != '|' && msh->prompt[i] != '<'
			&& msh->prompt[i] != '>' && msh->prompt[i] != '\0')
			i += save_wd(&msh->prompt[i], aux);
		else if (msh->prompt[i] == '|')
			i += save_pipe(aux);
		else if (msh->prompt[i] == '<')
			i += save_smaller_than(&msh->prompt[i], aux);
		else if (msh->prompt[i] == '>')
			i += save_greater_than(&msh->prompt[i], aux);
		if (msh->prompt[i] != '\0')
		{
			create_next_node(aux);
			aux = aux->next;
		}
	}
}
