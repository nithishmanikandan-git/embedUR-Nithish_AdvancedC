#include<stdio.h>
#include<pthread.h>
#include<signal.h>
#include<time.h>
#include<unistd.h>

int N;


void handler(int signal){
	if(signal == SIGINT) printf("\nSIGINT received!.\n Termination is prevented.\n");
}

int isPrime(int n){
	if(n<2) return 0;
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return 0;
	}
	return 1;
}

//Thread A - t1
void* sum_Prime(void* arg){
	int count=0,sum=0;
	clock_t start = clock();
	for(int i=2;count<N;i++){
		if(isPrime(i)){
			sum+=i;
			count++;
		}
	}
	clock_t end = clock();
	double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    	printf("\nThread A\n");
    	printf("Sum of first %d prime numbers = %d\n", N, sum);
    	printf("Execution Time = %f seconds\n", time_taken);

    	pthread_exit(NULL);
}

// Thread B - t2
void* thread_1(void* arg)
{
    time_t start = time(NULL);

    while(time(NULL) - start < 100)
    {
        printf("Thread 1 running\n");
        sleep(2);
    }

    pthread_exit(NULL);
}

// Thread C - t3
void* thread_2(void* arg)
{
    time_t start = time(NULL);

    while(time(NULL) - start < 100)
    {
        printf("Thread 2 running\n");
        sleep(3);
    }

    pthread_exit(NULL);
}

void main(){
	pthread_t t1,t2,t3;
	//Signal
	signal(SIGINT,handler);
	printf("Enter N: "); scanf("%d",&N);
	//create threads:
	pthread_create(&t1,NULL,sum_Prime,NULL);
	pthread_create(&t2,NULL,thread_1,NULL);
	pthread_create(&t3,NULL,thread_2,NULL);
	//wait for threads:
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);

	printf("\nAll threads completed its execution..!\n");
}
