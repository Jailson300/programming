#include<stdio.h>

int main(){
    int n,i,j,temp=0,arr[10]={39,9,81,15,45,90,27,72,18};

    n = 9;

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }

    for ( i = 0; i < n; i++)
    {
        printf(" %d",arr[i]);
    }
    
    return 0;
}