#include "minishell.h"

void    ft_unset(t_msh *data)
{
    t_env **head;
    char *str;
    int i;
    i = 0;
    head = &data->export;
    while (data->cmd->argv[i])
    {
        str = data->cmd->argv[i];
        ft_pop(head, str);
        i++;
    }
    return ;
}

void    ft_pop(t_env **head, char *str)
{
    t_env   *temp;
    t_env   *aux = *head;
    if (*head == NULL)
        return ;
    while (aux != NULL && aux->next != NULL)
    {
        if (ft_strncmp(aux->name, str, ft_strlen(str)+1) == 0)
        {
            temp = aux->next;
            ft_swap(&aux->name, &aux->next->name);
            ft_swap(&aux->content, &aux->next->content);
            aux->next = aux->next->next;
            temp->next = NULL;
            free(temp->name);
            free(temp->content);
            free(temp);
        }
        aux = aux->next;
    }
}