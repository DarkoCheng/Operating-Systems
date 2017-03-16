#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fcfs.h"

FILE *list;

int main(int argc, char *argv[]){
	char *num;
	int counterPro;
	int counterThr;
	int counterBru;
	char *reEnter;
	num = malloc(sizeof(char));
	// initial 3 list
	if (argc != 2)
    {
        printf("Wrong argunment!\n");
        exit(-1);
    }
    list = fopen(argv[1], "r");
    if (list == NULL)
    {
        printf("Could not open file %s\n", argv[1]);
        exit(-1);
    }

	int *numOfProcess, *numOfSwitchT, *numOfSwitchP;
	numOfProcess = (int *)malloc(sizeof(int));
	numOfSwitchT = (int *)malloc(sizeof(int));
	numOfSwitchP = (int *)malloc(sizeof(int));

	int *currentProcess, *numOfThread;
	currentProcess = (int *)malloc(sizeof(int));
	numOfThread = (int *)malloc(sizeof(int));

	int *currentThread, *arrivalTime ,*numOfBurst;
	currentThread = (int *)malloc(sizeof(int));
	arrivalTime = (int *)malloc(sizeof(int));
	numOfBurst = (int *)malloc(sizeof(int));

	int *currentBurst, *cpuTime, *ioTime;
	currentBurst = (int *)malloc(sizeof(int));
	cpuTime = (int *)malloc(sizeof(int));
	ioTime = (int *)malloc(sizeof(int));

	int *arrivalTimeque;
	arrivalTimeque = (int *)malloc(sizeof(int));

	firstline *headfirst;
	headfirst = creatFirstline();
	process *headpro;
	headpro = creatProcess();
	thread *headthr;
	headthr = creatThread();
	brust *headbru;
	headbru = creatBrust();
	brust *headque;
	headque = creatBrust();
/*
    var * temp;
    temo malloc
sscanf(str, ddd, &temp->a, temp->b)

insert(head, temp)

inside insert{
	temp->a, temp->b
}

*/
	
	fgets(num, 10, list);
//	printf("b");
	sscanf(num, "%d %d %d\n", numOfProcess, numOfSwitchT, numOfSwitchP);
//	insertFirstline(headfirst, numOfProcess, numOfSwitchT, numOfSwitchP);
	printf("%d %d %d\n", *numOfProcess, *numOfSwitchT, *numOfSwitchP);
	/*int counterPro;
	int counterThr;
	int counterBru;*/
	//counterBru = (int*)malloc(sizeof(int));
	//counterThr = (int*)malloc(sizeof(int));
	//counterPro = (int*)malloc(sizeof(int));
	counterBru = 1;
	counterThr = 1;
	counterPro = 1;

//	resetLocation(currentBurst,currentThread,currentProcess,ioTime);
	while(counterPro <= *numOfProcess){

		//pro
		fgets(num, 10, list);
		sscanf(num, "%d %d\n", currentProcess, numOfThread);
	//	printf("%d %d\n", *currentProcess, *numOfThread);
		
	//	counterThr = *numOfThread;
		//insertpro
		insertProcess(headpro, numOfThread, currentProcess);
	//	counterThr ＝ 1；
		while(counterThr <= *numOfThread){
			//thread
			fgets(num, 10, list);
			sscanf(num, "%d %d %d\n", currentThread, arrivalTime ,numOfBurst);
		//	printf("%d %d %d\n", *currentThread, *arrivalTime, *numOfBurst);
			//insertthre
			insertThread(headthr, arrivalTime, currentThread, numOfBurst);
			counterBru = 1;
			while(counterBru <= *numOfBurst){
            // brust
				fgets(num, 10, list);
				if(counterBru == *numOfBurst){
					sscanf(num, "%d %d\n", currentBurst, cpuTime);
					*currentThread = counterThr;
					*currentProcess = counterPro;
					*arrivalTimeque = *arrivalTime;
					printf("%d %d %d %d %d\n", *currentBurst, *cpuTime, *currentThread, *currentProcess, *arrivalTimeque);
				}else{
					sscanf(num, "%d %d %d\n", currentBurst, cpuTime, ioTime);
					*currentThread = counterThr;
					*currentProcess = counterPro;
					*arrivalTimeque = *arrivalTime;
					printf("%d %d %d %d %d %d\n", *currentBurst, *cpuTime, *ioTime, *currentThread, *currentProcess, *arrivalTimeque);
				}
				
				//insertbrust

				insertBrust(headbru, currentBurst, cpuTime, ioTime, currentThread, currentProcess, arrivalTimeque);
				counterBru++;
				//resetBrust(counterBru);
				printf("counterBru:%d\n",counterBru);			
			}
			counterBru = 1;

			//resetBrust(counterBru);
			counterThr ++;
			//resetThread(counterThr);
		}

		counterThr = 1;
		//resetThread(counterThr);
		counterPro++;
	}

	printList(headbru);
	return 0;
}
void printList(brust * headbru)
{
    brust * temp;
    temp = headbru->next;
    while (temp != NULL)
    {
        printf("currentBurst %d cpuTime: %d ioTime %d currentThread:%d currentProcess %d arrivalTimeque:%d \n", temp->currentBurst, temp->cpuTime, temp->ioTime, temp->currentThread, temp->currentProcess, temp->arrivalTimeque);
        temp = temp->next;
    }
}
firstline *creatFirstline(){
	firstline *new_firstline;
	new_firstline = (firstline *)malloc(sizeof(firstline));
	new_firstline -> next = NULL;
	return new_firstline;
}

