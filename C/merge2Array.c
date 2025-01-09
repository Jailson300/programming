#include<stdio.h>
void merge(int arr1[],int arr2[],int size1,int size2, int arr3[]){
    int i=0, j=0, k=0;

    while (i < size1 && j < size2)
    {
        if(arr1[i] < arr2[j]){
            arr3[k++] = arr1[i++];
        }
        else{
            arr3[k++] = arr2[j++];
        }
    }
    
    while(i < size1){
        arr3[k++] = arr1[i++];
    }

    while(j < size2){
        arr3[k++] = arr2[j++];
    }
    
}

int main(){
    int size1 ,size2,i,temp=0;
    printf("Enter the size of the first array: ");
    scanf("%d",&size1);

    int arr1[size1];
    printf("Enter the elements of the first array: ");
    for(i=0; i<size1; i++ ){
        scanf("%d",&arr1[i]);
    }

    printf("Enter the size of the second array: ");
    scanf("%d",&size2);

    int arr2[size2];
    printf("Enter the elements of the second array: ");
    for(i = 0; i< size2; i++){
        scanf("%d",&arr2[i]);
    }

    int arr3[size1 + size2];
    merge(arr1,arr2,size1,size2,arr3);

    for(i=0; i < size1+size2; i++){
        if(arr3[i+1] < arr3[i]){
          temp = arr3[i+1];
          arr3[i+1] =  arr3[i];
          arr3[i] = temp;
        }
    }

    printf("\nAfter merging\n");
    for(i=0;i< size1+size2; i++){
        printf(" %d ",arr3[i]);
    }

    return 0;
}
