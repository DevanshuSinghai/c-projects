#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *head=NULL;
int size=0;
void create(){
    node *temp;
    int choice=1;
    while (choice)
    {
        node *newnode=(node *)malloc(sizeof(node));
        printf("enter data ");
        scanf("%d",&newnode->data);
        if(head==0){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        temp->next=head;  //this line makes the linear linked list in circular linked list
        printf("if you want to exit press 0 else press 1 ");
        scanf("%d",&choice);
        size++;
    }
   // printf("\n%d\n",temp->next->next->data); just checking if its circular or not :)
}

void insert(int index, int data){ //funtion to insert node
    node *t,*p=head;
    if(index>0&&index<size){  //condition to check that index is in range or not 
        if(index==1){  //inserting at the beginning
            t=(node *)malloc(sizeof(node));  //allocating size to the node which we want to insert
            t->data=data; //storing the data in the new node
            if(head==NULL){ //if no elements is in linked list
                head=t; 
                head->next=head;
            }
            else{ 
                while (p->next!=head) //going to the last node which points the head node
                    p=p->next;
                p->next=t;  //pointing last node's next to t to make it first node 
                t->next=head; // now pointing t's next to head
                head=t; //making t as head node
            }
        }
        else  // if inserting anywhere except first node
        {
            t=(node *)malloc(sizeof(node));
            t->data=data;
            for (int i = 1; i < index-1; i++) //going to previous node of index node
            {
                p=p->next;
            }
            t->next=p->next; 
            p->next=t;
        }
    }
    else printf("\nindex of insertion is not in range ");
}

int delete(int index){  //funtion to delete a node 
    int ans=-1;
    if(index>0 &&index<size){ //checking if the index is valid or not
        if(head==0)  //if there is no node just return -1
            return ans;
        else
        {
            node *t=head;
            if(index==1){//if the index is of the fist node than we have to delete the first node and our list start from next node
                ans = head->data;  
                while (t->next!=head) //traversing to last node which points to head
                    t=t->next;
                head=head->next;  //making next node of head as head and breaking the link of first node(previous head) from linked list
                t->next=head;  //pointing the last node towards the next of head
            }
            else{
                for (int i = 1; i < index-1; i++) //if index is not of first node than this conditon will work
                    t=t->next;  // going to node which is just before the index node
                ans=t->next->data; 
                t->next=t->next->next;//making the link to point to the next node of deleted node
            }
        }
    }
    else printf("index for deletion is out of range ");
    return ans;
}

void display(){
    node *temp=head;
    do{  //we use do while loop because we want to print until we hit head second time 
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("\n");
}

void recdisplay(node *temp){  //display using recursion 
    static int flag=0; /*A static variable retains its value between function calls, 
                        so it can be used to keep track of the number of times the function is called */
    if (temp!=head || flag==0) // to see that we only visit head one time and next time we visit it than end it 
    {
        flag=1;
        printf("%d ", temp->data);
        recdisplay(temp->next);
    }
    flag=0;  /*After the recursive call returns, the function sets flag to 0. This is done to reset the value of
              flag for the next call of the function, in case the function is called multiple times in the main program*/
}

void main(){
    create();
    node *temp=head;
    recdisplay(temp);
    insert(1,45);  // we can also take user input 
    printf("\n");
    display();
    int ans=delete(1); //we can also take user input
    printf("%d\n",ans);
    display();
}
