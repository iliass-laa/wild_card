#include "../../includes/minishell.h"

int count_matches(char *old, t_dir_cont *dir_cont)
{
    int ret;
    int type;
    t_globing *wild;

    wild = wilding(old);
    type = file_or_dir(old);
    check_validation(old, dir_cont, type);
    ret = is_there_a_match(dir_cont);
    freeglobing(&wild);
    return (ret);
}

int count_new_args(char **old, t_dir_cont *dir_cont, int *index)
{
    int ret;
    int i;

    ret = 0;
    i = 0;
    while(old[i])
    {
        if (is_it_wild(old[i]))
        {
            ret = count_matches(old[i], dir_cont);
            if (ret)
                *index = 1;
        }
        else
            ret ++;
        i++;
    }
    return (ret);
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
            return (ft_strdup(dir_cont->value));
        else if (tmp->valid == 1)
            i++;
        tmp = tmp->next;
    }
    return res;
}

void  get_matches(char **new, char *needle, t_dir_cont *dir_cont, int *index)
{
    int i;
    int foundedlen;

    i = 0;
    foundedlen = count_matches(needle, dir_cont);
    if (foundedlen == 0)
        return;
    while (i < foundedlen)
    {
        new[*index] = get_next_valid(dir_cont, i);
        i++;
        (*index)++;
    }
    return;
}

char **get_new_args(char **old, int new_len, t_dir_cont *dir_cont)
{
    int i;
    int j;
    int tmp;
    char **new;

    i = 0;
    j = 0;
    new = (char **)malloc(sizeof(char *) * (new_len + 1));
    if (!new)
        panic("malloc failed !\n");
    while (i < new_len)
    {
        tmp = i;
        if (is_it_wild(old[j]))
        {
            get_matches(new, old[j], dir_cont, &i);
            if (i == tmp)
                new[i] = whithout_quotes(ft_strdup(old[j]));
        }
        else
            new[i] = whithout_quotes(ft_strdup(old[j]));
        i++;
        j++; 
    }
    new[i] = NULL;
    return (new);
}

void freedom(char ***dir_cont_array, t_dir_cont **dir_cont,char **working)
{
    free_mynigga(*dir_cont_array);
    free_dir_lst(dir_cont);
    free(*working);
}

char *get_work_direc()
{
    char *work_dir;

    work_dir = NULL;
    printf(">>Working directory :>>%s\n", work_dir);
    work_dir = getcwd(work_dir, 256);
    return(work_dir);
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

char **new_ones(char **old)
{
    char **new;
    int new_len;
    char *work_dir;
    char **dir_cont_array;
    t_dir_cont *dir_cont;
    int i;
    
    i = 0;
    if (is_it_wild_args(old) == 0)
        return (old);
        // return (unquote_old(old));
    work_dir = get_work_direc();
    dir_cont_array = all_dir_sorted(work_dir);
    dir_cont = array_to_lst_dir(dir_cont_array, work_dir);
    new_len = count_new_args(old, dir_cont, &i);
    printf(">>new_len : %d\n", new_len);
    if (new_len < 0 || i == 0)
        return (old);
        // return (freedom(&dir_cont_array, &dir_cont, &work_dir), unquote_old(old));
    new = get_new_args(old, new_len, dir_cont);
    return (new);
}

int main(int ac, char **av)
{
    char **new;
    int i;
    if (ac == 1)
        return(printf("more ARGS A zbi\n"));
    
    new = new_ones(av);
    i = 0;
    while (new[i])
    {
        printf("New >>%s\n", new[i]);
        i++;
    }
}