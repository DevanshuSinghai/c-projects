#include<stdio.h>
#include<stdlib.h>
struct elements // structure for non zero elements of sparse array 
{
    int i,j,x; // i= row of any non-zero element , j=col of corresponding element , x= non-zero element
};
struct sparse // structure for sparse arrray 
{
    int m,n,num; // m= total row , n= total column , num= total number of non zero element
    struct elements *e;//an array in heap which store values of elements
};
void create(struct sparse *s){// funtion to create sparse array by user
    printf("\nenter dimensions ");
    scanf("%d %d",&s->m,&s->n);
    printf("enter total number of non-zero elements ");
    scanf("%d",&s->num);
    s->e=(struct elements *)malloc(s->num*sizeof(struct elements));// allocating memeory for sparse array in heap
    printf("enter elements along with row and column\n");
    for(int i=0;i<s->num;i++){
        scanf("%d %d %d",&s->e[i].x,&s->e[i].i,&s->e[i].j);//taking non-zero element and its row and col no. by user
    }
}
struct sparse * add(struct sparse *s1 , struct sparse *s2){//pointer fuction to add two sparse arrays
    if(s1->m!=s2->m||s2->n!=s1->n)//if there row or col do not match return zero i.e they can't be add 
        return 0;
    struct sparse *s3;//a pointer array to store added sparse array
    s3=(struct sparse *)malloc(sizeof(struct sparse));//allocating memory to sparse array
    s3->e=(struct elements *)malloc((s1->num+s2->num)*sizeof(struct elements));//allocating memeory to non-zero elements along with row and col in heap
    int i=0,j=0,k=0;//variables to keep check on both array, i= for s1, j= for s2, k= for s3
    s3->m=s1->m;s3->n=s1->n;
    while (i<s1->num&&j<s2->num)
    {
        if(s1->e[i].i<s2->e[j].i)//if ith index of both array not matched than increase the counter variable for s3 and the one which is smaller
            s3->e[k++]=s1->e[i++];
        else if(s1->e[i].i>s2->e[j].i)
            s3->e[k++]=s2->e[j++];
        else
        {
            if(s1->e[i].j<s2->e[j].j)
                s3->e[k++]=s1->e[i++];
            else if(s1->e[i].j>s2->e[j].j)
                s3->e[k++]=s2->e[j++];
            else //if all above conditon is false than we are confirmed that ith and jth index of both array are now same and we can now add them
            {
                s3->e[k]=s1->e[i];//copying all members of s1 or s2 to s3 because in this condition we match the row and col which are same in s1 and s2
                s3->e[k++].x=s1->e[i++].x+s2->e[j++].x;// storing the added value of s1 and s2 into s3 
            }
        }
    }
    for(;i<s1->num;i++)s3->e[k++]=s1->e[i];// if any element is left in s1 than storing it in s3
    for(;j<s2->num;j++)s3->e[k++]=s2->e[j];// if any element is left in s2 than storing it in s3
    s3->num=k;//now total non-zero element in s3 is equals to k ie numbers which are added + number which are not added
    return s3;
}
void display(struct sparse s){// funtion to display sparse matrix
    int k=0;
    for(int i=0;i<s.m;i++){
        for (int  j = 0; j < s.n; j++)
        {
            if(s.e[k].i==i && s.e[k].j==j)//if non-zeroth element index is found than print that element 
                printf(" %d",s.e[k++].x);
            else printf(" 0");//else print zero
        }
        printf("\n");
    }
}
void main(){
    struct sparse s1,s2,*s3;// pointer variable is for storing the added array
    printf("enter all details of first mat ");
    create(&s1);
    printf("enter all details of second mat ");
    create(&s2);
    printf("showing sparse elements of first matrix \n");
    display(s1);
    printf("\nshowing sparse elements of second matrix \n");
    display(s2);
    s3=add(&s1,&s2);
    if(s3==0)
        printf("cant add these arrays");
    else{
        printf("showing sparse elements of summed matrix \n");
        display(*s3);    
}
}
