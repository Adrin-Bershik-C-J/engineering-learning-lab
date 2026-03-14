// Enter array size:3
// Enter array elements:
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9
// The rotated array:
// 7 4 1 
// 8 5 2 
// 9 6 3 


#include <stdio.h>
int main() {
   int n,i,j,temp;
   printf("Enter array size:");
   scanf("%d",&n);
   int arr[n][n];
   printf("Enter array elements:\n");
   for(i=0;i<n;i++){
       for(j=0;j<n;j++){
        scanf("%d",&arr[i][j]);
       }
   }
   for(i=0;i<n;i++){
       for(j=i+1;j<n;j++){
           temp=arr[i][j];
           arr[i][j]=arr[j][i];
           arr[j][i]=temp;
       }
   }
   for(i=0;i<n;i++){
       for(j=0;j<n/2;j++){
           temp=arr[i][j];
           arr[i][j]=arr[i][n-1-j];
           arr[i][n-1-j]=temp;
       }
   }
   printf("The rotated array:\n");
   for(i=0;i<n;i++){
       for(j=0;j<n;j++){
           printf("%d ",arr[i][j]);
       }
       printf("\n");
   }
}