#include<stdio.h>

int main(){
    int i,j,sum=0,arr[5][3];
    printf("Enter price: ");
    for(i=0;i<5;i++){
        printf("Sales %d: ",i+1);
        for (j= 0; j < 3; j++)
        {
            scanf("%d",&arr[i][j]);
        }   
    }

    for(i=0;i<5;i++){
       sum=0;
       for (j = 0; j < 3; j++)
       {
        sum= sum+ arr[i][j];
       }
       printf("sales by salesman %d: %d\n",i+1,sum);
    }

    for(j=0;j<3;j++){
        sum=0;
        for(i=0;i<5;i++){
            sum = sum + arr[i][j];
        }
        printf("sales of item %d: %d \n",j,sum);
    }

    return 0;
}