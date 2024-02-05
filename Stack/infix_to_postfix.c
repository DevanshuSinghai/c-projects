/*This code can convert any infix expression to postfix expression,here i had defined only limited
operators but you can add according to your requirements you just had to give the outside stack precendence 
and inside stack precedence, for L-R associativity  outside precedence should be greater than inside precedence and 
vice versa for R-L associativity    
To add more symbols you just add the symbols and their precedence in the function "ischar" , "outprece",
and "inprece" */

#include<stdio.h>
#include<stdlib.h>
#include<string.h> //importing to find length of expression  

typedef struct node  // defining structure node for linked list which we use to implement stack
{
    char data;
    struct node *next;
}node;
node *top=NULL; //initialising top = null 
int j=0; //variable to count length because we dont wanna print brackets so we exclude them

void push(char ch){  //funtion to push elements
    node *temp=(node *)malloc(sizeof(node));  // allocating memeory in heap to every new node formed
    if(!temp){
        printf("heap is full ");
    }
    temp->data=ch; //storing data into new node
    temp->next=top; //passing the address of top into newnode
    top=temp; // and then bringing top to new node
}
char pop(){  // funtion to pop elements from stack
    if(top==NULL)  
        return 0;
    char c;
    c=top->data;  // storing data of top into some variable
    top=top->next;  // now bringing top to next node 
    return c;
}
int isoptr(char ch){   // function to check if the character is an operator or not
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'||ch=='('||ch==')')
        return 1;
    return 0; 
}
int outprec(char ch){  // funtion to define the out precedence of each operator and returning the one we want 
    if(ch=='+'||ch=='-')
        return 1;
    if(ch=='*'||ch=='/')
        return 3;
    if(ch=='^')
        return 6;
    if(ch=='(')
        return 7;
    if(ch==')')
        return 0;
}
int inprec(char ch){   // funtion to define inside precedence of each operator and returning th one want 
    if(ch=='+'||ch=='-')
        return 2;
    if(ch=='*'||ch=='/')
        return 4;
    if(ch=='^')
        return 5;
    if(ch=='(')
        return 0;
    return -1;  //we returning -1 because at beginning we push a garbage element to prevent the segmentation fault exception
}
char * inf_to_post(char *ch){  //funtion to convert infix to postfix expression
    char *postfix=(char *)malloc(sizeof(strlen(ch))+1);  //allocating memeory to array in which we store postfix exp
    int i=0;
    while (ch[i]!='\0') //loop to traverse the exp until we hit EOL character
    {
        if(!isoptr(ch[i]))  //if the char at i is not a operator(that we define) than add it to postfix array
            postfix[j++]=ch[i++];
        else{
            if(outprec(ch[i])<=inprec(top->data)){  //checking the precedence of operator
                if(ch[i]==')'){ // if the operator is ')' than we have to pop elements in stack until we get '(' this bracket i.e we want the closing bracket
                    while (top->data!='(')
                    {
                        postfix[j++]=pop();
                        i++;
                    }
                    pop(); //we pop here because the above while loop pops out element until we hit '(' but no the bracket itself
                    if(top==NULL) // if the stack is null i.e we did not find the closing brakcets 
                        continue;
                }
                else postfix[j++]=pop(); //if char at i is not ')' than just add the element in postfix
            }
            else push(ch[i++]); // if the precedence condtion is false than add the symbol to stack
        }
    }
    while (top!=NULL)  // if the stack is not empty than pop and add all the remaining element to postfix
    {
        char poped=pop();
        if(poped=='(')  // we do not want to print brackets so we just continue without adding that
            continue;
        postfix[j++]=poped;
    }
    //postfix[j]='\0'; we can add this line but no need as of now 
    return postfix;
}
void main(){
    char *ch="((a+b)*c)-d^e^f"; 
    push('@'); // pushing the first element in stack, as mentioned earlier to prevent segmentation exception
    char *ans=(char *)malloc(sizeof(strlen(ch)*sizeof(char)+1)); // defining a pointer variable to store the address of first element of postfix expression
    ans=inf_to_post(ch);
    for (int i = 0; i < j-1; i++)  // printing all expr. of postfix
    {
        printf("%c",ans[i]);
    }
}
