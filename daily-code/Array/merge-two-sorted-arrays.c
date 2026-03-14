//Merging Two Sorted Arrays

#include<stdio.h>
void mergeArray(int arr1[],int m,int arr2[],int n);
int main(){
    int m,n,i;
    printf("Enter size of array1:");
    scanf("%d",&m);
    printf("Enter size of array2:");
    scanf("%d",&n);
    int arr1[m],arr2[n];
    printf("Enter array1 elements:");
    for(i=0;i<m;i++){
        scanf("%d",&arr1[i]);
    }
    printf("Enter array2 elements:");
    for(i=0;i<n;i++){
        scanf("%d",&arr2[i]);
    }
    mergeArray(arr1,m,arr2,n);
    return 0;
}
void mergeArray(int arr1[],int m,int arr2[],int n){
    int merged[m+n];
    int i=0,j=0,k=0;
    while(i<m&&j<n){
        if(arr1[i]<=arr2[j]){
            merged[k++]=arr1[i++];
        }else{
            merged[k++]=arr2[j++];
        }
    }
    while(i<m){
        merged[k++]=arr1[i++];
    }
    while(j<n){
        merged[k++]=arr2[j++];
    }
    printf("The merged array: ");
    for(i=0;i<m+n;i++){
        printf("%d ",merged[i]);
    }
}