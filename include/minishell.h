#ifndef MINISEHLL_H
# define MINISHELL_H

# include "libft.h"
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
	char	*cmd;
	char	**argv;
	int		len_argv;
} t_cmd;

typedef struct s_msh
{
    t_cmd   *cmd;
    int     len_cmds;
    char    **envp;
    int fdin; // -1 if not exist
    int fdout;
}   t_msh;

#endif