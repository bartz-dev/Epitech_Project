/*
** EPITECH PROJECT, 2019
** my_print_comb2
** File description:
** 
*/

int graph(int num)
{
    if (num == 9899)
        my_putchar('\n');
    else {
        my_putchar(',');
        my_putchar(' ');
    }
}
int check_a(int num)
{
    int a = num % 100;
    int b = num / 100;

    if (a <= b)
        return -1;
    return(num);
}
int my_print_comb2(void)
{
    int num;
    
    for (int i = 0; i < 10000; i++) {
        num = check_a(i);
        if (num > -1) {
            my_putchar((num / 1000) +48);
            num = num % 1000;
            my_putchar((num / 100) +48);
            num = num % 100;
            my_putchar(' ');
            my_putchar((num / 10) +48);
            num = num % 10;
            my_putchar((num) +48);
            graph(i);
        }
    }
    return(0);
}
