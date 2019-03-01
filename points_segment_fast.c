#include "points_segments.h"

// int *points_segments_fast(int s, int p, int ** segments, int * points){
// 	int *result = malloc(p*sizeof(int));
// 	for (int i = 0; i < p; i++){
// 		int count = 0;
// 		for (int j = 0; j < s; j++){
// 			if (segments[j][0] < points[i] && points[i] < segments[j][1]){
// 				count ++;
// 			}
// 		result[i] = count;
// 		}
// 	}
// 	return result;
// }
