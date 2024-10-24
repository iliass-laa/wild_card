#ifndef EXPANDER_H
#define EXPANDER_H

typedef struct s_node {
    char *str;
    char type;
    struct s_node *next;
} t_node;

typedef struct s_split_arg 
{
    char *token;
    char prevChar;
    t_node *head;
    t_node *tail;
    t_node *node;
    char *tmpdup;
    char *start ;
    int indx ;
} t_split_arg;

typedef struct s_expn {
    t_node *tmp;
    char *new;
    char *value;
    char *tmpstr;
} t_expn;

typedef struct s_tokens_exp {
    bool in_double_quotes ;
    bool in_single_quotes ;
    char prevChar ;
    int i;
} t_tokens;

char **expander(char **argv, t_env *env);
char *tokenizer(char *arg);
t_node *splitArg(char *str);
char *joiner(char *arg, t_env* env);

t_node *create_node(char *value, char type);
void add_node(t_node **head, t_node **tail, t_node *node);
char *splitWordVar(char *value, t_env *env);
void mini_expander(t_node **head, t_env *env);
char *expand(t_node **head, t_env *env);

char *ft_name(char *arg);
void free_lst(t_node *head);
char *clean_qts(char *str);

int herdoc_newfd( int fd, t_env* myenv);

#endif