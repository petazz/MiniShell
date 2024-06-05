#include "minishell.h"

void    ft_exeggutor(t_msh *msh)
{
    int tmpin;
    int tmpout;
	int fdout;
    int ret;
    int i;
    int fdpipe[2];
	char	*path;

    tmpin = dup(0);
    tmpout = dup(1);
    i = -1;
    if (msh->fdin == -1)
        msh->fdin = dup(tmpin);
    while(++i < msh->len_cmds)
    {
        dup2(msh->fdin, 0);
        close(msh->fdin);
        if (i == msh->len_cmds - 1)
        {
            if (msh->fdout == -1)
                fdout = dup(tmpout);
        }
        else
        {
            pipe(fdpipe);
            fdout = fdpipe[1];
            msh->fdin = fdpipe[0];
        }
        dup2(fdout, 1);
        close(fdout);
        if (!ft_builtins(msh))
        {
            ret = fork();
            if (!ret)
            {
                path = ft_get_path(msh);
                if (!path)
                    return(perror("error")); 
                execve(path, msh->cmd->argv, msh->envp);
                perror("error");
                exit(1);
            }
        }
		msh->cmd = msh->cmd->next;
    }
	dup2(tmpin, 0);
	dup2(tmpout, 1);
	close(tmpin);
	close(tmpout);
}

int    ft_builtins(t_msh *msh)
{
    if (!ft_strncmp(msh->cmd->argv[0], "echo", 4))
        return (ft_echo(msh->cmd), 1);
    else if (!ft_strncmp(msh->cmd->argv[0], "cd", 4))
        return (ft_cd(msh), 1);
    else if (!ft_strncmp(msh->cmd->argv[0], "export", 4))
        return (ft_export(msh), 1);
    else if (!ft_strncmp(msh->cmd->argv[0], "unset", 4))
        return (ft_unset(msh), 1);
    else if (!ft_strncmp(msh->cmd->argv[0], "pwd", 4))
        return (ft_pwd(), 1);
    else if (!ft_strncmp(msh->cmd->argv[0], "env", 4))
        return (ft_env(msh->cmd), 1);
    // else if (ft_strncmp(msh->cmd->argv[0], "exit", 4))
    //     ft_exit(msh->cmd);
    return (0);
    
}

char    *ft_get_content(t_env *env, char *name)
{
    while (env != NULL && env->next != NULL)
    {
        if (ft_strncmp(env->name, name, ft_strlen(name)+1) == 0)
            return (env->content);
		env = env->next;
	}
	return (NULL);
}

char	*ft_get_path(t_msh *msh)
{
	char	**content_splited;
	int		j;
	char	*path;
	char	*content;

	j = -1;
    if (access(msh->cmd->argv[0], X_OK) == 0)
       return (msh->cmd->argv[0]); 
    content = ft_get_content(msh->env, "PATH");
	if (!content)
		return (NULL);
	content_splited = ft_split(content, ':');
	while (content_splited[++j] != NULL)
	{
		path = ft_strjoin(content_splited[j], "/");
		path = ft_strjoin(path, msh->cmd->argv[0]);
		if(access(path, X_OK) == 0)
			return (path);
	}
	return (NULL);
}
