/*
** EPITECH PROJECT, 2019
** firtree
** File description:
** firetree project by clément fleur
*/

void my_putchar(char c);

void write_space(int size, int check_star)
{
    int i = 1;

    while (i < (size) + check_star) {
        my_putchar(' ');
        i++;
    }
}

int check_line(int size, int row, int check_star)
{
    int i = 0;

    while (i < size + row) {
        my_putchar('*');
        i++;
    }
    my_putchar('\n');
    check_star -= 1;
    return check_star;
}

void write_end(int size, int check_star)
{
    int i = 0;

    while (i <= size * 2) {
        my_putchar(' ');
        i++;
    }
    for (int p = 0; p < size; p++) {
        my_putchar('|');
    }
    my_putchar('\n');
}

void tree(int size)
{
    int row = 0;
    int i = 0;
    int check_star = 2;

    write_space(size, check_star);
    my_putchar(' ');
    my_putchar('*');
    my_putchar('\n');
    for (int i = 0;  i < 3; i++) {
        row += 2;
        write_space(size, check_star);
        check_star = check_line(size, row, check_star);
    }
    write_end(size, check_star);
}
