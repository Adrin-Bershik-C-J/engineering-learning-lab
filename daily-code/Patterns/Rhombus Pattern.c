// Enter the number of rows:5
//         1 2 3 4 5 
//       1 2 3 4 5 
//     1 2 3 4 5 
//   1 2 3 4 5 
// 1 2 3 4 5 

#include<stdio.h>
int main(){
    int n;
    printf("Enter the number of rows:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            printf("  ");
        }
        for(int j=1;j<=n;j++){
            printf("%d ",j);
        }
        printf("\n");
    }
    
}