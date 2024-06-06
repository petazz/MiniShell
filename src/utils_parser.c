#include "minishell.h"


void	msj_error_free(t_tok *token, char *str, t_msh *msh)
{
	t_tok	*aux;

	(void)msh;
	(void)token;
	(void)aux;
	if (str != NULL)
		ft_putendl_fd(str, 2);
	// while (token)
	// {
	// 	aux = token->next;
	// 	printf("token->content: %s\n", token->content);
	// 	free(token->content);
	// 	free(token);
	// 	token = aux;
	// }
	return ;
}
