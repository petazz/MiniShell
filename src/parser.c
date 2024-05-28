#include "minishell.h"

static	void	print_token(t_tok *tok)
{
	while (tok)
	{
		printf("content type:  %d  content tok :%s\n", tok->type, tok->content);
		tok = tok->next;
	}
}

static	int	save_double_quote(char *str, t_tok *tokens)
{
	int	i;

	i = 0;
	if (str[i] == '\"')
	{
		i++;
		while (str[i] != '\"' && str[i])
			i++;
		if (str[i] == '\"')
		{
			tokens->content = ft_substr(str, 0, ++i);
			tokens->type = T_DOUBLE_QUOTE;
		}
		else
			printf("error liberar y salir\n");
	}
	return (i);
}

static	int	save_quote(char *str, t_tok *tokens)
{
	int	i;

	i = 1;
	while (str[i] != '\'' && str[i])
		i++;
	if (str[i] == '\'')
	{
		tokens->content = ft_substr(str, 0, ++i);
		tokens->type = T_SIMPLE_QUOTE;
	}
	else if (str[i] == '\0')
		printf("error liberar y salir\n");
	return (i);
}

static void	create_tokens(t_msh *msh, t_tok *aux, int i)
{
	while (msh->prompt[i])
	{
		while (msh->prompt[i] == ' ')
			i++;
		if (msh->prompt[i] != '|' && msh->prompt[i] != '<'
			&& msh->prompt[i] != '>' && msh->prompt[i] != '\0'
			&& msh->prompt[i] != '\'' && msh->prompt[i] != '\"')
			i += save_wd(&msh->prompt[i], aux);
		else if (msh->prompt[i] == '\'')
			i += save_quote(&msh->prompt[i], aux);
		else if (msh->prompt[i] == '\"')
			i += save_double_quote(&msh->prompt[i], aux);
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

void	check_lexer(t_msh *msh)
{
	t_tok	*aux;

	msh->tok = malloc(sizeof(t_tok));
	if (!msh->tok)
		return ;
	aux = msh->tok;
	create_tokens(msh, aux, 0);
	print_token(msh->tok);
}
