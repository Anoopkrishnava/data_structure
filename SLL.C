#include<stdio.h>
#include<stdlib.h> // used to work dynamic memory allocation 
struct node { //creating a structure
    int data;
    struct node *next;
};
struct node *head=NULL; //at first set the head as null ie. no elements in it
void beginsert(void);
void display(void);
void begin_delete(void);
void last_insert(void);
void last_delete();
void random_insert();
void random_delete();
void search();
int main()
{
    int choice=0;
    while(choice!=3){
        printf("\n1.Insert at beginning\n2.display\n3.exit\n4.Delete from beginning\n5.Insert at end\n6.Delete from end\n7.Insert at a random location\n8.Delete from a random location\n9.Search\n\nEnter your choice :");
        scanf("%d",&choice);
        switch(choice){
            case 1:beginsert();
                break;
            case 2:display();
                break;
            case 3:exit(0);
                break;
            case 4:begin_delete();
                break;
            case 5:last_insert();
                break;
            case 6:last_delete();
                break;
            case 7:random_insert();
                break;
            case 8:random_delete();
                break;
            case 9:search();
                break;
            default:printf("Invalid choice");
        }

    }
return 0;
}
void beginsert()
{
    struct node *ptr;
    int item;
    ptr=(struct node*)malloc(sizeof(struct node)); // dynamically allocating memory
    //(struct node*) typecast the return void pointer from malloc() to structure type
    //sizeof(struct node) give number of byte needed to store the structure
    
    if(ptr==NULL){
        printf("\nOVERFLLOW\n");
    }
    else{
        printf("\nEnter value :");
        scanf("%d",&item);
        ptr->data=item;
        ptr->next=head;
        head=ptr;
        printf("\nNode inserted\n");
    }
}
void display()
{
    if(head==NULL){
        printf("\nEmpty List\n");
    }
    else{
        for(struct node *i=head;i!=NULL;i=i->next){
            printf("%d ->\t",i->data);
        }
    }
    printf("\n");
}
void begin_delete()
{
    struct node *ptr;
    if(head==NULL)
    {
        printf("\nList is empty\n");
    }
    else{
        ptr=head;
        head=ptr->next;
        free(ptr);
        printf("\nNode deleted from front\n");
    }
}
void last_insert()
{
    struct node *ptr,*temp;
    int item;
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else{
        printf("Enter value :");
        scanf("%d",&item);
        ptr->data=item;
        if(head==NULL)
        {
            ptr->next=NULL;
            head=ptr;
            printf("\nNode inserted\n");

        }
        else{
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=ptr;
            ptr->next=NULL;
            printf("\nNode inserted\n");
        }
    }
}
void last_delete()
{
    struct node *ptr,*temp;
    if(head==NULL){
        printf("List is empty");
    }
    else if(head->next==NULL){
        free(head);
        head=NULL;
        printf("\nOnly node in the list deleted\n");

    }
    else{
        temp=head;
        while(temp->next!=NULL){
            ptr=temp;
            temp=temp->next;
        }
        ptr->next=NULL;
        free(temp);
        printf("\nNode deleted from last\n");
    }
}
void random_insert()
{
    struct node *ptr,*temp;
    int item,position,i;
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("\nOVERFLOW\n");
    }
    else{
        printf("\nEnter the element :");
        scanf("%d",&item);
        ptr->data=item;
        printf("\nEnter the position that the element to be added :");
        scanf("%d",&position);
        
        temp=head;
        for(i=1;i<position-1;i++){
            temp=temp->next;
        }
        ptr->next=temp->next;
        temp->next=ptr;
        printf("\nNode inserted at %d\n",position);
    }
}
void random_delete()
{
    struct node *ptr,*temp=head;
    int position,i;
    if(head==NULL){
        printf("\nList is empty \n");
    }
    else{
        printf("Enter the position of node to be deleted :");
        scanf("%d",&position);
        
        for(i=1;i<position-1;i++){
            if(temp==NULL || temp->next==NULL){
                printf("\nIndex out of range\n");
            }
            temp=temp->next;
        }
        ptr=temp->next;
        if(ptr==NULL){
            printf("\nCan't delete\n");
        }
        temp->next=ptr->next;
        free(ptr);
        printf("\nNode deleted at position %d\n",position);
    }

}
void search()
{
struct node *temp=head;
int item;
bool flag=false;
if(head==NULL){
    
    printf("\nList is empty\n");
}
else{
    printf("\nEnter the value you are searching for :");
    scanf("%d",&item);
    if(temp->data==item){
        flag=true;
        //printf("\nThe element is present in the list\n");
    }
    while(temp->next!=NULL){
        temp=temp->next;
        if(temp->data==item){
            flag=true;
            break;
        }
    }
    if(flag==false){
        printf("\nIt is absent in the list \n");
    }
    else{
        printf("\nThe element is present in the list\n");

    }
}
}