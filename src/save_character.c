#include "minishell.h"

int	save_smaller_than(char *smaller, t_msh *msh)
{
	char	*content;

	if (smaller[0] == '<' && smaller[1] == '<')
	{
		content = ft_strdup("<<");
		tok_list(&msh->tok, T_HEREDOC, content, 0);
		return (2);
	}
	else
	{
		content = ft_strdup("<");
		tok_list(&msh->tok, T_REDIRECTION_INFILE, content, 0);
		return (1);
	}
}

int	save_greater_than(char *greater, t_msh *msh)
{
	char	*content;

	if (greater[0] == '>' && greater[1] == '>')
	{
		content = ft_strdup(">>");
		tok_list(&msh->tok, T_APPEND, content, 0);
		return (2);
	}
	else
	{
		content = ft_strdup(">");
		tok_list(&msh->tok, T_REDIRECTION_OUTFILE, content, 0);
		return (1);
	}
}

int	save_pipe(t_msh *msh)
{
	char	*content;

	content = ft_strdup("|");
	tok_list(&msh->tok, T_PIPE, content, 0);
	return (1);
}

int	save_scape(char *wd, t_msh *msh)
{
	int i;
	char *content;
	int flag;

	i = 1;
	flag = 0;
	if (wd[i] == '\0')
		msj_error(ERROR_SLASH);
	else
	{
		if (wd[i + 1] != ' ' && wd[i + 1] != '|'
			&& wd[i + 1] != '>' && wd[i + 1] != '<')
			flag = 1;
		content = ft_substr(wd , 1, 1);
		tok_list(&msh->tok, T_WORD, content, flag);
	}
	return(i + 1);
}
