// Swap two numbers

#include<stdio.h>
void swap(int *a,int *b);
int main(){
    int a,b;
    printf("Enter A value:");
    scanf("%d",&a);
    printf("Enter B value:");
    scanf("%d",&b);
    printf("Values before swap:\nA-%d\nB-%d\n",a,b);
    swap(&a,&b);
    printf("Values after swap:\nA-%d\nB-%d\n",a,b);
    return 0;
}
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}