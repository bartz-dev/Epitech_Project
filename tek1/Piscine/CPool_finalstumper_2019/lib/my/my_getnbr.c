/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** my_getnbr.c
*/

int	my_getnbr(char *str)
{
  int	nb;
  int	isneg;
  int	i;

  isneg = 1;
  nb = 0;
  i = 0;
  while (str[i] == '+' || str[i] == '-')
    {
      if (str[i] == '-')
	isneg = isneg * -1;
      i = i + 1;
    }
  while (str[i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
	{
	  nb = nb * 10;
	  nb = nb + str[i] - '0';
	  i = i + 1;
	}
      else
	return (nb * isneg);
    }
  return (nb * isneg);
}