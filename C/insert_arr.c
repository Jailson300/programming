#include<stdio.h>
#include<conio.h>

int main(){
    int i,j,n,num,arr[10],arr_len;
    printf("Array size: ");
    scanf("%d",&n);
    printf("Enter the element: ");
    for(i=0;i<n;i++){
       printf("arr[%d] : ",i);
       scanf("%d",&arr[i]);
    }
    printf("Enter the element to insert : ");
    scanf("%d",&num);
    for(i=0;i<n;i++){
        if(arr[i]>num){
            for(j=n-1;j>=i;j--){
                arr[j+1]=arr[j];
            }
            arr[i]=num;
            break;
        }
    }
    n = n + 1;
    printf("The inserted elememnt is : %d\n ",num);
    for(i=0;i<n;i++){
        printf("arr[%d] = %d\n",i,arr[i]);
    }

    return 0;

}