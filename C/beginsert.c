#include<stdio.h>
#include<stdlib.h>

void beginsert(int item);

struct node{
    int data;
    struct node* next;
};

struct node *head=NULL;

int main(){
    int choice,item;
    do{
        printf("Enter item to be inserted: ");
        scanf("%d",&item);
        beginsert(item);
        printf("\n Press 0 to insert more items : ");
        scanf("%d",&choice);
    }
    while(choice==0);
    return 0;
}

void beginsert(int item){
    struct node* ptr = (struct node*)malloc(sizeof(struct node*));
    if(ptr==NULL){
        printf("\n OVERFLOW \n");
    }
    else{
        ptr->data=item;
        ptr->next=head;
        head=ptr;
        printf("\n Node Inserted \n");
    }
}