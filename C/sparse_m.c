#include<stdio.h>
#include<conio.h>

struct s_mat{
   int r;
   int c;
   int val;
};

int main(){
    int row,col,i,j;
    int mat[10][10];
    struct s_mat sparse[100];
    int size=0;
    printf("Enter rows: ");
    scanf("%d",&row);
    printf("Enter columns: ");
    scanf("%d",&col);
    printf("Enter elements: ");
    for(i=0; i < row; i++){
        for(j=0; j < col; j++){
            scanf("%d",&mat[i][j]);
            if(mat[i][j]!=0){
                sparse[size].r = i;
                sparse[size].c = j;
                sparse[size].val = mat[i][j];
                size++;
            }
        }
    }
    printf("Sparse Representation\n");
    printf("Row\t Column\t Value\n");
    for(i=0;i<size;i++){
        printf("%d\t %d\t %d\n",sparse[i].r,sparse[i].c,sparse[i].val);
    }
    return 0;
}