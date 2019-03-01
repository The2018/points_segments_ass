#include "points_segments.h"

int *points_segments_fast(int s, int p, int ** segments, int * points){
	struct Point *ps = malloc((p+2*s)*sizeof(struct Point));
	int * result = malloc(p*sizeof(int));
	for (int i = 0; i < s; i++){
		ps[2*i].x = segments[i][0];
		ps[2*i].type = BEGIN;
		ps[2*i+1].x = segments[i][1];
		ps[2*i+1].type = END;
	}
	for (int j = 2*s; j < p + 2*s; j++){
		ps[j].x = points[j-2*s];
		ps[j].type = DOT;
		ps[j].index = j -2*s;
	}
	qsort(ps, p+2*s, sizeof(ps[0]),is_better);
	int count = 0;
	for (int k = 0; k < 2*s+p; k++){
		if (ps[k].type == BEGIN){
			count +=1;
		}else if (ps[k].type == DOT){
			result[ps[k].index] = count;
		} else if (ps[k].type == END){
			count -=1;
		} 
	}
	return result;
}

int is_better(const void *a, const void *b){
	struct Point a_val = *(const struct Point *)a;
	struct Point b_val = *(const struct Point *)b;

	if (a_val.x < b_val.x){
		return -1;
	} else if (a_val.x > b_val.x){
		return 1;
	} else{
		if (a_val.type < b_val.type){
			return -1;
		} else if (a_val.type > b_val.type){
			return 1;
		} return 0;
	}

}
