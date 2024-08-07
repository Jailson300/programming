#include<stdio.h>
#include<conio.h>

int main(){
    int n ,sum=0, myNumbers[] = {};
    float mean = 0;

    printf("Enter size of array: %d");
    scanf("%d",&n);

    for(int i=0;i < n ;i++){
        scanf("%d",&myNumbers[i]);     
    }

    return 0;

}