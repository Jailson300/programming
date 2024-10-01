#include<stdio.h>
#include<stdlib.h>

void create(int);
void spec_delete();
void traverse();

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

int main()
{
    int item, choice;

    // Taking user input to create nodes
    do {
        printf("Enter the value to insert in the list: ");
        scanf("%d", &item);
        create(item);

        printf("Do you want to insert another value? (1 for Yes / 0 for No): ");
        scanf("%d", &choice);
    } while (choice != 0);

    printf("\nList after creation:\n");
    traverse(); // Traverse and display the list

    // Delete the last node
    spec_delete();

    printf("\nList after deletion of last node:\n");
    traverse(); // Traverse and display the list again

    return 0;
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
        printf("\nNode inserted with value %d\n", item);
    }
}

void spec_delete()
{
    struct node *ptr, *ptr1;
    int loc,i;
    printf("Enter the specified node: ");
    scanf("%d",&loc);
    ptr=head;
    for(i=0;i<loc;i++){
        ptr1=ptr;
        ptr = ptr->next;

        if(ptr==NULL){
            printf("There are less than %d elements in the list..\n",loc);
            return;
        }
    }
        ptr1->next = ptr->next ;
        free(ptr);
        printf("\nDeleted node from the end\n");
}

void traverse()
{
    struct node *ptr = head;
    if(ptr == NULL)
    {
        printf("Empty list..\n");
    }
    else
    {
        printf("Printing values ........\n");
        while(ptr != NULL)
        {
            printf("\t%d", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}
