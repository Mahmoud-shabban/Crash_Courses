/*********** ***************** *********/
/*********** Queue LInked BAsed *********/
/*********** ***************** *********/

/*********** ***************** ****************/
/*  Author      : MAhmoud Shabban Gomaa       */
/*  Description : Queue LInked BAsed          */
/*  Date        : 27/12/2021                  */
/*  Version     : 0.1                         */
/*********** ***************** ****************/

#include <stdio.h>
#include <stdlib.h>

/* Preprocessing part */
typedef struct Queue_LInked_Based_Node
{
   int Data;
   struct Queue_LInked_Based_Node * Next;
}QN;

typedef struct Queue_LInked_Based
{
    QN * Front;
    QN * Rear;
    int Size;
}Q;



/***************************/
/*    Fucntions protype    */
/***************************/
// Function to initialize the Queue
void Queue__Void_Init(Q * pq);
// Function to Enqueue value into Queue
void Queue_Void_Enqueue(Q * pq, int value);
// Function to Dequeue value from Queue in given variable
void Queue_Void_Dequeue(Q * pq, int * Dequeueed );
// Function to check the Queue is full
int Queue_int_Is_Full(Q * pq);
// Function to check if a Queue is empty
int Queue_int_Is_Empty(Q * pq);
// Function to get the Queue size 
void get_void_Queue_size(Q * pq, int * size);
// Functon to get the top value in Queue
void get_void_Top_vlaue(Q * pq, int * R);
// Function to print the Queue contents
void print_Void_Queue(Q * pq);
// Function to clear the Queue contents
void clear_Void_Queue(Q * pq);

//************* Main Function***********//
int main(void)
{
    int size , x;
    Q q;
    
// Testing for initilization functions 
    Queue__Void_Init(&q);
    get_void_Queue_size(&q,&size);
    printf("your size initialy is: %d\n",size);
    printf("==================\n");

// Testing for Enquee function
    Queue_Void_Enqueue(&q,7);
    Queue_Void_Enqueue(&q,45);
    Queue_Void_Enqueue(&q,30);
    Queue_Void_Enqueue(&q,124);
    Queue_Void_Enqueue(&q,16);
    
// Testing for Enquee and get size functions
    get_void_Queue_size(&q,&size);
    printf("your size after enqueue is: %d\n",size);
    printf("==================\n");

// Testing for print Queue function
    print_Void_Queue(&q);
    printf("==================\n");

// Testing for Dequeue function
    Queue_Void_Dequeue(&q,&x);
    printf("your dequeueed is: %d\n",x);
    get_void_Queue_size(&q,&size);
    printf("your size after dequeue is: %d\n",size);
    printf("==================\n");

// Testing for Clear Queue function
    clear_Void_Queue(&q);
    get_void_Queue_size(&q,&size);
    printf("your size after clearing the queue is: %d\n",size);
    printf("==================\n");
    
    return 0;
}

/************* Function Declaration Section***********/

void Queue__Void_Init(Q * pq) 
{
    pq->Front = NULL;
    pq->Rear = NULL;
    pq->Size = 0;
}

void Queue_Void_Enqueue(Q * pq, int value) 
{
    //  this condition check for the first enquee process
    if(pq->Front == NULL)
    {
        // in the first enquee we allocate with teh rear
        pq->Rear = (QN*) malloc(sizeof(QN));    
        // move the front to the first location
        pq->Front = pq->Rear;
    }
    else
    {
        // not the first enquee operation
        // we allocate with Last nod pointer "Next" then move the rear
        // we used the Next pointer son we don't make the cod redundent
        pq->Rear->Next = (QN*) malloc(sizeof(QN));
        // move the rear to the new node
        pq->Rear = pq->Rear->Next;
    }  
    // setting Last node pointer "Next" to NULL
    pq->Rear->Next = NULL;
    // inserting the value
    pq->Rear->Data = value;
    // incrementing the size
    pq->Size++;
     
}

void Queue_Void_Dequeue(Q * pq, int * Dequeueed )
{
    if(Queue_int_Is_Empty(pq))
    {
        printf("your queue is empty");
    }
    else
    {
        * Dequeueed =  pq->Front->Data;
        // creating the temp to catch the last node 
        // while moving the Front so we can free the node later
        QN * temp = pq->Front;
        pq->Front = pq->Front->Next;
        // check if this is the last nod we dequeueing
        if(pq->Front == NULL)
        {
            pq->Rear = NULL; // to avoid Dangling pointer
        }
        // deallocate dequeued node
        free(temp);
        // decrement the size
        pq->Size--;
    }
}

int Queue_int_Is_Full(Q * pq)
{
    return 0;
}

int Queue_int_Is_Empty(Q * pq)
{
    return pq->Front == NULL;
}

void get_void_Queue_size(Q * pq, int * size)
{
    *size = pq->Size;
}

void get_void_Top_vlaue(Q * pq, int * R)
{
    *R = pq->Front->Data;
}

void print_Void_Queue(Q * pq)
{
    if(Queue_int_Is_Empty(pq))
    {
        printf("your queue is empty");
    }
    else
    {
        QN * temp = pq->Front;
        while(temp != NULL)
        {
            printf("%d\n",temp->Data);
            temp = temp->Next;
        }
        
    }
}

void clear_Void_Queue(Q * pq)
{
    if(Queue_int_Is_Empty(pq))
    {
        printf("your queue is empty");
    }
    else
    {
        // Using the rear to catch front node then clear that Node then Update
        // So we don't make our cod redundent 
        while(pq->Front !=NULL)
        {
            pq->Rear =pq->Front;
            pq->Front = pq->Front->Next;
            free(pq->Rear);
        }
        pq->Rear = NULL; // to avoid  Dangling pointer
        pq->Size = 0;
    }
}