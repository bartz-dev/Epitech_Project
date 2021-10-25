/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** match.h
*/

#ifndef __MATCH_STICK__
#define __MATCH_STICK__

typedef struct match_s
{
    char *lines;
    int line;
    int line2;
    char *maxs;
    int max;
    int pipe;
    int turn;
    int win;
} match_t;

int error_handling(char **argv, match_t *match, int ac);
char **my_strtodouble(match_t *match);
char **writemap(match_t *match, char **str);
int startgame(char **str, match_t *match, char *str2);
void remove_pipe(char **str, match_t *match, int nbr, int line);
void write_game(char **str, match_t *match);
void iaturn(char **str, match_t *match);
int checkerror_output(int nbr, match_t *match, char **str, int line);
int check_line(char **str, int line, match_t *match, char *str2);
void writeplayerinfo(int nbr, int line);

#endif /*__MATCH_STICK__ */
