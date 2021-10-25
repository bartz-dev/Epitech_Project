/*
** EPITECH PROJECT, 2019
** do_op
** File description:
** by clement fleur
*/

int do_op(int lhs, int rhs, char op)
{
    if (op == '+')
        return (lhs + rhs);
    else if (op == '-')
        return (lhs - rhs);
    else if (op == '*')
        return (lhs * rhs);
    else if (op == '/')
        return (lhs / rhs);
    else if (op == '%')
        return (lhs % rhs);
    else
        return (0);
}
