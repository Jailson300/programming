#include<stdio.h>

int main(){
int n,i,num,found=0,pos=-1;
printf("Enter array size: ");
scanf("%d",&n);
int arr[n];
printf("Enter elements: ");
for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
printf("Number to search: ");
scanf("%d",&num);
for(i=0;i<n;i++){
    if(arr[i]==num){
        found = 1;
        pos= i+1;
        printf("%d is found in position %d",num,pos);
        break;
    }
 }
 if(found==0){
    printf("value is not found");
   }
 return 0;
}
