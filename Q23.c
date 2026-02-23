
/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.*/

//Merge Two Sorted Linked Lists

#include<stdio.h>
#include<stdlib.h>

int count1=0, count2=0;      //Count for both lists

struct node
{
    int no;
    struct node *next;
}*new, *first1=NULL, *first2=NULL, *first3=NULL, *ptr1, *ptr2, *ptr3;


// Create First List
void create_list1()
{
    int n;
    printf("Enter number of elements in First List: ");
    scanf("%d",&n);
    count1=n;

    for(int i=1;i<=n;i++)
    {
        new=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&new->no);
        new->next=NULL;

        if(first1==NULL) first1=new;
        else
        {
            for(ptr1=first1; ptr1->next!=NULL; ptr1=ptr1->next);
            ptr1->next=new;
        }
    }
}

// Create Second List
void create_list2()
{
    int m;
    printf("Enter number of elements in Second List: ");
    scanf("%d",&m);
    count2=m;

    for(int i=1;i<=m;i++)
    {
        new=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&new->no);
        new->next=NULL;

        if(first2==NULL) first2=new;
        else
        {
            for(ptr2=first2; ptr2->next!=NULL; ptr2=ptr2->next);
            ptr2->next=new;
        }
    }
}

// Merge Lists
void merge_list()
{
    ptr1=first1;
    ptr2=first2;

    while(ptr1!=NULL && ptr2!=NULL)
    {
        new=(struct node*)malloc(sizeof(struct node));
        new->next=NULL;

        if(ptr1->no <= ptr2->no)
        {
            new->no=ptr1->no;
            ptr1=ptr1->next;
        }
        else
        {
            new->no=ptr2->no;
            ptr2=ptr2->next;
        }

        if(first3==NULL) first3=new;
        else
        {
            for(ptr3=first3; ptr3->next!=NULL; ptr3=ptr3->next);
            ptr3->next=new;
        }
    }

    // Remaining elements of first list
    while(ptr1!=NULL)
    {
        new=(struct node*)malloc(sizeof(struct node));
        new->no=ptr1->no;
        new->next=NULL;

        if(first3==NULL) first3=new;
        else
        {
            for(ptr3=first3; ptr3->next!=NULL; ptr3=ptr3->next);
            ptr3->next=new;
        }
        ptr1=ptr1->next;
    }

    // Remaining elements of second list
    while(ptr2!=NULL)
    {
        new=(struct node*)malloc(sizeof(struct node));
        new->no=ptr2->no;
        new->next=NULL;

        if(first3==NULL) first3=new;
        else
        {
            for(ptr3=first3; ptr3->next!=NULL; ptr3=ptr3->next);
            ptr3->next=new;
        }
        ptr2=ptr2->next;
    }
}

// Display Merged List
void display()
{
    for(ptr3=first3; ptr3!=NULL; ptr3=ptr3->next)
        printf("%d ", ptr3->no);
}

int main()
{
    create_list1();
    create_list2();
    merge_list();
    display();
    return 0;
}