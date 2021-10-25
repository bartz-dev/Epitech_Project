/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** navy.h
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdbool.h>
#include <time.h>

int receive[3];

void my_free_tab(char **tab);
void help(void);
char **create_map(char **map);
void print_map(char **map);
int init_server(char **map, char **pos);
int init_client(char **map, char **pos, int pid_server);
char *read_file(char *file);
int run_navy(char **map, char **pos, int user);
void save_pos(char *buff, char ***pos);
void my_free_ptrtab(char ***tab);
char *get_info(void);
void print_game(char **map, char **ennemy_map);
char *get_info_attack(char **enemy_map);
void send_attack(char *attack, char **enemy_map);
int receive_attack(char **map, int ships);
int is_game_finished(int ships);
int result_attack(void);
void get_coord(void);
void my_kill(int sig, int pid);
void end_handler(int sig);
int send_ping_game_end(int ships, char **map, char **enemy_map);
int receive_ping_game_end(char **map, char **enemy_map);
int play_game(char **map, char **enemy_map, int user);

/*                      ERROR                    */

int check_error(int ac, char **av);
int getnbrlinepos(char *buff);
int getnbrcolpos(char *buff);
int check_strpos(char **pos);
int check_collision(char **pos);
int checkline2(char *pos, int nbr);
char **strategical_add(char **map, char **pos);
char **write_boat(char **map, char *pos, int boatnbr);
char **redirecting(char **map, int nbr1_pos, int letter_pos, char *pos);
char **write_down(char **map, int nbr1_pos, int letter_pos, char *pos);
char **write_right(char **map, int nbr1_pos, int letter_pos, char *pos);
int findposx(char **map, int nbr_pos, int letter_pos, char *pos);
int findposy(char **map, int nbr_pos, int letter_pos, char *pos);