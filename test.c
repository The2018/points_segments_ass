#include "points_segments.h"

void print_array(int *arr, int size){
	for (int i=0; i<size; i++){
		printf("%d ",arr[i]);	
	}
	printf("\n");
}

void print_array_2D(int **arr, int rows, int cols){
	for (int i=0; i<rows; i++){
		printf("[");
		for (int j=0; j<cols; j++)
			printf("%d ",arr[i][j]);
		printf("] ");
	}
	printf("\n");
}


int main() {	
	const char * files[] = {"input1.txt", "input2.txt", "input3.txt"};   

	for (int f=0; f < 3; f++){
		FILE *pfile = fopen(files[f], "r");
		if(pfile == NULL)  {
			printf("Error opening file %s\n", files[f]);
			return 1;
		}
		
		int s, p;
		while(fscanf(pfile, "%d %d", &s, &p)!=EOF){		
		
			//allocate 2D array to hold s segments
			int ** segments = malloc(s*sizeof(int *));
			for (int i=0; i < s; i++){
				segments[i] = malloc(2*sizeof(int));
			}
		
			//scan all segment lines and populate the segments
			for (int i=0; i < s; i++){
				fscanf(pfile, "%d %d", &segments[i][0], &segments[i][1]);
			}		
		
			//allocate a single array to hold p points
			int * points = malloc(p*sizeof(int));
		
			//scan all point coordinates into points array
			for (int i=0; i < p; i++){
				fscanf(pfile, "%d", &points[i]);
			}
			
			printf("There are total %d segments, and %d points\n", s, p);
			
			print_array_2D(segments, s, 2);
			print_array(points, p);

			int * result1 = points_segments_naive(s, p, segments, points);
			int * result2 = points_segments_fast(s, p, segments, points);
			int check = 0;

			for (int i = 0; i < p; i++){
				if (result1[i] != result2[i]){
					check = 1;
				}
			} 
			if (check == 0){
				printf("OK\n");
			} else{
				printf("The result of naive algorithm is\n");
				print_array(result1, p);
				printf("The result of fast algorithm is\n");
				print_array(result2, p);
			}
			printf("\n");
			//points_segments_fast(int s, int p, int ** segments, int * points);
			//TODO: pass s, p, segments, and points to your two algorithms
			//the output should be an array of size p containing 
			//-for each point- the number of covering segments 
			
			//TODO: implement - compare these outputs from 2 algorithms
			
		}
		fclose(pfile);
	}
	return 0;
}