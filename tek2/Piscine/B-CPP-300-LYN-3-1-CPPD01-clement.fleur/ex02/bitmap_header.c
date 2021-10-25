/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD01-clement.fleur
** File description:
** bitmap_header.c
*/

#include <string.h>
#include <stdlib.h>
#include "bitmap.h"

void make_bmp_header(bmp_header_t *header, size_t size)
{
    int little_endian = 1;

    memset(header, 0, sizeof(*header));
    if (*(char *)&little_endian == 1)
        header->magic = 0x4D42;
    else
        header->magic = 0x424D;
    header->_app1 = 0;
    header->_app2 = 0;
    header->size = size * size * 4 + sizeof(bmp_header_t)
    + sizeof(bmp_info_header_t);
    header->offset = sizeof(bmp_header_t) + sizeof(bmp_info_header_t);
}

void make_bmp_info_header(bmp_info_header_t *header, size_t size)
{
    memset(header, 0, sizeof(*header));
    header->size = 40;
    header->height = size;
    header->width = size;
    header->raw_data_size = size * size * 4;
    header->planes = 1;
    header->bpp = 32;
    header->compression = 0;
    header->v_resolution = 0;
    header->h_resolution = 0;
    header->palette_size = 0;
    header->important_colors = 0;
}