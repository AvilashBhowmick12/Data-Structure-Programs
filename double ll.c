#include<stdio.h>
#include<stdlib.h>

typedef struct NODE{
    struct NODE *prev;
    int data;
    struct NODE *next;
}node;

//prototype
void insert_at_end(node **,int);
int menu();
node *create_node(int);
void display(node *);
void insert_at_beg(node **, int);
void insert_at_pos(node **,int, int);
void add_after_data(node **,int , int);
int del_at_beg(node **);
int del_at_end(node **);
int del_at_pos(node **,int);
int del_data(node **,int);

int main()
    {
        node *head=NULL;
        int data,choice,pos;
        while(1)
            {
                choice=menu();
                switch(choice)
                    {
                        case 1:
                            printf("Enter the data:  ");
                            scanf("%d",&data);
                            insert_at_end(&head,data);
                            break;
                        case 2:
                            printf("Enter the data:  ");
                            scanf("%d",&data);
                            insert_at_beg(&head,data);
                            break;
                        case 3:
                            printf("Enter the position: ");
                            scanf("%d",&pos);
                            printf("Enter the data: ");
                            scanf("%d",&data);
                            insert_at_pos(&head,data,pos);
                            break;
                        case 4:
                            printf("Enter the data after u want to insert: ");
                            scanf("%d",&pos);
                            printf("Enter the data: ");
                            scanf("%d",&data);
                            add_after_data(&head,data,pos);
                            break;
                        case 5:
                            data=del_at_beg(&head);
                            if(data!=-1)
                                printf("Deleted data is : %d\n",data);
                            break;
                        case 6:
                            data=del_at_end(&head);
                            if(data!=-1)
                                printf("Deleted data is : %d\n",data);
                            break;
                        case 7:
                            printf("Enter your index no: ");
                            scanf("%d",&pos);
                            data=del_at_pos(&head,pos);
                            if(data!=-1)
                                printf("Deleted data is : %d\n",data);
                            break;
                        case 8:
                            printf("Enter your data which u want to delete: ");
                            scanf("%d",&pos);
                            data=del_data(&head,pos);
                            printf("Deleted data is : %d\n",data);
                            break;
                        case 9:
                            display(head);
                            break;
                        case 10:
                            exit(1);
                        default:
                            printf("wrong choice!!!!");
                    }
            }
        return 0;
    }
    
