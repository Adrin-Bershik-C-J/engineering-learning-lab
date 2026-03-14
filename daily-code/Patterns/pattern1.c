//       1      
//      121     
//     12321    
//    1234321   
//   123454321  
//  12345654321 
// 1234567654321


#include<stdio.h>
int main(){
    int n,i,j,k,l;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        int num=1;
        for(j=1;j<=n+(n-1);j++){
            if(j>=n-(i-1)&&j<=n){
               printf("%d",num);
               num++;
            }else if(j>n&&j<=n+(i-1)){
                printf("%d",num-2);
                num--;
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
}