//Merge Two Sorted Linked Lists

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    int value;
    struct Node *next;
};
struct Node *createNode(struct Node *head,int val);
struct Node *mergeNodes(struct Node *head1,struct Node *head2);
void printNodes(struct Node *head);
int main(){
    char ch[3];
    struct Node *head=NULL,*head2=NULL;
    int val;
    printf("Linked list 1:\n");
    do{
        printf("Enter the node value:");
        scanf("%d",&val);
        head=createNode(head,val);
        printf("Do you want to add further nodes?(y/n):");
        scanf("%s",ch);
    }while(strcmp(ch,"y")==0);
    printf("The node values: ");
    printNodes(head);
    printf("\n");
    printf("Linked list 2:\n");
    do{
        printf("Enter the node value:");
        scanf("%d",&val);
        head2=createNode(head2,val);
        printf("Do you want to add further nodes?(y/n):");
        scanf("%s",ch);
    }while(strcmp(ch,"y")==0);
    printf("The node values: ");
    printNodes(head2);
    printf("\n");
    struct Node *final=mergeNodes(head,head2);
    printf("The final merged node:");
    printNodes(final);
    return 0;
}
struct Node *createNode(struct Node *head,int val){
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->value=val;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
        return head;
    }
    struct Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}
void printNodes(struct Node *head){
    struct Node *temp=head;
    while(temp){
        printf("%d ",temp->value);
        temp=temp->next;
    }
}
struct Node *mergeNodes(struct Node *head1,struct Node *head2){
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    if(head1->value<head2->value){
        head1->next=mergeNodes(head1->next,head2);
        return head1;
    }else{
        head2->next=mergeNodes(head1,head2->next);
        return head2;
    }
}