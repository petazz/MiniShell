#include "minishell.h"

void    ft_echo(t_cmd *cmd)
{
	int	i;
	int	n_flag;

	i = 1;
	n_flag = 0;
	while (cmd->argv[i] && (!ft_strncmp(cmd->argv[i], "-n", 3)))
	{
		n_flag = 1;
		i++;
	}
	while(cmd->argv[i])
	{
		ft_putstr_fd(cmd->argv[i], 1);
		if(i < cmd->len_argv - 1)
			write(1, " ", 1);
		i++;
	}
	if(!n_flag)
		write(1, "\n", 1);
}

void	ft_pwd()
{
	char buffer[200];
	getcwd(buffer, 200);
	printf("%s\n", buffer);
}

void	ft_cd(t_cmd *cmd)
{
	if (chdir(cmd->argv[1]) < 0)
		perror("error");
}

void	ft_env(t_cmd *cmd)
{
	(void)cmd;
	printf("%s\n", getenv("USER"));
}