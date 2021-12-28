/*********** ***************** *********/
/*********** Stack Array Based *********/
/*********** ***************** *********/

/*********** ***************** ****************/
/*  Author      : MAhmoud Shabban Gomaa       */
/*  Description : Stack Array BAsed           */
/*  Date        : 25/12/2021                  */
/*  Version     : 0.1                         */
/*********** ***************** ****************/


#include <stdio.h>
#include <stdlib.h>
#define max_size 100

/* Preprocessing part */
typedef struct Stack_Arr_Based
{
    int arr [max_size];
    int top;
}SA;

/***************************/
/*    Fucntions protype    */
/***************************/
void Stack_Void_Init( SA * ps);
void Stack_Void_Push(int value, SA * ps);
int Stack_Int_Pop(SA * ps);
int IsEmpty_Int(SA * ps);
int IsFull_Int(SA * ps);
int get_stack_size(SA * ps);
void print_Void_stack(SA * ps);

/* Main Function*/

int main(void)
{
    SA s1;  // Declearing stack object
    Stack_Void_Init( & s1); // Intialize the stack
    Stack_Int_Pop(& s1); // try to pop while the stack is empty
    Stack_Void_Push(16,& s1); // try push
    Stack_Void_Push(111,& s1);
    Stack_Void_Push(19,& s1);
    Stack_Void_Push(6,& s1);
    print_Void_stack(&s1); // print the stack values
    printf("\nThe stack size is: %d\n",get_stack_size(&s1)); // get the stack size
    Stack_Int_Pop(& s1); 
    Stack_Int_Pop(& s1);
    Stack_Int_Pop(& s1);
    Stack_Int_Pop(& s1);
    printf("\nThe stack after pop\n");
    print_Void_stack(&s1); // print stack after poping
     printf("\n%d\n",IsEmpty_Int(&s1));
    return 0;
}

int IsEmpty_Int(SA * ps)
{
    return ps->top == -1;
}

int IsFull_Int(SA * ps)
{
    return ps->top == (max_size-1);
}

void Stack_Void_Init( SA * ps)
{
    ps ->top = -1;
}

void Stack_Void_Push(int value, SA * ps)
{
    if(IsFull_Int(ps))
    {
        printf("stack is Full.");
    }
    else
    {
        ps->arr[++ps->top] =  value;
    }
}

int Stack_Int_Pop(SA * ps)
{
    if(IsEmpty_Int(ps))
    {
        printf("Stack is Empty.");
    }
    else
    {
        return (ps-> arr[ps->top--]) ;
    }

}

void print_Void_stack(SA * ps)
{
    if(!IsEmpty_Int(ps))
    {
        int i = ps->top;
        while(i >-1)
        {
        printf("\n%d",ps->arr[i]);
        i--;
        }
    }
    else
    {
        printf("your stack is empty");
    }
}

int get_stack_size(SA * ps)
{
    if(!IsEmpty_Int(ps))
    {
    return ps->top + 1;
    }
    else
    {
        printf("your stack is empty");
    }
} 