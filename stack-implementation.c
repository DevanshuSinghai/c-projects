/*stack is a data structure that works on discipline LIFO(Last In First Out)
for implementation of stack we need 3 things to define 1st is size of stack(if we are 
implementing it using array), 2nd is top which shows the index where is the last element
 is stored and 3rd is a pointer which will be used to dynamically create an array
 
 in this example we are implementing stack using array  */
#include<stdio.h>
#include<stdlib.h>

typedef struct stack//declaring a structure to define the prototype of stack
{
    int size;
    int top;
    int *p;
}stack;

void create(stack *st){//function to create the stack in memory
    printf("enter size of stack ");
    scanf("%d",&st->size);
    st->p=(int *)malloc(sizeof(stack));//storing the address of memory which is allocated to stack/array
    st->top=-1;//initializing top =-1 which shows that stack is empty now
    free(st->p);
}
int push(stack *st,int x){//function to push element in stack 
    if(st->top==st->size-1){//if stack is full no element will then we push into it
        printf("overflow ");
        return 0;
    }
    else{
    st->top++;//pushing the element and incresing the top
    st->p[st->top]=x;
    return 1;
}}
int pop(stack *st){// function to pop element fromm stack in lifo order 
    if(st->top==-1){//if top =-1 than its empty ie no element is there to pop out
        printf("underflow ");
        return -1;
    }
    int x=st->p[st->top--];//poping element and decreasisng the top 
    return x;
}
void display(stack st){//function to display stack in lifo order
    if(st.top==-1)
        printf("no element to print ");
    int temp =st.top;
    printf("\n\ndisplaying element of stack\n");
    while (temp!=-1)
    {
        printf("%d ",st.p[temp]);
        --temp;
    }
}
void main(){
    stack st;
    create(&st);
    int choice=1;//choice to keep check when user does not want to give more values
    while (choice)
    {
        printf("enter element ");
        int x;
        scanf("%d",&x);
        choice=push(&st,x);//storing in choice so if the stack is full we will break out from loop at only that time
        if(choice==0)
            break;
        printf("for entering more elements pres 1 else press 0 ");
        scanf("%d",&choice);
    }
    display(st);
    printf("\nif you want to pop element enter the number how many you want to pop else press zero ");
    int x;
    scanf("%d",&x);
    if(x!=0)
        printf("elements which are popped are ");
    for(int i=0;i<x;i++){//loop to pop out as many elements as user wants
        if(st.top==-1)
            printf("no element left in stack ");
        printf("%d ",pop(&st));
    }
    printf("\nelements left after performing pop operation are %d ",st.top+1);
    display(st);
    
}
