#ifndef POINTS_SEGMENTS_H
#define POINTS_SEGMENTS_H

#include <stdio.h>
#include <stdlib.h>

#define BEGIN 0
#define END 2
#define DOT 1

void print_array(int *arr, int size);
void print_array_2D(int **arr, int rows, int cols);

int * points_segments_naive(int s, int p, int ** segments, int * points);
int * points_segments_fast(int s, int p, int ** segments, int * points);
int is_better(const void *p, const void *q);

struct Point{
	int x;
	int type;
	int index;
};

#endif