/*********** ***************** *********/
/*********** Stack Array Based *********/
/*********** ***************** *********/

/*********** ***************** ********************************/
/*  Author      : MAhmoud Shabban Gomaa                       */
/*  Description : Solving Challanges using Stack Array Based  */
/*  Challanges  : Balanced Brackets -- Print String in Order  */
/*  Date        : 25/12/2021                                  */
/*  Version     : 0.1                                         */
/*********** ***************** ********************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_size 100

/* Preprocessing part */
typedef struct Stack_Arr_Based
{
    char arr [max_size];
    int top;
}SA;

/***************************/
/*    Fucntions protype    */
/***************************/
// Function to initialize the stack
void Stack_Void_init( SA * ps);
// Function to push value into stack
void Stack_Void_Push(SA * ps ,char value);
// Function to pop value from stack in given variable
void Stack_Void_Pop(SA * ps, char * poped );
// Function to check the stack is full (Always return True)
int IsFull_Int(SA * ps);
// Function to check if a stack is empty
int IsEmpty_Int(SA * ps);
// Function to get the stack size 
void get_stack_size(SA * ps, int * size);
// Functon to get the top value in stack
void get_Top_vlaue(SA * ps, char * R);
// Function to print the Stack contents
void print_Void_stack(SA * ps);
// Function to check if a string is balanced Time complexity = O(n)
void brackets_balance(char  string []);
// Function to print the string in reverse order or normal
void print_string(char string[], char order[]);

//************* Main Function***********//
int main(void)
{
    char test[] = "() m [] {} { () [][)()][{}][]{)}{(]{)(}{]})})}}}ah () ) ";
    brackets_balance(test);
    print_string("mahmoud shabban gomaa","Normal");
    return 0;
}




/***************************/
/*  Fucntions Defenition   */
/***************************/

/**** function brackets_balance Desciption ****/
/* 1- this function takes string we want to check and the variable to store the result in.
   2- it creates a stack and traverse the string for n times.
   3- in each loop it check for the openning and closing brackets.
       a- if it finds opening brackets it peforms push operation.
       b- if it finds closing brackets it performs check to find matching
          in the stack if ther is a match it performs pop operation.
       c- if finds a wild closing brackets it increments the value of the wild counter.
    4- check the stack and wild counter then returns the result. 
    5- If the String contains no brackets it will be dealed as BAlanced. */
void brackets_balance(char  string [])
{
    int result, x, i = 0, wild_counter = 0;
    char top_value ;
    char poped ;
    SA temp_stack;
    Stack_Void_init(& temp_stack);
    for(;i< strlen(string); i++)
    {
        if(string[i] == '(' || string[i] == '[' || string[i] == '{')
        {
            Stack_Void_Push(&temp_stack, string[i]);
        }
        else if(string[i] == ')' || string[i] == ']' || string[i] == '}')
        {
            get_Top_vlaue(&temp_stack, &top_value);
            if(string[i] == ')' && top_value == '(')
            {
                Stack_Void_Pop(&temp_stack, &poped);
            }
            else if(string[i] == ']' && top_value == '[')
            {
                Stack_Void_Pop(&temp_stack, &poped);
            }
            else if(string[i] == '}' && top_value == '{')
            {
                Stack_Void_Pop(&temp_stack, &poped);
            }
            else
            {
                wild_counter++;
            }

        }
    }
    result = IsEmpty_Int(&temp_stack) && wild_counter == 0;
    if(result == 1)
    {
        printf("\n***** your string is balanced ********\n");
    }
    else
    {
        printf("\n***** your string is Not balanced ******\n");
    }
}

/**** function print_string Desciption ****/
/* this function takes 2 arguments string to process and order to apply
   ther are 2 orders Normal order "string" will be printed as "string"
   'Reverse' order "string" will printed as "gnirts" */
void print_string(char string[], char order[])
{
    SA stack;
    Stack_Void_init(&stack);
    if(order == "Reverse")
    {
        int i = 0;
        for(; i<strlen(string); i++)
        {
            Stack_Void_Push(&stack,string[i]);
        }
        print_Void_stack(&stack);
    }
    else if(order == "Normal")
    {
        int i = strlen(string);
        for(; i>= 0; i--)
        {
            Stack_Void_Push(&stack,string[i]);
        }
        print_Void_stack(&stack);
    }
    else
    {
        printf("please choose correck order");
    }
}


void get_Top_vlaue(SA * ps, char * R)
{
    *R = ps->arr[ps->top];
}

int IsEmpty_Int(SA * ps)
{
    return ps->top == -1;
}

int IsFull_Int(SA * ps)
{
    return ps->top == (max_size-1);
}

void Stack_Void_init( SA * ps)
{
    ps ->top = -1;
}

void Stack_Void_Push(SA * ps ,char value)
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

void Stack_Void_Pop(SA * ps, char * poped )
{
    if(IsEmpty_Int(ps))
    {
        printf("Stack is Empty.");
    }
    else
    {
        * poped =  ps->arr[ps->top--] ;
    }

}

void print_Void_stack(SA * ps)
{
    if(!IsEmpty_Int(ps))
    {
        int i = ps->top;
        while(i >-1)
        {
        printf("\n%c",ps->arr[i]);
        i--;
        }
    }
    else
    {
        printf("your stack is empty");
    }
}

void get_stack_size(SA * ps, int * size)
{
    if(!IsEmpty_Int(ps))
    {
    *size =  ps->top + 1;
    }
    else
    {
        printf("your stack is empty");
    }
}