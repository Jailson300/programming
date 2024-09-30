#include<stdio.h>
#include<stdlib.h>
void create(int);
void begdelete();
void traverse();

struct node
{
int data;
struct node *next;
};

struct node *head;
int main ()
{
  int choice,item;
   do
   {
     printf("\n1.Append List\n2.Traverse\n3.Delete\n4.Exit\n5.Enter your choice: ");
     scanf("%d",&choice);
     switch(choice)
      {
        case 1:
        printf("\nEnter the item\n");
        scanf("%d",&item);
        create(item);
        break;

        case 2:
        traverse();
        break;

        case 3:
        begdelete();
        break;

        case 4:
        exit(0);
        break;
        default:
        printf("\nPlease enter valid choice\n");
      }
    }while(choice != 4);
}

void create(int item)
{
  struct node *ptr = (struct node *)malloc(sizeof(struct node *));
    if(ptr == NULL)
    {
    printf("\nOVERFLOW\n");
    }
    else
    {
    ptr->data = item;
    ptr->next = head;
    head = ptr;
    printf("\nNode inserted\n");
    }
}

void begdelete(){
    struct node *ptr;
    if(head==NULL){
        printf("\nList is empty");
    }
    else{
        ptr=head;
        head=ptr->next;
        free(ptr);
        printf("\n Node deleted from the begining");
    }
}

void traverse()
{
  struct node *ptr;
  ptr = head;
  if(ptr == NULL)
  {
  printf("Empty list..");
  }
  else
  {
    printf("printing values ........ \n");
    while (ptr!=NULL)
    {
     printf("\n%d",ptr->data);
     ptr = ptr -> next;
    }
  }
}