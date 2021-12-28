/*********** ***************** *******************/
/*********** Circular Queue  Array BAsed *********/
/*********** ***************** *******************/

/*********** ***************** ****************/
/*  Author      : MAhmoud Shabban Gomaa       */
/*  Description : Queue Circular Array BAsed  */
/*  Date        : 27/12/2021                  */
/*  Version     : 0.1                         */
/*********** ***************** ****************/

#include <stdio.h>
#include <stdlib.h>
#define max_size 6 // testing on small size

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
    int x, size,top;
    Queue q;
// Initialization of the queue 
    Queue__Void_Init(&q);
// Enqueue some values until the Queue is full
    Queue_Void_Enqueue(&q,10);
    Queue_Void_Enqueue(&q,30);
    Queue_Void_Enqueue(&q,21);
    Queue_Void_Enqueue(&q,18);
    Queue_Void_Enqueue(&q,79);
    Queue_Void_Enqueue(&q,108);

// Enqueue when it is full.
    Queue_Void_Enqueue(&q,55);

// printing the queue
    print_Void_Queue(&q);
    printf("=====================\n");

// testing dequeue and preparing to check for circulation
    get_void_Queue_size(&q,&size);
    printf("your queue size : %d\n",size);
    Queue_Void_Dequeue(&q,&x);
// Deque one more time to create gap between top and rear to test print function
    Queue_Void_Dequeue(&q,&top);
    printf("you poped : %d\n",x);
    printf("you poped : %d\n",top);
    printf("=====================\n");
// Enqueue After Dequee the first element to check for circulation.
    Queue_Void_Enqueue(&q,55);
// get the queue size
    get_void_Queue_size(&q,&size);
    printf("your queue size : %d\n",size);
    printf("=====================\n");
    print_Void_Queue(&q);

    Queue_Void_Enqueue(&q,93);
 
    get_void_Queue_size(&q,&size);
    printf("your queue size : %d\n",size);
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
        // chech for first Enquee operation
        if(pq->Front == -1)
        {
            pq->Front = 0;
        }
        // check for free places in the queue and Circulate
        else if(pq->Front >0 && pq->Rear == max_size -1)
        {
            pq->Rear = -1;
        }
        
        pq->Rear++;
        pq->Arr[pq->Rear] = value;
        pq->Size++;
        printf("******* %d\n",pq->Rear);
    }
    else
    {
        printf("your Queue is full\n");
    }
}

void Queue_Void_Dequeue(Queue * pq, int * Dequeueed )
{
    if(Queue_int_Is_Empty(pq))
    {
        printf("your Queue is Empty\n");
    }
    else
    {
        *Dequeueed = pq->Arr[pq->Front];
        // check if we dequeue the last postion and circulate
        if(pq->Front+1 > max_size-1)
        {
            pq->Front = -1;
        }
        pq->Front++;
        pq->Size--;
    }
}

int Queue_int_Is_Empty(Queue * pq)
{
    return (pq->Front == -1 && pq->Rear == -1);
}

int Queue_int_Is_Full(Queue * pq)
{
    if(pq->Front < pq->Rear)
    {
        return ( pq->Rear == (max_size-1) && pq->Front == 0);
    }
    else
    {
        return pq->Rear +1 == pq->Front;
    }
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
        int i = pq->Front;
        // to overcome the issue when the front exceeding the rear
        while(i != pq->Rear+1)
        {
            // circulate if necessary;
            if(i > max_size -1)
            {
                i = 0;
            }
            printf("%d\n",pq->Arr[i]);
            i++;
        }
    }
    else
    {
        printf("your stack is empty\n");
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
        printf("your stack is empty\n");
    }
}