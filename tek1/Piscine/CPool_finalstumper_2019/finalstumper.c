/*
** EPITECH PROJECT, 2019
** finalstumper
** File description:
** by clement fleur and paul moccelin
*/

#include <unistd.h>
#include "rush3.h"
#include <stdio.h>

void cas2(char *buff, int x, int y)
{
    if (x == 1 | y == 1) {
        for (int i = 1; i < 4 ; i++) {
            my_putstr("[rush1-");
            my_put_nbr(i + 2);
            my_putchar(']');
            my_putchar(' ');
            my_put_nbr(x);
            my_putchar(' ');
            my_put_nbr(y);
        }
    }
}

int who_rush(char *buff, int x, int y)
{
	char *str;
	if (buff[0] == 'o') {
		my_putstr("[rush1-1]");
		my_putchar (' ');
		my_put_nbr(x);
    		my_putchar (' ');
		my_put_nbr(y);
	}
	else if (buff[0] == '/' || buff[0] == '*') {
		my_putstr("[rush1-2]");
		my_putchar (' ');
		my_put_nbr(x);
    		my_putchar (' ');
    		my_put_nbr(y);
	}
	else if (buff[0] == 'B') 
            cas2(buff, x, y);
        else
            cas1(buff, x, y);
}
	
void rush3(char *buff, int len)
{
    int x = 0;
    int y = len;

    x = my_strlen(buff);
    y = my_strlen2(buff);
    who_rush(buff, x, y);

}

int main()
{
    int BUFFER_SIZE = 10000;
    char buff[BUFFER_SIZE + 1];
    int offset = 0;
    int len;

    while ((len = read(0 , buff + offset , BUFFER_SIZE - offset)) > 0) {
        offset = offset + len;
    }
    buff[offset] = '\0';
    if (len < 0)
        return (84);
    rush3(buff, offset);
    return 0;
}
