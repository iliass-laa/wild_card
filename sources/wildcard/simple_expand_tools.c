#include "../../includes/minishell.h"



char **clone(char **av, int len)
{
    int i;
    char **res;

    i = 0;
    res = (char **)malloc(sizeof(char *) *(len + 1));
    while (i <  len)
    {
        res[i] = ft_strdup(av[i]);
        i++;
    }
    res[i] = NULL;
    return (res);
}

void freedom(char ***dir_cont_array, t_dir_cont **dir_cont,char **working)
{
    free_mynigga(*dir_cont_array);
    free_dir_lst(dir_cont);
    free(*working);
}

void printd(char **av)
{
    int i =0;
    while (av[i])      
        printf("AV :: %s\n", av[i++]);
}

void print_valid_ones(t_dir_cont *head)
{
    t_dir_cont *tmp;

    tmp = head;
    while (tmp)
    {
        if (tmp->valid == 1)
            printf("VALID ONE :%s\n", tmp->value);
        tmp = tmp->next;
    }
}

char *get_next_valid(t_dir_cont * dir_cont, int index)
{
    int i;
    t_dir_cont *tmp;
    char *res;

    i = 0;
    tmp = dir_cont;
    res = NULL;
    while (tmp)
    {
        if (tmp->valid == 1 && index == i)
        {
            res = ft_strdup(tmp->value);
            return (res);
        }
        else if (tmp->valid == 1)
            i++;
        tmp = tmp->next;
    }
    return res;
}


char *get_work_direc()
{
    char *work_dir;
    char *last;

    work_dir = NULL;
    work_dir = getcwd(work_dir, 256);
    last = ft_strjoin(work_dir, "/");
    free(work_dir);
    // printf(">>Working directory :>>%s\n", work_dir);
    return(last);
}


char **unquote_old(char **old)
{
    int i;
    int res_len;
    char **res ;

    i = 0;
    res_len = dstr_len(old);
    res = (char **)malloc(sizeof(char*) * (res_len + 1));
    if (!res)
        panic("malloc failed \n");
    while (i < res_len)
    {
        res[i] = whithout_quotes(old[i]);
        i++;
    }
    res[i] = NULL;
    free(old);
    return (res);
}


char *take_slash_of(char *arg)
{
    int i;
    int newlen;
    char *new;

    i = 0;
    newlen = ft_strlen(arg) - 1;
    if (arg[newlen] != '/')
        return (arg);
    new = (char *)malloc(newlen + 1);
    if (!new)
        panic("malloc failed!\n");
    while (i < newlen)
    {
        new[i] = arg[i];
        i++;
    }  
    new[i] = 0;
    // free(arg);
    return(new);
}