int menu()
    {
        int choice;
        printf("MENU \n");
        printf("1. Insert at End.\n");
        printf("2. Insert at Beg.\n");
        printf("3. Insert at any position.\n");
        printf("4. Insert after data.\n");
        printf("5. Deletion from Beg.\n");
        printf("6. Deletion from End.\n");
        printf("7. Deletion from any position.\n");
        printf("8. Deletion the data which u want.\n");
        printf("9. Print.\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        return choice;
    }
    
node *create_node(int data)
    {
        node *temp=malloc(sizeof(node));
        temp->prev=NULL;
        temp->data=data;
        temp->next=NULL;
        return temp;
    }
        
void insert_at_end(node **head,int data)
    {
        node *ptr;
        node *newnode;
        newnode=create_node(data);
        if(*head==NULL)
            {
                *head=create_node(data);
                return;
            }
        ptr=*head;
        while(ptr->next != NULL)
            ptr=ptr->next;
        ptr->next=newnode;
        newnode->prev=ptr;
    }

void display(node *head)
    {
        node *trav1=head;
        node *trav2=NULL;
        if(head==NULL)
            {
                printf("linked List is empty.\n");
                return;
            }
        while(trav1 != NULL)
            {
                trav2=trav1;
                printf("%d ",trav1->data);
                trav1=trav1->next;
            }
        printf("<--- original sequence ");
        printf("\n");
        while(trav2 != NULL)
            {
                printf("%d ",trav2->data);
                trav2=trav2->prev;
            }
        printf("<--- reverse sequence ");
        printf("\n");
    }

void insert_at_beg(node **head, int data)
    {
        node *newnode;
        if(*head==NULL)
            {
              *head=create_node(data);  
              return;
            }
        newnode=create_node(data);
        newnode->next=*head;
        (*head)->prev=newnode;
        *head=newnode;
    }
    
void insert_at_pos(node **head,int data, int pos)
    {
       node *newnode;
       node *ptr1=*head;
       node *ptr2=NULL;
       newnode=create_node(data);
        if(pos==1)
            {
            node *newnode;
            if(*head==NULL)
                {
                *head=create_node(data);  
                return;
                }
            newnode=create_node(data);
            newnode->next=*head;
            (*head)->prev=newnode;
            *head=newnode;
            return;
            }
        
       while(pos>2)
            {
                ptr1=ptr1->next;
                pos--;
            }
        ptr2=ptr1->next;
        ptr1->next=newnode;
        ptr2->prev=newnode;
        newnode->next=ptr2;
        newnode->prev=ptr1;
    }

void add_after_data(node **head,int data, int data1)
    {
        node *newnode;
        node *ptr1=*head;
        node *ptr2=NULL;
        if(ptr1->data==data1)
            {
            node *newnode;
            if(*head==NULL)
                {
                *head=create_node(data);  
                return;
                }
            newnode=create_node(data);
            newnode->next=*head;
            (*head)->prev=newnode;
            *head=newnode;
            return;
            }
        newnode=create_node(data);
        while(ptr1->next != NULL)
            {
                if(ptr1->data==data1)
                    {
                        ptr2=ptr1->next;
                        ptr1->next=newnode;
                        ptr2->prev=newnode;
                        newnode->next=ptr2;
                        newnode->prev=ptr1; 
                        return;                      
                    }
            ptr1=ptr1->next;
            }
        printf("data not found[Insertion Failed\n");    
    }

int del_at_beg(node **head)
    {
        int data;
        node *ptr=*head;
        if(*head==NULL)
            {
                printf("Linked list is empty.\n");
                return -1;
            }
        data=ptr->data;
        if(ptr->next==NULL)
            {
                free(*head);
                *head=NULL;
                ptr=NULL;
                return data;
            }
        *head=ptr->next;
        (*head)->prev=NULL;
        free(ptr);
        ptr=NULL;
        return data;
    }

int del_at_end(node **head)
    {
        int data;
        node *ptr=*head;
        if(*head==NULL)
            {
                printf("Linked list is empty.\n");
                return -1;
            }
        if(ptr->next==NULL)
            {
                data=ptr->data;
                free(*head);
                *head=NULL;
                ptr=NULL;
                return data;
            }
        while(ptr->next->next!=NULL)
            ptr=ptr->next;
        data=ptr->next->data;
        free(ptr->next);
        ptr->next=NULL;
        return data;  
    }

int del_at_pos(node **head,int pos)
    {
        int data;
        node *temp=*head;
        node *temp2=NULL;
        if(*head==NULL)
            {
                printf("Linked List is empty");
                return -1;
            }
        if(pos==1)
            {
             data=temp->data;
             if(temp->next==NULL)
                {
                    free(*head);
                    *head=NULL;
                    temp=NULL;
                    return data;
                }
            *head=temp->next;
            (*head)->prev=NULL;
            free(temp);
            temp=NULL;
            return data;
            } 
        while(pos>1)
            {
                temp=temp->next;
                pos--;
            }
        data=temp->data;
        if(temp->next==NULL)
            {
                temp2=temp->prev;
                temp2->next=NULL;
                free(temp);
                temp=NULL;
                return data;
            }
        temp2=temp->prev;
        temp2->next=temp->next;
        temp->next->prev=temp2;
        free(temp);
        temp=NULL;
        return data;
    }

int del_data(node **head,int data)
    {
        node *temp=*head;
        node *temp2=NULL;
        if(temp->data==data)
            {
                if(temp->next==NULL)
                    {
                        free(*head);
                        *head=NULL;
                        temp=NULL;
                        return data;
                    }
                (*head)=temp->next;
                free(temp);
                temp=NULL;
                return data;        
            }
        while(temp!=NULL)
            {
                if(temp->data==data)
                    {
                        if(temp->next==NULL)
                            {
                                temp2=temp->prev;
                                temp2->next=NULL;
                                free(temp);
                                temp=NULL;
                                return data;
                            }
                        temp2=temp->prev;
                        temp2->next=temp->next->prev;
                        temp->next->prev=temp2;
                        free(temp);
                        temp=NULL;
                        return data;
                    }
                temp=temp->next;
            }
        printf("Data not found[Deletion failed!!!]"); 
    }
