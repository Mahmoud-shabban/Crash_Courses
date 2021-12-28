/*********** ***************** *********/
/*********** Queue Array BAsed *********/
/*********** ***************** *********/

/*********** ***************** ****************/
/*  Author      : MAhmoud Shabban Gomaa       */
/*  Description : Queue Array BAsed           */
/*  Date        : 27/12/2021                  */
/*  Version     : 0.1                         */
/*********** ***************** ****************/

#include <stdio.h>
#include <stdlib.h>
#define max_size 100

/* Preprocessing part */
typedef struct Queue_Array_Based
{
    int Front;
    int Rear;
    int Size;
    int Arr[max_size];
}Queue;

/***************************/
/*    Fucntions protype    */
/***************************/
// Function to initialize the Queue
void Queue__Void_Init(Queue * pq);
// Function to Enqueue value into Queue
void Queue_Void_Enqueue(Queue * pq, int value);
// Function to Dequeue value from Queue in given variable
void Queue_Void_Dequeue(Queue * pq, int * Dequeueed );
// Function to check the Queue is full
int Queue_int_Is_Full(Queue * pq);
// Function to check if a Queue is empty
int Queue_int_Is_Empty(Queue * pq);
// Function to get the Queue size 
void get_void_Queue_size(Queue * pq, int * size);
// Functon to get the top value in Queue
void get_void_Top_vlaue(Queue * pq, int * R);
// Function to print the Queue contents
void print_Void_Queue(Queue * pq);
// Function to clear the Queue contents
void clear_Void_Queue(Queue * pq);

//************* Main Function***********//
int main(void)
{
    int x, size;
    Queue q;
    Queue__Void_Init(&q);
    Queue_Void_Enqueue(&q,10);
    Queue_Void_Enqueue(&q,30);
    Queue_Void_Enqueue(&q,21);
    Queue_Void_Enqueue(&q,18);
    print_Void_Queue(&q);
    printf("=====================\n");
    Queue_Void_Dequeue(&q,&x);
    printf("you poped : %d\n",x);
    printf("=====================\n");
    get_void_Queue_size(&q,&size);
    printf("your queue size : %d\n",size);
    printf("=====================\n");
    print_Void_Queue(&q);
    return 0;
}

/************* Function Declaration Section***********/

void Queue__Void_Init(Queue * pq)
{
    pq->Front = -1;
    pq->Rear = -1;
    pq->Size = 0;
}

void Queue_Void_Enqueue(Queue * pq, int value)
{
    if(!Queue_int_Is_Full(pq))
    {
        if(pq->Front == -1)
        {
            pq->Front = 0;
        }
        pq->Rear++;
        pq->Arr[pq->Rear] = value;
        pq->Size++;
    }
    else
    {
        printf("your Queue is full");
    }
}

void Queue_Void_Dequeue(Queue * pq, int * Dequeueed )
{
    if(Queue_int_Is_Empty(pq))
    {
        printf("your Queue is Empty");
    }
    else
    {
        *Dequeueed = pq->Arr[pq->Front];
        pq->Front++;
        pq->Size--;
        if(pq->Front > pq->Rear)
        {
            pq->Front = -1;
            pq->Rear = -1;
        }
    }
}

int Queue_int_Is_Empty(Queue * pq)
{
    return pq->Front == -1;
}

int Queue_int_Is_Full(Queue * pq)
{
    return pq->Rear == (max_size-1);
}

void get_void_Queue_size(Queue * pq, int * size)
{
    *size = pq->Size;
}

void get_void_Top_vlaue(Queue * pq, int * R)
{
    if(!Queue_int_Is_Empty(pq))
    {
        *R =pq->Front;
    }
    else
    {
        printf("your stack is empty\n");
    }
}

void print_Void_Queue(Queue * pq)
{
    if(!Queue_int_Is_Empty(pq))
    {
        int i ;
        for(i = pq->Front; i<= pq->Rear; i++)
        {
            printf("%d\n",pq->Arr[i]);
        }
    }
    else
    {
        printf("your stack is epty");
    }
}

void clear_Void_Queue(Queue * pq)
{
    if(!Queue_int_Is_Empty(pq))
    {
        pq->Front = -1;
        pq->Rear = -1;
    }
    else
    {
        printf("your stack is empty");
    }
}