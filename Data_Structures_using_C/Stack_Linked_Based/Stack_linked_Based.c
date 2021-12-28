/*********** ***************** *********/
/*********** Stack Linked Based *********/
/*********** ***************** *********/

/*********** ***************** *********/
/*  Author      : MAhmoud Shabban Gomaa       */
/*  Description : Stack Linked BAsed          */
/*  Date        : 25/12/2021                  */
/*  Version     : 0.1                         */
/*********** ***************** ****************/

#include <stdio.h>
#include <stdlib.h>

/* Preprocessing part */
typedef struct StackNode
{
    int Data;
    struct StackNode * Next; // struct StackNode * here to see the error of using SN before declaration
}SN;

typedef struct Stack_linked_Based
{
    SN * Top;
    int Size;
}Stack;

/***************************/
/*    Fucntions protype    */
/***************************/
// Function to initialize the stack
void Stack_Init(Stack* ps);
// Function to push value into stack
void Stack_Void_Push(Stack * ps ,int value);
// Function to pop value from stack in given variable
void Stack_Void_Pop(Stack * ps, int * poped );
// Function to check the stack is full (Always return True)
void IsFull_Void(Stack * ps , int * R );
// Function to check if a stack is empty
int IsEmpty_Int(Stack * ps);
// Function to get the stack size 
void get_stack_size(Stack * ps, int * size);
// Functon to get the top value in stack
void get_Top_vlaue(Stack * ps, int * R);
// Function to print the Stack contents
void print_Void_stack(Stack * ps);
// Function to clear the Stack contents
void clear_Void_stack(Stack * ps);

//************* Main Function***********//
int main(void)
{
    Stack s;
    int size,pop1,pop2,pop3,m;
    Stack_Init(&s);
    get_stack_size(&s, &size);
    printf("Stack Size initially is: %d\n",size);
    Stack_Void_Push(&s,10);
    Stack_Void_Push(&s,5);
    Stack_Void_Push(&s,8);
    Stack_Void_Push(&s,30);
    Stack_Void_Push(&s,6);
    get_stack_size(&s, &size);
    printf("Stack Size after push is: %d\n",size);
    printf("\n===================");
    print_Void_stack(&s);
    Stack_Void_Pop(&s,&pop1);
    printf("\nyour poped: %d\n",pop1);
    printf("\n===================");
    Stack_Void_Pop(&s,&pop2);
    printf("\nyour poped: %d\n",pop2);
    printf("\n===================");
    Stack_Void_Pop(&s,&pop3);
    printf("\nyour poped: %d\n",pop3);
    printf("\n===================");
    get_stack_size(&s,&size);
    printf("\nStack Size after pop is: %d\n",size);
    printf("\n===================");
    print_Void_stack(&s);
    clear_Void_stack(&s);
    print_Void_stack(&s);
    get_stack_size(&s,&size);
    printf("\nStack Size after clear is: %d\n",size);
    return 0;
}

/************* Function Declaration Section***********/

void Stack_Init(Stack* ps)
{
    ps->Top = NULL;
    ps->Size = 0;
}

void Stack_Void_Pop(Stack * ps, int * poped )
{
    if(!IsEmpty_Int(ps))
    {
        /* 1- First give the value poped back to user */
        *poped = ps->Top->Data;
        /* 2- Catch the Poped Node from Top so we can free Top and still have the poped Node */
        SN * temp = ps->Top;
        /* 3- now the Top is free we can move it to the Next Node */
        ps->Top = temp->Next;
        /* 4- Now we can deallocate the poped Node */
        free(temp);
        /* 5- Decrement the Size */
        ps->Size--;    
    }
    else
    {
        printf("your Stack is Empty");
    }
    
}

void Stack_Void_Push(Stack * ps ,int value)
{
    /* 1- allocate new node and catch it with pointer temp */
    SN * temp = (SN *) malloc(sizeof(SN));
    /* 2- Hand the Top pointer old Node to the 
    new Node pointer "Next" to free the Top Pointer hand 
    so it can catch the new Node without loosing the old Node. */
    temp->Next = ps->Top;
    /* 3- Catch the new Node with the Top pointer */
    ps->Top = temp;
    /* 4- Push the value in the Node */
    ps->Top->Data = value;
    /* Increment the Size */
    ps->Size++;
}

int IsEmpty_Int(Stack * ps)
{
    return ps->Top == NULL;
}

void IsFull_Void(Stack * ps, int * R)
{
    *R =  0;
}

void get_stack_size(Stack * ps, int * size)
{
    *size =  ps->Size ;
}

void get_Top_vlaue(Stack * ps, int * R)
{
    *R = ps->Top->Data;
}

void print_Void_stack(Stack * ps)
{
    if(!IsEmpty_Int(ps))
    {
        // Creating temp pointer to traverse the NOdes
        SN * temp = ps->Top;
        do
        {
            printf("\n%d",temp->Data);
            temp = temp->Next;
            if(temp->Next == NULL)
            {
                printf("\n%d",temp->Data);
            }
        }
        while(temp->Next !=NULL);
    }
    else
    {
        printf("\nyour stack is Empty");
    }
}

void clear_Void_stack(Stack * ps)
{
    if(!IsEmpty_Int(ps))
    {
        SN * temp;
        do
        {
            // Creating temp pointer to traverse the NOdes
            temp = ps->Top;
            ps->Top = temp->Next;
            free(temp);
            ps->Size--;
        }  
        while(ps->Top !=NULL);
    }
    else
    {
        printf("\nyour stack is Empty");
    }
}