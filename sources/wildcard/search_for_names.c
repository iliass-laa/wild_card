#include "../../includes/minishell.h"

int check_last(char *needl, char *haystak, int i)
{
    int stacklen;
    int needlen;

    needlen = ft_strlen(needl);
    stacklen = ft_strlen(haystak);
    while (needlen >= 0)
    {
        if (stacklen < 0)
            return 1;
        if (needl[needlen] != haystak[stacklen])
            return 1;
        if (stacklen < i)
            break;
        stacklen --;
        needlen --;
    }
    if (needlen == -1)
        return 0;
    return (1);
}

int check_midd(char *needle, char *haystack, int *start)
{
    int i;
    int j;

    i = *start;
    j = 0;
    while (haystack[i])
    {
        while (needle[j] && haystack[i + j] && haystack[i + j] == needle[j])
            j++;
        if (j == (int)ft_strlen(needle))
        {
            *start = i + j - 1;
            return 0;
        }
        else
            j = 0;
        i++;
    }
    return (-1);
}

int check_first(char *needle, char *haystak, int *start)
{
    int i;

    i = 0;
    while (needle[i] && haystak[i] && (needle[i] == haystak[i]))
        i++;
    if (i == (int)ft_strlen(needle))
    {
        *start = i;
        return 0;
    }
    return 1;
}

int check_glob(char *val, t_globing *node)
{
    int val_len;
    int ret;
    t_globing *tmp;
    int i;
    int j;

    val_len = ft_strlen(val);
    tmp = node;
    ret = 1;
    i = 0;
    j = 0;
    if (node->pos == ALL)
        return (ft_strncmp(val, node->value, val_len));
    while (tmp)
    {
        if (tmp->pos == FIRST)
        {
            ret = check_first(tmp->value, val, &i);
            if (ret != 0)
                j = 1;
        }
        if (tmp->pos == MIDLLE && j == 0)
        {
            ret = check_midd(tmp->value, val, &i);
            if (ret)
                j = 1;
        }
        if (tmp->pos == LAST && j == 0)
            ret = check_last(tmp->value, val ,i);
        tmp = tmp->next;
    }
    if (ret == 0)
        printf("THE MIGHTY I>>>>%d\n", i);
    (void)j;
    return (ret);
}

int check_node_for_valid(t_globing *wild, t_dir_cont *head, int fil_or_dir)
{

    if (fil_or_dir == DIREC && head->type != DIREC)
        return 1;
    if (wild->value == NULL && wild->pos == ALL)
        return(0);
    if (0 == check_glob(head->value, wild))
        return 0;
    (void)fil_or_dir;
    return 1;
}

int is_there_a_match(t_dir_cont *head)
{
    t_dir_cont *tmp;
    int match;

    match = 0;
    tmp = head;
    while (tmp)
    {
        if (tmp->valid == 1)
            match ++;
        tmp = tmp->next;
    }
    return match;
}

void reset_validation(t_dir_cont *head)
{
    t_dir_cont *tmp;

    tmp = head;
    while (tmp)
    {
        tmp->valid = 0;
        tmp = tmp->next;
    }
}

void check_validation(char *needle, t_dir_cont *head, int type)
{
    t_dir_cont *tmp;
    t_globing *glob;

    tmp = head;
    glob = wilding(needle);
    // printf("############\n");
    // print_glob(glob);
    while (tmp)
    {
        if (0 == check_node_for_valid(glob, tmp,type))
            tmp->valid = 1;
        tmp = tmp->next;
    }
    tmp = head;
    while(tmp)
    {
        if(needle[0] != '.' && tmp->valid == 1 && tmp->value[0] == '.')
            tmp->valid = 0;
        tmp = tmp->next;
    }
    freeglobing(&glob);
}


// char **names_u_need(char *s , t_dir_cont *head)
// {
//     char **names;
//     int fil_or_dir;
//     int i = 0;

//     fil_or_dir = ALL_KINDS;
//     if (s[ft_strlen(s) - 1] == '/')
//         fil_or_dir = DIREC;
//     return(names);
// }



// int main(int ac , char **av)
// {
//     int i;
//     t_globing *head;
//     if (ac != 3)
//         return 1;
    
//     i = 0;
//     head = wilding(av[1]);
//     print_glob(head);
//     printf("is it there ? : %d\n", check_midd( head->value, av[2], &i));
//     printf("MIGHTY I : %d\n", i);
//     freeglobing(&head);
// }




int main(int ac, char **av)
{
    t_dir_cont *head;
    char **whatsin;
    if (ac == 1)
        return(printf("enter more args \n"), 1);
    whatsin = all_dir_sorted("/home/ilaasri/Desktop/C_cursus/minishell_v2/");
    head = array_to_lst_dir(whatsin, "/home/ilaasri/Desktop/C_cursus/minishell_v2/");
    print_dir_lst(head);
    printf("Needle : %s\n", av[1]);
    check_validation(av[1], head, ALL_KINDS);
    printf("#######################################\n");
    printf("NUMBER OF MATCHES>>%d\n", is_there_a_match(head));
    print_dir_lst(head);
    free_mynigga(whatsin);
    free_dir_lst(&head);

    // (void)av;
    // (void)head;
    return 0;
}


