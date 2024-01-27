#include<stdio.h>
#include<stdlib.h>

typedef struct node  //creating a structure of node
{
    int data;
    struct node *next;
}node;
node *top=NULL;//initialising the top as null

void push(int dat){//function to push element in node
    node *temp=(node *)malloc(sizeof(node));//creating new node
    if(temp==NULL)//condtion for overflow of stack i.e when heap is full
        printf("stack overflow");
    temp->data=dat;
    temp->next=top;
    top=temp;//making the new node as top of stack
}
int pop(){//function to delete or pop element of stack
    int x=-1;
    if(top==NULL)//condtion for empty stack
        return -1;
    x=top->data;
    top=top->next;//moving the top forward 
    return x;
}
void peek(int index){// function to fetch the element at the given position if exists
    node *temp=top;//storing top's address into temp for traversing the stack which is in the form of linkedlist
    int i=0;
    for(;i<index-1&&temp!=NULL;i++)//either we get the index to check or we get null
        temp=temp->next;
    if(temp==NULL)//if get null means the index is out of bounds 
        printf("entered index is out of stack \n");
    printf("element at position %d is %d\n",++i,temp->data);
}

void display(){//function to display elements in stack
    if(top==NULL)
        printf("no element to print ");
    node *temp=top;
    printf("\ndisplaying data in stack ");
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void main(){
    node *st;
    int choice=1;
    while (choice)//loop for entering data
    {
        int x;
        printf("enter data ");
        scanf("%d",&x);
        push(x);
        printf("\nif you do not want to enter data than press 0 otherwise press any number ");
        scanf("%d",&choice);
    }

    display();
    printf("\nif you want to delete elements than enter how many elements you want to delete else press 0 ");
    scanf("%d",&choice);
    for(int i=0;i<choice;i++)//loop for poping out elements
        printf("popped elements are %d ",pop());
    display();

    char ch;
    printf("enter index at which you want to check element else press 'n' ");
    scanf(" %c", &ch);
    if(ch!='n'){//condition for peek
        int check=ch-'0';
        peek(check);
    }
    display();
}