#include "../includes/minishell.h"


// int main()
// {
//     char *str;
//     int status;

//     signal(SIGINT, signal_handler);
//     while (1)
//     {
//         status = 0;
//         if (g_sig == 1300)
//             status = 1;
//         g_sig = -1;
//         str = readline(">");

//         if (ft_strlen(str))
//         {
//             if (g_sig == -1)
//             {
//                 printf("i am about  to exec \n");
//                 printf("STATUS :%d\n", status);
//             }
//             if (g_sig == 1300)
//                 printf("SIG IS 130\n");
//         }
//         if (!str)
//             break;
//         free(str);
//     }
//     return (0);
// }