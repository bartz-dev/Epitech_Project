#include "my.h"

int detect_flag(char **av, int ac)
{
    int d = 0;
    
    for (int i = 3; i < ac && i <= 5; i+= 2) {
        if (av[i][0] == '-' && av[i][1] == 's') {
            d+= 2;
            break;
        }
    }
    for	(int i = 3; i < ac && i <= 5; i+= 2) {
	if (av[i][0] == '-' && av[i][1] == 'w') {
            d+=	1;
            break;
        }
    }
    return d;
}

int my_strlen(char *s)
{
    int i = 0;

    for (; s[i]; i++);
    return i;
}

void my_puterror(char *s)
{
    write(2, s, my_strlen(s));
}

int init_game(char **av, int flag)
{
    int size = 4;

    if (flag == 2) {
        size = atoi(av[4]);
        launchbasic(av, size);
        printf("%d\n", size);
    }
    else if (flag == 1)
        findword(av[4], size, av);
    else if (flag == 3) {
        if (av[3][0] == '-' && av[3][1] == 's') {
            size = atoi(av[4]);
            findword(av[6], size, av);
        }
        if (av[5][0] == '-' && av[5][1] == 's') {
            size = atoi(av[6]);
            findword(av[4], size, av);
        }
    }
}

int main(int ac, char **av)
{
    int flag = 0;

    if (ac < 3 || ac > 7) {
        my_puterror("Usage: ./boggle -g GRID [-s SIZE] [-w WORD]\n");
        return 84;
    }
    if (ac == 3 && av[1][0] == '-' && av[1][1] == 'g')
        launchbasic(av, 4);
    else if (ac > 3)
        flag = detect_flag(av, ac);
    else {
        my_puterror("Usage: ./boggle -g GRID [-s SIZE] [-w WORD]\n");
        return 84;
    }
    init_game(av, flag);
    printf("%d\n", flag);
}
