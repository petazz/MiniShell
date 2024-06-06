#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# define ERROR_PIPES "bash: syntax error near unexpected token `|'"
# define ERROR_NEWLINE "bash: syntax error near unexpected token `newline'"
# define ERROR_DOUBLE_QUOTES "bash: expected to close the double quote"
# define ERROR_SIMPLE_QUOTES "bash: expected to close the quote"
# define ERROR_NO_FILE ": No such file or directory"

typedef struct s_cmd
{
	char			**argv;
	int				len_argv;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_tok
{
	struct s_tok	*next;
	char			*content;
	int				type;
}	t_tok;

typedef struct s_env
{
	struct s_env	*next;
	char			*content;
	char			*name;
}	t_env;

typedef enum e_tok_type
{
	T_PIPE = 7,
	T_HEREDOC = 8,
	T_APPEND = 9,
	T_REDIRECTION_INFILE = 10,
	T_REDIRECTION_OUTFILE = 11,
	T_WORD = 12,
	T_SIMPLE_QUOTE = 13,
	T_DOUBLE_QUOTE = 14,
	T_DOUBLE_QUOTE_DOLLAR = 15
}	t_tok_type;

typedef enum e_stats
{
	S_INIT = 1,
	S_WORD = 2,
	S_QUOTE = 3,
	S_DOUBLE_QUOTE = 4,
	S_DOLLAR = 5,
	S_DOLLAR_DOUBLE_QUOTE = 6
}	t_stats;

typedef struct s_msh
{
	t_cmd	*cmd;
	t_env	*env;
	t_env	*exp;
	t_tok	*tok;
	char	*prompt;
	int		len_cmds;
	char	**envp;
	int		fdin;
	int		fdout;

}	t_msh;
///////ENVP////////
void	organization_env(char **envp, t_msh *msh);
////////FREE///////
void	free_msh(t_msh *msh);
///////UTILS_PARSER/////////
void	msj_error(char *str);
///////LEXER AND UTILS//////
int		check_lexer(t_msh *msh);
int		save_smaller_than(char *smaller, t_msh *msh);
int		save_greater_than(char *greater, t_msh *msh);
int		save_pipe(t_msh *msh);
int		save_wd(char *wd, t_msh *msh);
//////////NODES TOK///////////////
t_tok	*new_node_tok(int type, char *content);
void	add_back_tok(t_tok **tok, t_tok *aux);
void	tok_list(t_tok **tok,int type,char *content);
//////////STRUCT CMD///////////////
void	struct_cmd(t_msh *msh);
//////////SAVE OUTFILE/////////////
t_tok	*save_trunc(t_tok *aux, t_msh *msh);
t_tok	*save_append(t_tok *aux, t_msh *msh);
/////////SAVE INFILE//////////////
t_tok	*save_infile(t_tok *tok, t_msh *msh);
t_tok	*save_heredoc(t_tok *tok, t_msh *msh);
//////////////BUILT-INS//////////////
void	ft_echo(char **args);
void	ft_cd(char **args);

#endif