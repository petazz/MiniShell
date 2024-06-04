#include "minishell.h"

int	save_smaller_than(char *smaller, t_tok *tokens)
{
	if (smaller[0] == '<' && smaller[1] == '<')
	{
		tokens->content = ft_strdup("<<");
		tokens->type = T_HEREDOC;
		return (2);
	}
	else
	{
		tokens->content = ft_strdup("<");
		tokens->type = T_REDIRECTION_INFILE;
		return (1);
	}
}

int	save_greater_than(char *greater, t_tok *tokens)
{
	if (greater[0] == '>' && greater[1] == '>')
	{
		tokens->content = ft_strdup(">>");
		tokens->type = T_APPEND;
		return (2);
	}
	else
	{
		tokens->content = ft_strdup(">");
		tokens->type = T_REDIRECTION_OUTFILE;
		return (1);
	}
}

int	save_pipe(t_tok *tokens)
{
	tokens->content = ft_strdup("|");
	tokens->type = T_PIPE;
	return (1);
}

int	save_wd(char *wd, t_tok *tokens)
{
	int	i;

	i = 0;
	while (wd[i] != '|' && wd[i] != '<' && wd[i] != '>'
		&& wd[i] != ' ' && wd[i] != '\0' && wd[i] != '\'' && wd[i] != '\"')
		i++;
	tokens->content = ft_substr(wd, 0, i);
	tokens->type = T_WORD;
	return (i);
}

void	create_next_node(t_tok *token)
{
	t_tok	*new_node;

	if (!token->next)
	{
		new_node = malloc(sizeof(t_tok));
		if (!new_node)
			return ;
		new_node->next = NULL;
		token->next = new_node;
	}
}
