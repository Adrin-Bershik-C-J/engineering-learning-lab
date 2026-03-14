#include<stdio.h>
#include<stdlib.h>

struct Node{
    int value;
    struct Node *right;
};

struct Node *createNode(struct Node *,int);
void printNodes(struct Node *head);
int isPalindrome(struct Node *head);
struct Node *reverse(struct Node *head);
struct Node *createCopy(struct Node *head);

int main(){
    struct Node *head=NULL;
    int num;
    char ch;
    do{
        printf("Enter the node value:");
        scanf("%d",&num);
        head=createNode(head,num);
        printf("Do you want to continue adding nodes(y/n):");
        scanf(" %c",&ch);
    }while(ch=='y');
    printf("The node values:");
    printNodes(head);
    printf("\n");
    int ans=isPalindrome(head);
    if(ans){
        printf("It is palindromic");
    }else{
        printf("It isn't palindromic");
    }
    return 0;
}
struct Node *createNode(struct Node *head,int value){
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
struct Node *reverse(struct Node *head){
    struct Node *prev=NULL,*curr,*next=NULL;
    curr=head;
    while(curr!=NULL){
        next=curr->right;
        curr->right=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
struct Node *createCopy(struct Node *head){
    struct Node *temp=head;
    struct Node *newHead=NULL;
    struct Node *tail=NULL;
    while(temp!=NULL){
        struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
        newNode->value=temp->value;
        newNode->right=NULL;
        if(newHead==NULL){
            newHead=tail=newNode;
        }else{
            tail=newNode;
            tail->right=newNode;
        }
        temp=temp->right;
    }
    return newHead;
}
int isPalindrome(struct Node *head){
    struct Node *temp1=createCopy(head);
    struct Node *temp2=reverse(head);
    while(temp1!=NULL){
        if(temp1->value!=temp2->value){
            return 0;
        }
        temp1=temp1->right;
        temp2=temp2->right;
    }
    return 1;
}
