#include "ui.h"
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int gold = 100;
int soldiers = 0;
int health = 100;
int zombies = 1;

void* spawn_miner(){
	if(gold >= 100){
		print_msg("Miner created!");
		pthread_mutex_lock(&mutex);
		gold -= 100;
		print_gold(gold);
		pthread_mutex_unlock(&mutex);
		while(1){
			pthread_mutex_lock(&mutex);
			gold += 10;
			print_gold(gold);
			pthread_mutex_unlock(&mutex);
			sleep(1);
		}
	} else {
		print_fail("Not enough gold!");
	}
}

void spawn_soldier(){
	if(gold >= 10){
		print_msg("Soldier created!");
		pthread_mutex_lock(&mutex);
		gold -= 10;
		print_gold(gold);
		soldiers++;
		print_soldiers(soldiers);
		pthread_mutex_unlock(&mutex);
	} else {
		print_fail("Not enough gold!");
	}
}

void spawn_soldiers(){
	if(gold >= 100){
		print_msg("Soldier created!");
		pthread_mutex_lock(&mutex);
		gold -= 100;
		print_gold(gold);
		soldiers += 10;
		print_soldiers(soldiers);
		pthread_mutex_unlock(&mutex);
	} else {
		print_fail("Not enough gold!");
	}
}

void* spawn_zombies(){
	while(1){
		for(int i = 5; i >= 0; i--){
			pthread_mutex_lock(&mutex);
			print_zombies(i, zombies);
			pthread_mutex_unlock(&mutex);
			sleep(1);
		}
		if(zombies > soldiers){
			print_fail("Zombie attack succeded ;(!");
			pthread_mutex_lock(&mutex);
			health -= (zombies - soldiers);
			pthread_mutex_unlock(&mutex);
			if(health <= 0){
				game_end(zombies);
			} else {
				pthread_mutex_lock(&mutex);
				print_health(health);
				pthread_mutex_unlock(&mutex);	
			}
		} else {
			print_succ("Zombie attack deflected! :)");
		}
		pthread_mutex_lock(&mutex);
		zombies *= 2;
		pthread_mutex_unlock(&mutex);
	}
}

int main() {
	init();
	print_gold(gold);
	print_soldiers(soldiers);
	print_health(health);

	pthread_t zombies_thread;

	pthread_create(&zombies_thread, NULL, spawn_zombies, NULL);
	while(1) {
		int ch = get_input();
		switch(ch) {
			case 'm':
				{
					pthread_t miner_thread;
					pthread_create(&miner_thread, NULL, spawn_miner, NULL);
				}
				break;
			case 's':
				spawn_soldier();
				break;
			case 'x':
				spawn_soldiers();
				break;
			case 'q':
				game_end(zombies);
				break;
		}
	}
	return 0;
}