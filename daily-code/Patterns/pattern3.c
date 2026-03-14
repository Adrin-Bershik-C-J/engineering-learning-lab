// 1
// 12
// 123
// 1234
// 12345

#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int i,j,k;
    for(i=1;i<=n;i++){
        for(j=1;j<=n-i;j++){
            printf(" ");
        }
        for(k=1;k<=i;k++){
            printf("%d",k);
        }
        printf("\n");
    }
}