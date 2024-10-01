#include<stdio.h>
#include<stdlib.h>
void create(int);
void enddelete();
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
        enddelete();
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
  struct node *ptr = (struct node *)malloc(sizeof(struct node));
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

void enddelete(){
    struct node *ptr,*ptr1;
    if(head==NULL){
        printf("\nList is empty");
    }
    else if(head->next==NULL){
        head=NULL;
        free(head);
        printf("Only node of the list is deleted..");
    }
    else{
        ptr=head;
        while(ptr->next != NULL){
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next=NULL;
        free(ptr);
        printf("\n Deleted from the Last");
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
     printf("\t%d",ptr->data);
     ptr = ptr -> next;
    }
    printf("\n");
  }
}