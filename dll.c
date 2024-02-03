#include<stdio.h>
#include<stdlib.h> 

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
}node;

node *first=NULL;

void create(){
    node *temp;
    int choice=1;
    while (choice)
    {
        printf("enter element ");
        node *newnode=(node *)malloc(sizeof(node));
        scanf("%d",&newnode->data);
        if (first==NULL)
        {
            newnode->prev=NULL;
            newnode->next=NULL;
            first=temp=newnode;
        }
        else {
            newnode->prev=temp;
            temp->next=newnode;
            newnode->next=NULL;
            temp=newnode;
    }
    printf("enter 0 to exit else 1 ");
    scanf("%d",&choice);
    }
}

void insert(int index,int data){
    node *newnode=(node *)malloc(sizeof(node));
    newnode->data=data;
    if (index==0)
    {
        newnode->prev=NULL;
        first->prev=newnode;
        newnode->next=first;
        first=newnode;
    }
    else {
        node *temp=first;
        for (int i = 0; i < index-1; i++)
        {
            temp=temp->next;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        free(temp);
    }
}

int delete(int index){
    
}

void display(){
    node *temp=first;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    free(temp);
}

void main(){
    create();
    display();
    //printf("%d ",first->next->next->next->prev->data);
    insert(0,23);
    display();
    free(first);
}