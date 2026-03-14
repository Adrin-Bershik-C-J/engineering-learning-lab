// Enter the parenthesis string:()(())
// Satisfied parenthesis!

#include<stdio.h>
#include<string.h>
#define SIZE 100
int main(){
    printf("Enter the parenthesis string:");
    char str[SIZE];
    scanf("%s",str);
    int i=0,top=-1,arr[SIZE];
    while(i<strlen(str)){
        if(str[i]!='('&&str[i]!=')'){
            printf("Sorry! It's an invalid input!");
            return 0;
        }
        i++;
    }
    for(i=0;i<strlen(str);i++){
        if(str[i]=='('){
            arr[++top]=str[i];
        }else{
            if(arr[top]=='('){
                top--;
            }else{
                printf("Parenthesis unsatisfied!");
                return 0;
            }
        }
    }
    if(top>-1){
        printf("Parenthesis unsatisfied!");
    }else
        printf("Satisfied parenthesis!");
}