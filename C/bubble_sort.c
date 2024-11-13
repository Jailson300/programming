#include<stdio.h>

int main(){
    int i,n,temp,j,arr[10];
    printf("Array size : ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(i=0 ; i<n; i++){
        scanf("%d",&arr[i]);
    }

    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[i]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("After Bubble sort");
    for(i=0; i<n ; i++){
        printf(" %d ",arr[i]);
    }
    printf("\n");
    return 0;
}