//Reverse an Array Using Pointer

#include<stdio.h>
#include<stdlib.h>
void reverse(int *arr,int n);
int main(){
    int n,i;
    printf("Enter array size:");
    scanf("%d",&n);
    int *arr=(int *)malloc(n*sizeof(int));
    printf("Enter array elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    reverse(arr,n);
    printf("Array elements after swap:\n");
    for(i=0;i<n;i++){
        printf("%d ",*(arr+i));
    }
    return 0;
}
void reverse(int *arr,int n){
    int i=0,j=n-1;
    while(i<j){
        int temp=*(arr+i);
        *(arr+i)=*(arr+j);
        *(arr+j)=temp;
        i++;
        j--;
    }
}