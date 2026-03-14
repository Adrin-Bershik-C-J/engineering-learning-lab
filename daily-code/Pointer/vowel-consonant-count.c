//Vowel consonant count 

#include<stdio.h>
#include<ctype.h>
void countVowelsConsonants(char *str,int *vowelCount,int *consonantCount);
int main(){
    char str[50];
    int vowelCount=0,consonantCount=0;
    printf("Enter the sentence:");
    scanf("%[^\n]s",str);
    countVowelsConsonants(str,&vowelCount,&consonantCount);
    printf("Vowels: %d\nConsonants: %d",vowelCount,consonantCount);
    return 0;
}
void countVowelsConsonants(char *str,int *vowelCount,int *consonantCount){
    while(*str){
        char ch=tolower(*str);
        if(isalpha(ch)){
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
                (*vowelCount)++;
            }else{
                (*consonantCount)++;
            }
        }
        str++;
    }
}