process *creatProcess(){
	process *new_process;
	new_process = (process *)malloc(sizeof(process));
	new_process -> next = NULL;
	return new_process;
}
thread *creatThread(){
	thread *new_thread;
	new_thread = (thread *)malloc(sizeof(thread));
	new_thread -> next = NULL;
	return new_thread;
}
brust *creatBrust(){
	brust *new_brust;
	new_brust = (brust *)malloc(sizeof(brust));
	new_brust -> next =NULL;
	return new_brust;
}	
void insertFirstline(firstline *headfirst, int *numOfProcess, int *numOfSwitchT, int *numOfSwitchP){
	firstline *newNode, *currentNode;
	newNode = (firstline*)malloc(sizeof(firstline));
	newNode -> numOfProcess;
	newNode -> numOfSwitchT;
	newNode -> numOfSwitchP;
	newNode -> next = NULL;
	if(headfirst == NULL){
		headfirst = newNode;
	}else{
		currentNode = currentNode -> next;
	}
	currentNode -> next = newNode -> next;
}
void insertProcess(process *headpro, int *numOfThread, int *currentProcess){
	process *newNode, *currentNode;
	newNode = (process*)malloc(sizeof(process));
	newNode -> currentProcess;
	newNode -> numOfThread;
	newNode -> next = NULL;
}
void insertThread(thread *headthr, int *arrivalTime, int *currentThread, int *numOfBurst){
	thread *newNode, *currentNode;
	newNode = (thread*)malloc(sizeof(thread));
	newNode -> arrivalTime;
	newNode -> currentThread;
	newNode -> numOfBurst;
	newNode -> next = NULL;
}
void insertBrust(brust *headbru, int *currentBurst, int *cpuTime, int *ioTime, int *currentThread, int *currentProcess, int *arrivalTimeque){
	brust *newNode, *currentNode;
	newNode = (brust*)malloc(sizeof(brust));
 	newNode -> currentBurst = *currentBurst;
 	newNode -> cpuTime = *cpuTime;
 	newNode -> ioTime = *ioTime;
 	newNode -> currentThread = *currentThread;
 	newNode -> currentProcess = *currentProcess;
 	newNode -> arrivalTimeque = *arrivalTimeque;
 	newNode -> next = NULL;
}
/*
process_node *find(){
	process_node *head = new_process;
}*/
/*
void resetVariables(){
	totalWaitingTime = 0;
	totalContextSwitches = 0;
	cpuTimeUtilized = 0;
	sumTurnarounds = 0;
}
*//*
void resetLocation(int *currentBurst,int *currentThread, int *currentProcess, int *ioTime){
	 *currentBurst = -1;
	 *currentThread = -1;
	 *currentProcess = -1;
	 *ioTime = -1;
	 return;
}*/
void resetBrust(int *currentBurst){
	*currentBurst = 1;
	return;
}
void resetThread(int *currentThread){
	*currentThread = 1;
	return;
}
/*
int compare(){

}*/
/*
void reEnterTime(brust *headbru){
	brust *temp;
	temp = headbru->next;
	if(temp -> ioTime == -1){
		fgets(reEnter, 5, )
		printf("%d\n", );
	}
}*/






