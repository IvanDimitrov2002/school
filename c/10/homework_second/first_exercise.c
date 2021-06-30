#include <stdio.h>

struct pipe_t {
    int diameter;
    int flow;
};

struct pool_t {
    float capacity;
    int number_of_entry_pipes;
    int number_of_exit_pipes;
    int entry_flow_sum;
    int exit_flow_sum;
    struct pipe_t entry_pipes[5];
    struct pipe_t exit_pipes[5];
};

struct pool_t fill_time(struct pool_t the_pool){
    int x;
    the_pool.entry_flow_sum=0, the_pool.exit_flow_sum=0;
    for(x=0;x<the_pool.number_of_entry_pipes;x++){
        the_pool.entry_flow_sum+=the_pool.entry_pipes[x].flow;
    }
    for(x=0;x<the_pool.number_of_exit_pipes;x++){
        the_pool.exit_flow_sum+=the_pool.exit_pipes[x].flow;
    }
    the_pool.entry_flow_sum = the_pool.capacity / the_pool.entry_flow_sum;
    the_pool.exit_flow_sum = the_pool.capacity / the_pool.exit_flow_sum;    
    
    return the_pool;
}


int main(){
    struct pool_t pool;
    pool.capacity = 400.0;
    pool.number_of_entry_pipes = 3;
    pool.number_of_exit_pipes = 2;
    if(pool.number_of_entry_pipes>5 || pool.number_of_exit_pipes>5){
        printf("Too many pipes\n");
        return 0;
    }
    pool.entry_pipes[0].flow = 10;
    pool.entry_pipes[1].flow = 20;
    pool.entry_pipes[2].flow = 30;
    pool.exit_pipes[0].flow = 50;
    pool.exit_pipes[1].flow = 50;
    printf("Entry time: %d\nExit time: %d\n", fill_time(pool).entry_flow_sum, fill_time(pool).exit_flow_sum);
    return 0;
}