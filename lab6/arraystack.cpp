#include <iostream>
using namespace std;

class stack
{
    private:
        char arr[5];
        int top;

    public:
        stack()
        {
            top = -1;
        }
        void push(char data);
        char pop();
        char peek();
        void display();
};
//Function to push an element into the top of an array 
void stack:: push(char data)
{
    if(top==4)
    {
        cout<<"The stack is full(overflow)"<<'\n';
    }
    else
    {
        arr[++top]=data;
    }
}
//Function to pop the topmost element out of an array,returns the element that is popped
char stack:: pop()
{
    if(top==-1)
    {
        cout<<"THe stack is empty(Underflow)"<<'\n';
        return 0;
    }
    return arr[top--];
    
}
//Functino to display the stack from top to bottom
void stack::display()
{
    if(top==-1)
    {
        cout<< "The stack is empty"<<'\n';
    }
    else
    {
        cout<< "Stack:";
        for(int i=top;i>=0;i--)
        {
            cout<<arr[top]<<'\n';
        }
    }
}
//Function to peek the stack,i.e display the topmost element of the stack
char stack::peek()
{
        if(top < 0)
        {
            cout << "Stack is empty"<<'\n';
            return 0;
        }
        cout<<"Top element is:"<<arr[top]<<'\n';
        return arr[top];
}
int main()
{
    stack s;//an instance of the stack is created
    int choice;
    char data;

    do
    {
        cout<<"\n Stack ADT Menu:\n1. Push;\n2. Pop;\n3. Peek;\n4.Exit\n Enter your choice:";//display of menu
        cin>>choice;//we get the users choice as input

        switch(choice)//switch case to perform the operations based of the user's choice
        {
            case 1://pushing an element into the stack
                cout<<"Enter data: ";
                cin>>data;
                s.push(data);
                s.display();//displays the stack after an element is added into it to show the changes
                break;

            case 2://to pop an elemnt out of the stack
                cout<<"Popped element:"<<s.pop()<<'\n';
                break;

            case 3:
                cout<<"THe top element is: "<<s.peek()<<'\n';//displays the topmost element
                break;
            case 4://carry's out if the user wants to exit the menu
                cout<<"Exiting the program...gn gng\n";
                break;

            default://if a choice that is not in the menu,i.e(1,2,3,4) is entered,we display an error message
                cout<<"Invalid choice\n";
                choice=4;
        }
    }
    while(choice != 4);//exits loop if 4 is entered
    return 0;
}