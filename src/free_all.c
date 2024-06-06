#include "minishell.h"

static void	free_token(t_tok **token)
{
	t_tok	*aux;

	if (!*token || !token)
		return ;
	while (*token)
	{
		aux = (*token)->next;
		free((*token)->content);
		free(*token);
		*token = aux;
	}
}

static void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
	matrix = NULL;
}

static void	free_cmd(t_cmd **cmd)
{
	t_cmd	*aux;

	if (!*cmd || !cmd)
		return ;
	while (*cmd)
	{
		aux = (*cmd)->next;
		free_matrix((*cmd)->argv);
		free(*cmd);
		*cmd = aux;
	}
}

void	free_msh(t_msh *msh)
{
	if (msh->cmd)
		free_cmd(&msh->cmd);
	if (msh->tok)
		free_token(&msh->tok);
	if (msh->prompt)
		free(msh->prompt);
	msh->len_cmds = 0;
}
