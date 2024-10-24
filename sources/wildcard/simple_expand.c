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
    return (ret);
}

int count_new_args(char **old, t_dir_cont *dir_cont, int *j)
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
                *j = 0;
        }
        else
            ret ++;
        i++;
    }
    return (ret);
}


void set_new_args(char **new, char *old, char *dir_name, int *i)
{

}

char **new_ones(char **old)
{
    char **new;
    int new_len;
    char *work_dir;
    char **dir_cont_array;
    t_dir_cont *dir_cont;
    int i;
    
    i = 1;
    if (is_it_wild_args(old) == 0)
        return (old);
    work_dir = get_work_direc();
    dir_cont_array = 
    new_len = count_new_args(old, );

    


    return (new);
}

