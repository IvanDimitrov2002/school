#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct process_t {
    int id;
    int duration;
};

struct processor_t {
    int count;
    int total_time;
    struct process_t *processes;
};

void init(struct processor_t *processor){
    processor->count=0;
    processor->total_time=0;
    processor->processes = NULL;
}

void push(struct processor_t *processor, struct process_t new_process){
    processor->processes = (struct process_t*)realloc(processor->processes, sizeof(struct process_t)*(++processor->count));
    processor->processes[processor->count - 1] = new_process;
    processor->total_time+=new_process.duration;
}

void turn_off_processor(struct processor_t *processor){
    free(processor->processes);
}

int shortest_total_time(int size, struct processor_t processors[size]){
    int shortest = processors[0].total_time;
    int index_shortest=0;
    for(int i=1;i<size;i++){
        if(shortest>processors[i].total_time){
            shortest=processors[i].total_time;
            index_shortest=i;
        }
    }
    return index_shortest;
}

void processing(int size, struct processor_t *processors){
    struct process_t *processes = NULL;
    int processes_count=0, i=0, j;
    char input[11];
    while(1){
        scanf("%s", input);
        if(strcmp(input, "exit")==0){  //using "if" otherwise empty process is created
            free(processes);
            for(j=0;j<size;j++){
                turn_off_processor(&processors[j]);
            }
            break;
        }
        processes = (struct process_t*)realloc(processes, sizeof(struct process_t)*(++processes_count));
        processes[i].duration = atoi(input);
        processes[i].id = i+1;
        push(&processors[shortest_total_time(size, processors)], processes[i]);
        i++;
        if(i%5==0){
            for(j=0;j<size;j++){
                printf("Queue for processor %d: %d processes, Total time: %d\n", j+1, processors[j].count, processors[j].total_time);
            }
        }
    }
}

int main(int argc, char *argv[]){
    int size = atoi(argv[1]);
    struct processor_t processors[size];
    for(int i=0;i<size;i++){
        init(&processors[i]);
    }
    processing(size, processors);
    return 0;
}