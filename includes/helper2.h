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


#endif