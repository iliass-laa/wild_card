#include "../../includes/minishell.h"

int count_matches(char *old, t_dir_cont *dir_cont)
{
    int ret;
    int type;

    type = file_or_dir(old);
    if (type == DIREC)
    {    
        // old = take_slash_of(old);
        printf("I AM LOOOKING FOR DIR %s\n", old);
    }
    else
        printf("I AM LOOOKING FOR ALL\n");
    print_dir_lst(dir_cont);

    check_validation(old, dir_cont, type);
    printf("#################################\n");
    printf("AFTER VALIDATION\n");
    printf("#################################\n");
    print_dir_lst(dir_cont);

    ret = is_there_a_match(dir_cont);
    printf("NbR of matches : %d\n", ret);
    return (ret);
}

int count_new_args(char **old, t_dir_cont *dir_cont, int *index)
{
    int ret;
    int nbr_mtches;
    int i;

    ret = 0;
    i = 0;
    while(old[i])
    {
        if (is_it_wild(old[i]))
        {
            nbr_mtches = count_matches(old[i], dir_cont);
            if (nbr_mtches > 0)
            {
                ret += nbr_mtches;
                *index = 1;
            }
            else
                ret++;
            reset_validation(dir_cont);
        }
        else
            ret ++;
        i++;
    }
    return (ret);
}


void  get_matches(char **new, char *needle, t_dir_cont *dir_cont, int *index)
{
    int i;
    int foundedlen;

    i = 0;
    foundedlen = count_matches(needle, dir_cont);
    print_dir_lst(dir_cont);
    if (foundedlen == 0)
        return;
    while (i < foundedlen)
    {
        new[*index] = get_next_valid(dir_cont, i);
        // printf("New ARGS (matches)>>%s\n",new[*index]);
        i++;
        (*index)++;
    }
    reset_validation(dir_cont);
    printf("#########################################\n");
    printf("After reseting!\n");
    printf("#########################################\n");
    print_dir_lst(dir_cont);
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
    // printf("NEW LEN TO ALLOCATE !>>>%d\n", new_len);
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
            else
            {
                // reset_vmalidation(dir_cont);
                printf("MIGHTY I<<%d>>\n", i);
            }
        }
        else
        {
            new[i] = whithout_quotes(ft_strdup(old[j]));
            printf("the one not wilding : %s\n",new[i]);
        }
        if (i == tmp)
            i++;
        j++; 
    }
    new[i] = NULL;
    return (new);
}

char **new_ones(char **old)
{
    char **new;
    int new_len;
    char *work_dir;
    char **dir_cont_array;
    t_dir_cont *dir_cont;
    int i;
    
    printf("$$$$$$$$$$$$$$$$$$$$\n");
    printd(old);
    printf("$$$$$$$$$$$$$$$$$$$$\n");
    i = 0;
    if (is_it_wild_args(old) == 0)
        return (printf("nothing is wild enough !\n"), unquote_old(old));
        // return (old);
    work_dir = get_work_direc();
    dir_cont_array = all_dir_sorted(work_dir);
    // printd(dir_cont_array);
    dir_cont = array_to_lst_dir(dir_cont_array, work_dir);
    new_len = count_new_args(old, dir_cont, &i);
    printf(">>new_len : %d\n", new_len);
    if (new_len < 0 || i == 0)
    {
        printf("nothing is wild enough 2!\n");
        return (freedom(&dir_cont_array, &dir_cont, &work_dir), unquote_old(old));
    }
    // print_valid_ones(dir_cont);
    new = get_new_args(old, new_len, dir_cont);
    free_mynigga(old);
    return (freedom(&dir_cont_array, &dir_cont, &work_dir), new);
}


int main(int ac, char **av)
{
    char **new, **old;
    int i, avlen;
    new = NULL;
    if (ac == 1)
        return(printf("more ARGS A zbi\n"));
    avlen = dstr_len(av);
    old = clone(av, avlen);
    new = new_ones(old);
    i = 0;
    while (new[i])
    {
        printf("New >>%s\n", new[i]);
        i++;
    }
    avlen = dstr_len(new);
    if (avlen > 2)
        free_mynigga(new);
}
