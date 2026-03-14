//Reverse a Linked List (Iterative)

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct Node{
    int value;
    struct Node *right;
};

void printNodes(struct Node *head);
struct Node *appendNode(struct Node *head,int value);
struct Node *reverseNodes(struct Node *head);
    
int main(){
    
    int num;
    char ch[3];
    struct Node *head=NULL;
    
    do{

        printf("Enter the node value:");
        scanf("%d",&num);
        head=appendNode(head,num);
        printf("Do you want to add node further?(y)/(n):");
        scanf("%s",ch);

    }while(strcmp(ch,"y")==0);
    
    printf("The node values before getting reversed:");
    printNodes(head);
    printf("\n");
    
    head=reverseNodes(head);
    printf("The node values after getting reversed:");
    printNodes(head);
    
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

struct Node *reverseNodes(struct Node *head){
    struct Node *next,*curr,*prev;
    next=NULL;
    prev=NULL;
    curr=head;
    while(curr!=NULL){
        next=curr->right;
        curr->right=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}