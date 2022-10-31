#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}tree;

typedef struct n
{
    tree *point;
    struct n *next;
}node;

void push(node ** hd, tree *item)
{
    node *newnode, *temp = *hd;
    newnode=(node*)(malloc(sizeof(node)));
    newnode->point=item;
    newnode->next=NULL;
    if(*hd == NULL)
    {
        *hd=newnode;
        return;
    }
    else
    {
        newnode->next=*hd;
        *hd=newnode;
    }
}
tree *pop(node ** hd)
{
    tree *x;
    node *temp = *hd;
    x=temp->point;
    temp=temp->next;
    *hd=temp;
    return(x);
}
tree *create_node(int data)
{
    tree *new_node = (struct node*)malloc(sizeof(tree));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
void insert(tree **root,int value)
{
    tree *new_node = create_node(value);
    if (new_node!=NULL)
    {
        if (*root==NULL)
        {
            *root = new_node;
            return;
        }
    }
    tree *temp = *root;
    tree *prev = NULL;
    while (temp!=NULL)
    {
        prev = temp;
        if (value>temp->data)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    if (value>prev->data)
    {
        prev->right = new_node;
    }
    else
    {
        prev->left = new_node;
    }
}
void preorder(tree *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(tree *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void postorder(tree *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
void preorder_iterative(tree * root, node ** hd)
{
    tree *temp = root;
    while(1)
    {
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            push(hd, temp);
            temp = temp->left;
        }
        if(*hd==NULL)
        break;
        temp = pop(hd);
        temp=temp->right;
    }
    printf("\n");
}
void inorder_iterative(tree * root, node ** hd)
{
    tree *temp = root;
    while(1)
    {
        while(temp!=NULL)
        {
            push(hd, temp);
            temp = temp->left;
        }
        if(*hd==NULL)
        break;
        temp = pop(hd);
        printf("%d ",temp->data);
        temp=temp->right;
    }
    printf("\n");
}
void postorder_iterative(tree * root, node ** hd)
{
    tree *temp = root, *prev = NULL;
    while(1)
    {
        while(temp!=NULL)
        {
            push(hd, temp);
            temp = temp->left;
        }
        if(*hd==NULL)
        break;
        while(temp==NULL && *hd!=NULL)
        {
            temp=(*hd)->point;
            if (temp->right == NULL || temp->right == prev)
            {
                printf("%d ",temp->data);
                pop(hd);
                prev=temp;
                temp=NULL;
            }
            else
            temp=temp->right;
        }
    }
    printf("\n");
}
int node_calculation(tree *root)
{
    if(root==NULL)
    {
        return 0;
    }
    return node_calculation(root->left)+node_calculation(root->right)+1;
}
int height_calculation(tree *root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        int left = height_calculation(root->left);
        int right = height_calculation(root->right);
        if(left>right)
        {
            return (left+1);
        }
        else
        {
            return (right+1);
        }
    }
}
void main()
{
    tree *root = NULL;
    node *head = NULL;
    int ch,value;
    while(1)
    {
        printf("Choose One Option\n");
        printf("01. for Insertion\n");
        printf("02. for Preorder-Traversal\n");
        printf("03. for Inorder-Traversal\n");
        printf("04. for Postorder-Traversal\n");
        printf("05. for Preorder-Iterative-Traversal\n");
        printf("06. for Inorder-Iterative-Traversal\n");
        printf("07. for Postorder-Iterative-Traversal\n");
        printf("08. for Node_Calculation\n");
        printf("09. for Height_Calculation\n");
        printf("10. for Exit\n");
        printf("Enter Your Choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter the Data you want to Insert\n");
            scanf("%d",&value);
            insert(&root,value);
            break;
            case 2:
            preorder(root);
            printf("\n");
            break;
            case 3:
            inorder(root);
            printf("\n");
            break;
            case 4:
            postorder(root);
            printf("\n");
            break;
            case 5:
            preorder_iterative(root,&head);
            break;
            case 6:
            inorder_iterative(root,&head);
            break;
            case 7:
            postorder_iterative(root,&head);
            break;
            case 8:
            printf("%d\n",node_calculation(root));
            break;
            case 9:
            printf("%d\n",height_calculation(root));
            break;
            case 10:
            exit(1);
            break;
        }
    }
}