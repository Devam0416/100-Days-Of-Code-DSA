
/*Problem: Create and Traverse Singly Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50*/

#include<stdio.h>
#include<stdlib.h>

int count=0;                 //To count no. of nodes in list

struct node                  //Define structure of node
{
    int no;                  //data element
    struct node *next;       //self referential pointer
}*new, *first=NULL, *ptr;

void create_list()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    count = n;

    for(int i=1; i<=n; i++)
    {
        new = (struct node*)malloc(sizeof(struct node));   //DMA
        printf("Enter data: ");
        scanf("%d", &new->no);

        new->next = NULL;

        if(first==NULL)
            first = new;        //Head node
        else
        {
            for(ptr=first; ptr->next!=NULL; ptr=ptr->next);
            ptr->next = new;    //Link nodes
        }
    }
}

void display()
{
    if(first==NULL)
        printf("List is Empty\n");
    else
    {
        printf("\nElements in the List are:\n");
        for(ptr=first; ptr!=NULL; ptr=ptr->next)
            printf("%d ", ptr->no);
    }
}

int main()
{
    create_list();
    display();
    return 0;
}