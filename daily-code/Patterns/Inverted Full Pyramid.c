// Enter the number of rows:5
// 1 2 3 4 5 6 7 8 9 
//   1 2 3 4 5 6 7   
//     1 2 3 4 5     
//       1 2 3       
//         1         

#include<stdio.h>
int main(){
    int n;
    printf("Enter the number of rows:");
    scanf("%d",&n);
    int i,j,k;
    for(i=n;i>=1;i--){
        int count=1;
        for(j=1;j<=2*n-1;j++){
            if(j>=n-i+1&&j<=n+i-1){
                printf("%d ",count);
                count++;
            }else{
                printf("  ");
            }
        }
        printf("\n");
    }
}