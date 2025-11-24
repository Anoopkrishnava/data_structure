#include<stdio.h>
#include<stdlib.h>
int stack[100],choice,size,value,i;
int top=-1;
void push(void);
void pop(void);
void display(void);
void main()
{
    
    printf("Enter the size of stack :");
    scanf("%d",&size);
    printf("\n\n1.Push\n2.Pop\n3.Display\n4.exit\n");
    do{
        printf("\nEnter your choice :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:push();
                break;
            case 2:pop();
                break;
            case 3:display();
                break;
            case 4:printf("program terminated");
                break;
            default:
                printf("Please enter a valid choice ");

        }
    }while(choice!=4);
}
void push()
{
    if(top>=size-1){
        printf("\nStack is overflow");
    }
    else{
        printf("Enter a value to push :");
        scanf("%d",&value);
        top++;
        stack[top]=value;
    }
}
void pop()
{
    if(top<=-1){
        printf("Stack underflow");
    }
    else{
        printf("The popped element is %d\n",stack[top]);
        top--;
    }
}
void display()
{
    if(top<=-1){
        printf("Nothing to print\n");

    }
    else{
        printf("The elements in stack is :\n");
        for(i=top;i>=0;i--)
        {
            printf("\n%d\n",stack[i]);
        }
    }
}