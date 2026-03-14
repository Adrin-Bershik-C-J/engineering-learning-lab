//Delete a Node by Value

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct Node{
    int value;
    struct Node *right;
};

void printNodes(struct Node *head);
struct Node *appendNode(struct Node *head,int value);
struct Node *deleteNode(struct Node *head,int n);
    
int main(){
    
    int num,n;
    char ch[3];
    struct Node *head=NULL;
    
    do{

        printf("Enter the node value:");
        scanf("%d",&num);
        head=appendNode(head,num);
        printf("Do you want to add node further?(y)/(n):");
        scanf("%s",ch);

    }while(strcmp(ch,"y")==0);
    
    printf("The node values before getting deleted:");
    printNodes(head);
    printf("\n");
    
    printf("Enter the value to be deleted:");
    scanf("%d",&n);
    head=deleteNode(head,n);
    
    printf("The node values after deleting the said value:");
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

struct Node *deleteNode(struct Node *head,int number){
    struct Node *temp=head;
    struct Node *prev=NULL;
    if(temp!=NULL&&temp->right==NULL&&temp->value==number){
        free(head);
        return NULL;
    }
    while(temp!=NULL){
        if(temp->value==number){
            if(temp->right==NULL&&prev!=NULL){
                prev->right=NULL;
                free(temp);
                return head;
            }
            if(prev!=NULL&&temp->right!=NULL){
                prev->right=temp->right;
                //free(temp).
                return head;
            }
            if(prev==NULL){
                head=temp->right;
                //free(temp);
                return head;
            }
        }
        prev=temp;
        temp=temp->right;
    }
}