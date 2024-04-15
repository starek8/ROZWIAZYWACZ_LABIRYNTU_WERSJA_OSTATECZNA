#ifndef BIN_TO_SF_H
#define BIN_TO_SF_H

#include <stdio.h>
#include <stdlib.h>

struct info_lab{
    int File_Id;
    char ESC;
    short columns;
    short lines;
    short entryx;
    short entryy;
    short exitx;
    short exity;
    char reserved[12];
    int counter;
    int solution_offset;
    char separator;
    char wall;
    char path;
} __attribute__((packed)); 

void wstaw_PK(FILE* file, FILE *bin);

FILE *StworzSf(FILE* file);

#endif