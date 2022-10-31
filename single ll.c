//linked list
#include <stdio.h>
#include<stdlib.h>

struct node{
	int info;
	struct node *link;
};

struct node* head = NULL;

void insert_beg(int val)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node*));
	if(temp == NULL)
	{
		printf("unable to allocate : ERROR ");
		exit(0);
	}
	temp->info = val;
	if(head == NULL)
	temp->link = NULL;
	if(head!=NULL)
		temp->link=head;
	head = temp;
	return;
}
void insert_end(struct node **head,int val)
{
	struct node *temp, *newnode;
	newnode = (struct node*)malloc(sizeof(struct node*));
	newnode->info=val;
	newnode->link=NULL;
	if(*head==NULL)
	{
		*head=newnode;
		return;
	}
	temp=*head;
	while(temp->link!=NULL)
	{
		temp=temp->link; //shifting till temp->link=null
	}
	temp->link=newnode; // assigning new value one by one to newnode
}

void insert_any(int val)
{
	struct node *temp;
	struct node *next;
	next= (struct node*)malloc(sizeof(struct node*));
	int i=1,num;
	printf("enter data : ");
	scanf("%d",&num);
	temp=head;
	next->info=num;
//	next->link=NULL;
	while(i<val-1)      //if taking 3, then node address of 2 taking here,
	{
		temp=temp->link;
		i++;
	}
	if(val==1 && head!=NULL)
	{
		next->link=head;
		head=next;
	}
	if(val==1 && head==NULL)
	{
		next->link=NULL;
		head=next;
	}	
	if(val!=1)
	{
		next->link=temp->link;
		temp->link=next;		
	}
	return ;
}

void display()
{
	struct node *ptr = head;
	if(head==NULL)
			printf("Linked list is empty. ");
	else
	{
		printf("Linked list is: ");	
		while(ptr!=NULL)
		{
			printf(" %d-->",ptr->info);
			ptr = ptr->link;
		}				
	}			
}

void deletion_beg()
{
	struct node *ptr;
	if(head==NULL)
			printf("Linked list is empty. Hence nothing to delete. ");
	else
	{
	ptr=head->link;
	free(head);
	head=ptr;
	}			
}

void deletion_end()
{
	struct node *temp;
	struct node *ptr;
	if(head==NULL)
	{
		printf("Linked list is empty. Hence nothing to delete.\n");
		return;
	}
	temp = head;
	ptr = temp->link;
	//ptr=head;
    while (ptr->link!= NULL) 
    {
        temp=ptr;
        ptr=ptr->link;
        //temp = temp->link; 
    }
    temp->link = NULL;
    free(ptr);
    //free(temp);
}
void delete_at_value(struct node **head, int value)
{
    struct node *temp1 = *head;
    struct node *temp2 = *head;
    if(*head == NULL)
    {
        printf("Linked List is Empty\n");
        return;
    }
    if(temp1->info == value)
    {
        *head = temp1->link;
        free(temp1);
        return;
    }
    while(temp1->info != value)
    {
        temp2 = temp1;
        temp1 = temp1->link;
    }
    temp2->link = temp1->link;
    free(temp1);
}

int menu()
    {
        int choice;
        printf("1. insertion at beginning. \n");
        printf("2. insertion at end. \n");
        printf("3. insert_any_position. \n");
        printf("4. deletion from beg. \n");
        printf("5. deletion from end. \n");
        printf("6. delete_any_position. \n");
        printf("7. display.\n");
        printf("8. exit.\n");
        printf("Enter your choice : \n");
        scanf("%d",&choice);
        return choice;
    }

int main()
    {
        int choice,data,number;
        while(1)
            {
                choice=menu();
                switch(choice)
				{
                case 1:
                    printf("enter the data : ");
                    scanf("%d",&data);
                    insert_beg(data);
                    break;
                case 2:
				    printf("enter the data : ");
                    scanf("%d",&data);
                    insert_end(&head,data);
                    break;
                case 3:
                	printf("insert position want to add new element : ");
                	scanf("%d",&data);
                	insert_any(data);
                	break;
                	deletion_beg();
                	break;
                case 4:
					deletion_beg();
                	break;
                case 5:
                	deletion_end();
                	break;
                case 6:
                    printf("Enter Your Value want to delete\n");
                    scanf("%d",&data);
                    delete_at_value(&head,data);
                    break;
                case 7:
                    display();
                    printf("\n");
                    break;
                case 8:
                    exit(1);
                default:
                    printf("wrong choice!!!");
            }
        }
    return 0;
    }
