#include<stdio.h>
#include<string.h>
#include<ctype.h>
void reverseWords(char *str);
void reverse(char *str,int begin,int end);
int main(){
    char ch[20];
    printf("Enter any sentence:");
    scanf("%[^\n]s",ch);
    reverseWords(ch);
    printf("Reversed string:%s",ch);
    return 0;
}
void reverseWords(char *str){
    int len=strlen(str);
    reverse(str,0,len-1);
    int i,start=0;
    for(i=0;i<=len;i++){
        if(isspace(str[i])||str[i]=='\0'){
            reverse(str,start,i-1);
            start=i+1;
        }
    }
}
void reverse(char *str,int begin,int end){
    while(begin<end){
        char temp=str[begin];
        str[begin]=str[end];
        str[end]=temp;
        begin++;
        end--;
    }
}
