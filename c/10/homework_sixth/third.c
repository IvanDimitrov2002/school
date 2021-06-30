#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

//using LONG_MAX from limits.h

struct graph_t{
    int size;
    int *matrix;
};

struct graph_t create_graph(){
    int x=0, y=0;
    struct graph_t graph;
    FILE* f = fopen("in.txt", "r");
    fscanf(f, "%d", &graph.size);
    graph.matrix = (int*)malloc(sizeof(int) * graph.size * graph.size);
    while(!feof(f)){
        if(x<graph.size){
            fscanf(f, "%d", (graph.matrix + x*graph.size + y));
            x++;
        }
        else{
            y++;
            x=0;
        }
    }
    fclose(f);
    return graph;
}

int shortest_way(int x, int y, struct graph_t graph){
    int checked[graph.size], i, current_index, start, current_way;
	long ways[graph.size], min;
    if(x>y){
        i=x;
        x=y;
        y=i;
    }
	memset(checked, 0, sizeof(int)*graph.size);
    for(i=1; i<graph.size; i++) ways[i]=LONG_MAX;
    start=x;
    checked[start]=1;
    ways[start]=0;
    while(checked[y]==0){
        min=LONG_MAX;
        current_index=0;
        for(i=1; i<graph.size; i++){
			if(*(graph.matrix + start*graph.size + i)>0){	
		        current_way=ways[start] + *(graph.matrix + start*graph.size + i);
		        if(current_way<ways[i] && checked[i]==0) ways[i]=current_way;
		        if(min>ways[i] && checked[i]==0){
		            min=ways[i];
		            current_index=i;
		        }
			}
        }
        start=current_index;
        checked[start]=1;
    }
    return ways[y];
}

int main(){
	int x, y;
    struct graph_t graph = create_graph();
	scanf("%d", &x); scanf("%d", &y);
	printf("Shortest way: %d\n", shortest_way(x, y, graph));
    free(graph.matrix);
    return 0;
}