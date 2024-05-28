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

typedef struct s_cmd
{
	char	*path;
	char	**argv;
	int		len_argv;
} t_cmd;

typedef struct s_tok
{
    struct s_tok *next;
    char *content;
    int type;
}   t_tok;

typedef struct s_env
{
	struct s_env *next;
	char *content;
	char *name;
} t_env;

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
} t_tok_type;

typedef enum e_stats
{
    S_INIT = 1,
    S_WORD = 2,
    S_QUOTE = 3,
    S_DOUBLE_QUOTE = 4,
    S_DOLLAR = 5,
    S_DOLLAR_DOUBLE_QUOTE = 6
}   t_stats;

typedef struct s_msh
{
    t_cmd   **cmd;
	t_env	*env;
    t_tok   *tok;
    char    *prompt;
    int     len_cmds;
    char    **envp;
    char    **tokens;
    int fdin; // -1 if not exist
    int fdout;
}   t_msh;
///////ENVP////////
void    organization_env(char **envp,t_msh *msh);
///////LEXER AND UTILS//////
void	check_lexer(t_msh *msh);
int     save_smaller_than(char *smaller, t_tok *tokens);
int	    save_greater_than(char *greater, t_tok *tokens);
int	    save_pipe(t_tok *tokens);
int	    save_wd(char *wd, t_tok *tokens);
void	create_next_node(t_tok *tokens);

//////////////BUILT-INS//////////////
void    ft_echo(char **args);
void	ft_cd(char **args);

#endif