#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int launchbasic(char **av, int size);
char *getword();
int my_strlen(char *arg);
int findword(char *word, int size, char *arg);
int my_getnbr(char *s, int base);
