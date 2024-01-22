#include<stdio.h>
#include<stdlib.h>

struct node // structure to create a node
{
    int data;// member to store data in node
    struct node *next; // self-referenced structure for pointing to next node
}*head=NULL;// initializing a node which is head node which is pointing towards null 

void display(struct node *n){// function to display linked list
    if(n==NULL)
        printf("no element in linked list");
    else
    {
        struct node *temp=n;//defining a temp variable of pointer node type for traversing
        while(temp!=NULL){// going forward until reaches the last node i.e node which is pointing to null
            printf(" %d ",temp->data);
            temp=temp->next;//moving temp to next node
    }
  }  
}
void create(){// function to create a node
    struct node *temp,*newnode;// temp variable for going to next node after adding new node 
    int choice=1;// user can add as many node as it wants untill choice is 0 which will be given by user
    while(choice){//if choice is not zero we will hop into this while loop
        newnode=(struct node*)malloc(sizeof(struct node));// allocating memory to new node in heap and
                                                        //storing the address of that memory allocation to newnode
        printf("enter element in linked list ");//asking user to input element in node
        scanf("%d", &newnode->data);
        newnode->next=0;//storing 0 as address of newnode's next
        if(head ==0)// i.e initially when there is no node 
            head=temp=newnode;//storing the address of new node in head as well as in temp
        else{
            temp->next=newnode;//storing address of new node in the last node of un-updated linked list
            temp=newnode;//moving temp forward to last node of updated linked list
        }
        printf("enter 0 to exit or any other number to continue ");
        scanf("%d", &choice);
    }
}
void main(){
    create();
    printf("\ndisplaying elements");
    display(head);
}