#include "minishell.h"

// static	void	print_token(t_tok *tok)
// {
// 	while (tok)
// 	{
// 		printf("content type:  %d  content tok :%s\n", tok->type, tok->content);
// 		tok = tok->next;
// 	}
// } 

static int	syntactic_analysis(t_msh *msh, int i)
{
	t_tok	*aux;

	aux = msh->tok;
	while (aux)
	{
		if (aux->type == T_PIPE && i == 1)
		{
			msj_error_free(aux, ERROR_PIPES, msh);
			return (0);
		}
		else if (aux->type >= 7 && aux->type <= 11 && aux->next == NULL)
		{
			msj_error_free(aux, ERROR_NEWLINE, msh);
			return (0);
		}
		else if (aux->type >= 8 && aux->type <= 11 && aux->next->type != T_WORD)
		{
			msj_error_free(aux, ERROR_NEWLINE, msh);
			return (0);
		}
		i = 0;
		aux = aux->next;
	}
	return (1);
}

static	int	save_double_quote(char *str, t_msh *msh)
{
	int	i;
	char *content;

	i = 1;
	while (str[i] != '\"' && str[i])
		i++;
	if (str[i] == '\"')
	{
		content = ft_substr(str, 1, (i++) - 1);
		tok_list(&msh->tok, T_WORD, content);
	}
	else if (str[i] == '\0')
		msj_error_free(msh->tok, ERROR_DOUBLE_QUOTES, msh);
	return (i);
}

static	int	save_quote(char *str, t_msh *msh)
{
	int	i;
	char	*content;

	i = 1;
	while (str[i] != '\'' && str[i])
		i++;
	if (str[i] == '\'')
	{
		content = ft_substr(str, 1, (i++) - 1);
		tok_list(&msh->tok, T_WORD, content);
	}
	else if (str[i] == '\0')
		msj_error_free(msh->tok, ERROR_SIMPLE_QUOTES, msh);
	return (i);
}

static void	create_tokens(t_msh *msh, int i)
{
	while (msh->prompt[i])
	{
		while (msh->prompt[i] == ' ')
			i++;
		if (msh->prompt[i] != '|' && msh->prompt[i] != '<'
			&& msh->prompt[i] != '>' && msh->prompt[i] != '\0'
			&& msh->prompt[i] != '\'' && msh->prompt[i] != '\"')
			i += save_wd(&msh->prompt[i], msh);
		else if (msh->prompt[i] == '\'')
			i += save_quote(&msh->prompt[i], msh);
		else if (msh->prompt[i] == '\"')
			i += save_double_quote(&msh->prompt[i],msh);
		else if (msh->prompt[i] == '|')
			i += save_pipe(msh);
		else if (msh->prompt[i] == '<')
			i += save_smaller_than(&msh->prompt[i], msh);
		else if (msh->prompt[i] == '>')
			i += save_greater_than(&msh->prompt[i], msh);
	}
}

int	check_lexer(t_msh *msh)
{
	int 	ret;

	create_tokens(msh, 0);
	ret = syntactic_analysis(msh, 1);
	return (ret);
}
