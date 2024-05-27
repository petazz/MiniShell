#include "minishell.h"

int	save_smaller_than(char *smaller, t_tok *tokens)
{
	int	i;

	i = 0;
	if (smaller[i] == '<' && smaller[i + 1] == '<')
	{
		tokens->content = ft_strdup("<<");
		tokens->type = T_HEREDOC;
		tokens->next = NULL;
		return (2);
	}
	else
	{
		tokens->content = ft_strdup("<");
		tokens->type = T_REDIRECTION_INFILE;
		tokens->next = NULL;
		return (1);
	}
}

int	save_greater_than(char *greater, t_tok *tokens)
{
	int	i;

	i = 0;
	if (greater[i] == '>' && greater[i + 1] == '>')
	{
		tokens->content = ft_strdup(">>");
		tokens->type = T_APPEND;
		tokens->next = NULL;
		return (2);
	}
	else
	{
		tokens->content = ft_strdup(">");
		tokens->type = T_REDIRECTION_OUTFILE;
		tokens->next = NULL;
		return (1);
	}
}

int	save_pipe(t_tok *tokens)
{
	tokens->content = ft_strdup("|");
	tokens->type = T_PIPE;
	tokens->next = NULL;
	return (1);
}

int	save_wd(char *wd, t_tok *tokens)
{
	int	i;

	i = 0;
	while (wd[i] != '|' && wd[i] != '<' && wd[i] != '>'
		&& wd[i] != ' ' && wd[i] != '\0')
		i++;
	tokens->content = ft_substr(wd, 0, i);
	tokens->type = T_WORD;
	tokens->next = NULL;
	return (i);
}

void	create_next_node(t_tok *tokens)
{
	if (!tokens->next)
	{
		tokens->next = malloc(sizeof(t_tok));
		if (tokens->next)
			return ;
		tokens->next = NULL;
	}
}
