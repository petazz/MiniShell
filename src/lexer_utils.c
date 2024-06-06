#include "minishell.h"

int	save_smaller_than(char *smaller, t_msh *msh)
{
	char *content;

	if (smaller[0] == '<' && smaller[1] == '<')
	{
		content = ft_strdup("<<");
		tok_list(&msh->tok, T_HEREDOC, content);
		return (2);
	}
	else
	{
		content = ft_strdup("<");
		tok_list(&msh->tok, T_REDIRECTION_INFILE, content);
		return (1);
	}
}

int	save_greater_than(char *greater, t_msh *msh)
{
	char *content;
	if (greater[0] == '>' && greater[1] == '>')
	{
		content = ft_strdup(">>");
		tok_list(&msh->tok, T_APPEND, content);
		return (2);
	}
	else
	{
		content = ft_strdup(">");
		tok_list(&msh->tok, T_REDIRECTION_OUTFILE, content);
		return (1);
	}
}

int	save_pipe(t_msh *msh)
{
	char *content;

	content = ft_strdup("|");
	tok_list(&msh->tok, T_PIPE, content);
	return (1);
}

int	save_wd(char *wd, t_msh *msh)
{
	int		i;
	char	*content;

	i = 0;
	while (wd[i] != '|' && wd[i] != '<' && wd[i] != '>'
		&& wd[i] != ' ' && wd[i] != '\0' && wd[i] != '\'' && wd[i] != '\"')
		i++;
	content = ft_substr(wd, 0, i);
	tok_list(&msh->tok, T_WORD, content);
	return (i);
}
