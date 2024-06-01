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
        //builtin
		ret = fork();
        if (!ret)
        {
			path = ft_get_path(msh);
            execve(path, msh->cmd->argv, msh->envp);
			perror("error");
			exit(1);
        }
		msh->cmd = msh->cmd->next;
    }
	dup2(tmpin, 0);
	dup2(tmpout, 1);
	close(tmpin);
	close(tmpout);
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
