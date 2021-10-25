/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD01-clement.fleur
** File description:
** bitmap.h
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>

typedef struct __attribute__((packed)) bmp_header_s {
    int16_t magic;
    int32_t size;
    int16_t _app1;
    int16_t _app2;
    int32_t offset;
} bmp_header_t;

typedef struct __attribute__((packed)) bmp_info_header_s {
    int32_t size;
    uint32_t width;
    uint32_t height;
    int16_t planes;
    int16_t bpp;
    int32_t compression;
    int32_t raw_data_size;
    int32_t h_resolution;
    int32_t v_resolution;
    int32_t palette_size;
    int32_t important_colors;
} bmp_info_header_t;


void make_bmp_header(bmp_header_t *header, size_t size);
void make_bmp_info_header(bmp_info_header_t *header, size_t size);