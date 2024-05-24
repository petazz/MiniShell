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
}   t_tok;

typedef struct s_env
{
	struct s_env *next;
	char *content;
	char *name;
} t_env;

typedef enum e_stats
{
    init = 1,
    word = 2,
    quote = 3,
    double_quote = 4,
    dollar = 5,
    dollar_double_quote = 6
}   t_stats;

typedef struct s_msh
{
    t_cmd   **cmd;
	t_env	*env;
    char    *prompt;
    int     len_cmds;
    char    **envp;
    char    **tokens;
    int fdin; // -1 if not exist
    int fdout;
}   t_msh;
///////Envp////////
void    organization_env(char **envp,t_msh *msh);

//////////////BUILT-INS//////////////
void    ft_echo(t_cmd *cmd);
void	ft_pwd();
void	ft_cd(t_cmd *cmd);
void    ft_env(t_cmd *cmd);

#endif