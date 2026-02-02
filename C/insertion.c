#include<stdio.h>

void insertion_sort(int arr[],int n);

int main(){
    int n,i,arr[10];

    printf("Array size: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    insertion_sort(arr, n);

    printf("After Insertion sort: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void insertion_sort(int arr[],int n){
    int i,j,temp;
    for(i=0;i<n;i++){
        temp=arr[i];
        j=i-1;
        while(((j>=0) && temp<arr[j])){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}