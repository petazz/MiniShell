#include "minishell.h"

void    ft_echo(char **args)
{
	int	i;
	int	n_flag;

	i = 1;
	n_flag = 0;
	if(args[1] && (!ft_strncmp(args[1], "-n", 3)))
	{
		n_flag = 1;
		i++;
	}
	while(args[i])
	{
		if(n_flag)
			ft_putstr_fd(args[i], 1);
		else
			printf("%s\n", args[i]);
		i++;	
	}
}

void	ft_cd(char **args)
{
	printf("%d", chdir(args[1]));
}
