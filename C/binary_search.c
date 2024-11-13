#include<stdio.h>

int main(){
    int n,i,first,last,search,mid;
    printf("Enter the array size: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Search: ");
    scanf("%d",&search);
    first=0;
    last= n-1;
    while(first <= last){
        mid=(first + last)/2;
        if(arr[mid]<search){
          first = mid+1;
        }
        else if(arr[mid]==search){
            printf("Number found at %d position",mid+1);
            return 0;
        }
        else{
            last = mid-1;
        }
    }
    printf("Not Found");
    return 0;
}