#include <iostream>
using namespace std;
class list
{
    private:
        struct node//defining the structure and elements of a node
        {
            char data;
            node *next;
        }*head;
    public:
        list()
        {
            head=NULL;//implies that the list is empty,as it is empty in the start
        }
        void push(char data);
        char pop();
        char peek();
        void display();
};
//
void list::push(char data)
{
    struct node * newnode=(node*)malloc(sizeof(node));//allocates memory to the newnode
    newnode->data=data;//the input data is stored in the newnode
    if(head==NULL)//checks if list is empty
    {
        head=newnode;
        newnode->next=NULL;//if list is empty the next element for the newnode is nothing,so the next is set to NULL 
    }
    else
    {
        newnode->next=head;//if list is not empty the next for newnode is set to head
        head=newnode;
    }
} 
//functino that displays the whole stack
void list:: display()
{
    if(head==NULL)//checks if the stack is empty
    {
        cout<<"The stack is empty"<<'\n';
    }
    else
    {
        node *temp=head;//temp variable to store value of head to iterate through the stack
        cout<<"Stack: ";
        while(temp->next!=NULL)//this condition is to check when the list ends,and when it ends the loop terminates
        {
            cout<<temp->data<<" ";//displays the element
            temp=temp->next;//goes to the next element
        }
        cout<<temp->data<<" "<<'\n';//displays the last element of the stack
    }
}
//function to pop an element out of the stack
char list:: pop()
{
    if(head==NULL)//checks if the stack is empty
    {
        cout<<"The stack is empty"<<'\n';
        return -1;
    }
    node * del=head;//stores the head element
    head=head->next;//moves to the next element
    char value=del->data;
    free(del);
    return value;//popped data is returned to the main function
}
//function that displays the topmost element of the stack
char list:: peek()
{
    if(head==NULL)//checks if the stack is empty
    {
        cout<<"The stack is empty"<<'\n';
        return -1;
    }
    else
    {
        return head->data;//returns the topmost elemnt
    }
}
int main()
{
    list s;//instance of the class list is created
    int choice;
    char data;
    do
    {
        cout<<"\n Stack ADT Menu:\n1. Push;\n2. Pop;\n3. Peek;\n4.Exit\n Enter your choice:";//displaying the menu
        cin>>choice;//get the choice as input from the user
        switch(choice)
        {
            case 1:
                cout<<"Enter data: ";
                cin>>data;//we get data as input to push into the stack
                s.push(data);//data is pushed into the stack
                s.display();//displaying the stack after data is pushed to show the changes made to the stack
                break;

            case 2:
                cout<<"Popped element:"<<s.pop()<<'\n';//the popped element is displayed
                break;

            case 3:
                cout<<"The top element is: "<<s.peek()<<'\n';
                break;
            case 4:
                cout<<"Exiting the program...\n";
                break;

            default:
                cout<<"Invalid choice\n";
                choice=4;

        }
    }
    while(choice != 4);
    return 0;
}