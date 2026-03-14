//Find the Nth Node from the End (Two-Pointer Method)

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct Node{
    int value;
    struct Node *right;
};

void printNodes(struct Node *head);
struct Node *appendNode(struct Node *head,int value);
void printNthFromEnd(struct Node *head,int num);
    
int main(){
    
    int num,find;
    char ch[3];
    struct Node *head=NULL;
    
    do{

        printf("Enter the node value:");
        scanf("%d",&num);
        head=appendNode(head,num);
        printf("Do you want to add node further?(y)/(n):");
        scanf("%s",ch);

    }while(strcmp(ch,"y")==0);
    
    printf("The node values:");
    printNodes(head);
    printf("\n");
    
    printf("Enter the node whose value should be print from the end:");
    scanf("%d",&find);
    
    printNthFromEnd(head,find);
    
    return 0;
}

struct Node *appendNode(struct Node *head,int value){
    
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->value=value;
    newNode->right=NULL;
    
    if(head==NULL){
        head=newNode;
        return head;
    }
    
    struct Node *temp=head;
    
    while(temp->right!=NULL){
        temp=temp->right;
    }
    
    temp->right=newNode;
    return head;
}

void printNodes(struct Node *head){
    
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->value);
        temp=temp->right;
    }
    
}

void printNthFromEnd(struct Node *head,int value){
    struct Node *first=head,*second=head;
    int i;
    for(i=0;i<value;i++){
        if(first==NULL){
            printf("Index out of range!\n");
            return;
        }
        first=first->right;
    }
    while(first){
        first=first->right;
        second=second->right;
    }
    printf("The value of the %d node from the end is %d",value,second->value);
}