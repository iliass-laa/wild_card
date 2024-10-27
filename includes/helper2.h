#ifndef HELPER2_H
# define HELPER2_H

#include "struct.h"

/********************************************** */
//IF THE ARG ARE WILD CONVERT TO LIST
/************************************************* */

t_globing *create_glob_node(char *value, int pos);
t_globing *add_glob_node(t_globing *head, t_globing *new);
t_globing *wilding(char *s);
void freeglobing(t_globing **head);
void print_glob(t_globing *head);



/********************************************** */
// GET WHAT'S IN THE DIRECTORY, SORT IT AND PUT IT IN A LIST
/********************************************** */

t_dir_cont *creat_node(char *value, char *work_dir);
void print_dir_lst(t_dir_cont *head);
void add_to_lst_dir(t_dir_cont **head, t_dir_cont *new_node);
t_dir_cont *array_to_lst_dir(char **av, char *work_dir);
void free_dir_lst(t_dir_cont **head);

/*********************************** */
//JUST MORE USEFULL FUNCTIONS:
/********************************** */

int is_quoted(char *s);
int get_reslen(char *s);
char *whithout_quotes(char *value);

void check_validation(char *needle, t_dir_cont *head, int type);
int get_next_wild(char *av, int i);


/**************************** */
//LITTLE TOOLS :
/****************************** */
int file_or_dir(char *s);
int valid_dir(char *dir_nmae);


/************************************************/
// LLOKING FOR MATCHES 
/************************************************/
int is_there_a_match(t_dir_cont *head);
void reset_validation(t_dir_cont *head);



/**************************************************** */
// TOOLS OF SIMPLE EXPAND :
/**************************************************** */
char **clone(char **av, int len);
void freedom(char ***dir_cont_array, t_dir_cont **dir_cont,char **working);
void printd(char **av);
void print_valid_ones(t_dir_cont *head);
char *get_next_valid(t_dir_cont * dir_cont, int index);
char *get_work_direc();
char **unquote_old(char **old);
char *take_slash_of(char *arg);


/*************************************************************** */
//SIMPLE WILD EXPAND :
/*************************************************************** */

char **wild_expand(char **old);

/**************************************************************/
// SEARCHING TOOLS :
/**************************************************************/
int	check_last(char *needl, char *haystak, int i);
int	check_midd(char *needle, char *haystack, int *start, int *index);
int	check_first(char *needle, char *haystak, int *start, int *index);
int	check_glob(char *val, t_globing *node);
int	check_node_for_valid(t_globing *wild, t_dir_cont *head, int fil_or_dir);


#endif