#ifndef STACK_OPERATIONS_H
#define STACK_OPERATIONS_H

#include<iostream>
#include<cctype>
#include<string>
using namespace std;

//Defining the structure of the node
struct node{  
    char data;
    node* next;
};

class stack{
private:
    node* top;
public:
    stack(){
        top=nullptr;
    }

    int isempty(){return top==nullptr;}

//Function to push a character to the stack
    void push(char value){
        node* newnode=(node*)malloc(sizeof(node));
        newnode->data=value;
        newnode->next=top;
        top=newnode;
    }

//Function to pop the top most character from the stack
    int pop(){
        if(isempty())return '\0';
        char value=top->data;
        node* temp=top;
        top=top->next;
        free(temp);
        return value;
    }
//Function to peek and print the top most character from the stack
    int peek(){
        return isempty()?'\0':top->data;
    }

//Function to clear the stack
    void clear(){
        while(!isempty())pop();
    }

    ~stack(){clear();}
};

int precedence(char op){
    if(op=='=')return 0;
    if(op=='+'||op=='-')return 1;
    if(op=='*'||op=='/'||op=='%')return 2;
    return -1;
}

//Function to convert infix to postfix
void infixtopostfix(string &infix,string &postfix){
    stack s;
    postfix="";

    for(char ch:infix){
        if(isalnum(ch))postfix+=ch;
        else if(ch=='(')s.push(ch);
        else if(ch==')'){
            while(!s.isempty()&&s.peek()!='(')postfix+=s.pop();
            s.pop();
        }
        else{
            while(!s.isempty()&&precedence(s.peek())>=precedence(ch))postfix+=s.pop();
            s.push(ch);
        }
    }

    while(!s.isempty())postfix+=s.pop();
}

//Function to evaluate postfix
int evaluatepostfix(string &postfix){
    stack s;
    
    for(char ch:postfix){
        if(isdigit(ch))s.push(ch-'0');
        else{
            int val2=s.pop(),val1=s.pop();
            switch(ch){
                case '+':s.push(val1+val2);break;
                case '-':s.push(val1-val2);break;
                case '*':s.push(val1*val2);break;
                case '/':s.push(val1/val2);break;
                case '%':s.push(val1%val2);break;
                case '=':s.push(val2);break;
            }
        }
    }
    return s.pop();
}

#endif // STACK_OPERATIONS_H
