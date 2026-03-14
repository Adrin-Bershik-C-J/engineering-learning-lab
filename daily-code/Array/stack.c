// Stack implementation using array
// Enter your choice:
// 1.Push
// 2.Pop
// 3.Peep
// 4.Exit


#include<stdio.h>
#define SIZE 5
int stack[SIZE],top=-1;
void push();
void pop();
void peep();
int main(){
    int choice;
    do{
        printf("Enter your choice:\n1.Push\n2.Pop\n3.Peep\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            peep();
            break;
            default:
            printf("Enter a proper input\n");
        }
    }while(choice!=4);
}
void push(){
    if(top==SIZE-1){
        printf("Stack overflow!\n");
        return;
    }
    int value;
    printf("Enter the value:");
    scanf("%d",&value);
    
    stack[++top]=value;
}
void pop(){
    if(top==-1){
        printf("Stack underflow!\n");
        return;
    }
    stack[top--];
}
void peep(){
    if(top==-1){
        printf("Nothing to show...\n");
        return;
    }
    printf("%d\n",stack[top]);
}