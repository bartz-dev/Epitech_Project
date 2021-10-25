/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD01-clement.fleur
** File description:
** pyramid.c
*/

int pyramid_path(int size, const int **map)
{
    int final_value = 0;
    int index = 0;

    for (int i = 0; i != size - 1; i++) {
            index = best_choice(map[i + 1], index);
            final_value +=  map[i + 1][index];
    }

    return final_value;
}

int best_choice(int *map, int index)
{
    return (map[index] < map[index + 1] ? index : index + 1);
}