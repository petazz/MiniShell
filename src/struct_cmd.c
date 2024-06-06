#include "minishell.h"

// static	void	print_cmd(t_cmd *cmd)
// {
// 	int i;

// 	i = 0;
// 	while (cmd)
// 	{
// 		i = 0;
// 		while (cmd->argv[i])
// 		{
// 			printf("content cmd :%s\n", cmd->argv[i]);
// 			i++;
// 		}
// 		cmd = cmd->next;
// 	}
// } 

static void	add_back_cmd(t_cmd **cmd, t_cmd *new)
{
	t_cmd	*node;

	if (!*cmd)
		return ;
	else
	{
		node = *cmd;
		while ((*cmd)->next != NULL)
			*cmd = (*cmd)->next;
		(*cmd)->next = new;
		*cmd = node;
	}
}

static t_cmd	*new_node_cmd(int i, t_tok *tok)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->argv = malloc(sizeof(char *) * i);
	if (!cmd->argv)
		return (NULL);
	cmd->len_argv = i;
	i = 0;
	while (tok && tok->type == T_WORD)
	{
		cmd->argv[i] = ft_strdup(tok->content);
		tok = tok->next;
		i++;
	}
	cmd->argv[i] = NULL;
	cmd->next = NULL;
	return (cmd);
}

static t_tok	*create_node_cmd(t_tok *tok, t_msh *msh)
{
	t_tok	*aux;
	t_cmd	*new;
	int		i;

	i = 0;
	aux = tok;
	msh->len_cmds += 1;
	while (aux && aux->type == T_WORD)
	{
		aux = aux->next;
		i++;
	}
	if (msh->cmd)
	{
		new = new_node_cmd(i, tok);
		add_back_cmd(&msh->cmd, new);
	}
	else
		msh->cmd = new_node_cmd(i, tok);
	return (aux);
}

void	struct_cmd(t_msh *msh)
{
	t_tok	*aux;

	aux = msh->tok;
	while (aux != NULL)
	{
		if (aux->type == T_WORD)
			aux = create_node_cmd(aux, msh);
		else if (aux->type == T_PIPE)
			aux = aux->next;
		else if (aux->type == T_APPEND)
			aux = save_append(aux, msh);
		else if (aux->type == T_REDIRECTION_OUTFILE)
			aux = save_trunc(aux, msh);
		else if (aux->type == T_REDIRECTION_INFILE)
			aux = save_infile(aux, msh);
		else if (aux->type == T_HEREDOC)
			aux = save_heredoc(aux, msh);
	}
}
