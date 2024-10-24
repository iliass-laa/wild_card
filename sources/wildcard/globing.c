#include "../../includes/minishell.h"

void freeglobing(t_globing **head)
{
    t_globing *tmp;

    while (*head)
    {
        tmp = (*head)->next;
        free((*head)->value);
        free(*head);
        *head = tmp;
    }   
}

void print_glob(t_globing *head)
{
    t_globing *tmp;

    tmp = head;
    while (tmp)
    {
        printf("val : %s, Pose: %d\n", tmp->value, tmp->pos);
        tmp = tmp->next;
    }
}

int get_next_wild(char *av, int i)
{
    while (av[i] && av[i] != '*')
    {
        if (av[i] == '\'' || av[i] == '"')
            i = get_next_quote(av, i);
        if (av[i])
            i++;
    }
    return i;
}

t_globing *create_glob_node(char *value, int pos)
{
    t_globing *node;

    node = (t_globing *)malloc(sizeof(t_globing));
    if (!node)
        panic("malloc failed !");
    if (is_quoted(value))
        value = whithout_quotes(value);
    node->value = value;
    node->pos = pos;
    node->found_it = 0;
    node->next = NULL;
    return (node);
}

t_globing *add_glob_node(t_globing *head, t_globing *new)
{
    t_globing *tmp;

    if (!head)
        return (new);
    tmp = head;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new; 
    return (head);
}

t_globing *wilding(char *s)
{
    int i;
    int j;
    int pos;
    int slen;
    t_globing *ret;
    char *val;

    i = 0;
    j = 0;
    ret = NULL;
    slen = (int)ft_strlen(s);
    while (s[i])
    {
        if (s[i] != '*')
        {
            j = get_next_wild(s, i);
            val = ft_substr(s, i, j - i);
            if (i == 0)
            {
                pos = FIRST;
                if (j == slen)
                    pos = ALL;
            }
            else if (j == slen)
                pos = LAST;
            else
                pos = MIDLLE;
            ret = add_glob_node(ret, create_glob_node(val, pos));
            i = j;
        }
        if (s[i])
            i++;
    }
    if (!ret)
        ret = create_glob_node(NULL, ALL);
    return ret;
}