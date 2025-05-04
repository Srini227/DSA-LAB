#include <cstdio>
#include<cstdlib>

class list
{
    private:
        int arr[5];
        int cur;
    public:
        list(){
            cur=0;
        }
        int is_empty(){
            if(cur!=0)
            {
                return 1;
            }
            else{
                return 0;
            }
        }
        void insb(int val);
        void inse(int val);
        void insp(int pos,int val);
        void delb();
        void dele();
        void delp(int pos);
        void search(int num);
        void disp();
        void rotate(int k);
};
void list::insb(int val)
{
    int r;
    r=is_empty();
    if(cur==5){
        printf("List if full\n");
    }
    else if(r==0)
    {
        arr[0]=val;
        cur++;
    }
    else{
        for(int i=cur;i>=1;i--)
        {
            arr[i]=arr[i-1];
        }
        arr[0]=val;
        cur++;
    }
}
void list::inse(int val)
{
    int r;
    r=is_empty();
    if(cur==5){
        printf("List if full\n");
    }
    else if(r==0)
    {
        arr[0]=val;
        cur++;
    }
    else{
        arr[cur]=val;
        cur++;
    }
}
void list::insp(int pos,int val)
{
    int r;
    r=is_empty();
    if(cur==5){
        printf("List if full\n");
    }
    else if(r==0)
    {
        arr[0]=val;
        cur++;
    }
    else{
        if(pos==4 & cur!=4)
        {
            arr[cur]=val;
            cur++;
        }
        else{
            for(int i=pos;i<cur;i++)
            {
                arr[i+1]=arr[i];
            }
            arr[pos]=val;
            cur++;
        }
    }
}
void list :: delb()
{
    int r;
    r=is_empty();
    if(r==0)
    {
        printf("LIst is empty\n");
    }
    else
    {
        printf("%d\n",arr[0]);
        for(int i=0;i<cur-1;i++)
        {
            arr[i]=arr[i+1];
        }
        cur--;
    }
}
void list :: dele()
{
    int r;
    r=is_empty();
    if(r==0)
    {
        printf("LIst is empty\n");
    }
    else
    {
        cur--;
        printf("%d\n",arr[cur+1]);
    }
}
void list :: delp(int pos)
{
    int r;
    r=is_empty();
    if(r==0)
    {
        printf("LIst is empty");
    }
    else
    {
        printf("%d\n",arr[pos]);
        for(int i=pos;i<cur-1;i++)
        {
            arr[i]=arr[i+1];
        }
        cur--;
    }
}
void list ::search(int num)
{
    int r,c;
    r=is_empty();
    if(r==0)
    {
        printf("THe list is empty\n");
    }
    else{
        for(int i=0;i<cur;i++)
        {
            if(arr[i]==num)
            {
                printf("The element is found\n");
                c++;
            }
        }
    }
    if(c==0)
    {
        printf("The element is not found\n");
    }
}
void list :: disp()
{
    for(int i=0;i<cur;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("\n");
}
void list :: rotate(int k)
{
    int r;
    r=is_empty();
    if(r==0)
    {
        printf("THe list is empty\n");
    }
    else
    {
        for(int j=0;j<k;j++)
        {
            int temp;
            temp=arr[cur-1];
            printf("%d",temp);
            for(int i=cur;i>=1;i--)
            {
                arr[i]=arr[i-1];
            }
            arr[0]=temp;
        }
    }
}
int main()
{
    class list arr;
    int choice;
    while (choice!=10)
    {
        printf("1.Insert beginning\n");
        printf("2.Insert end\n");
        printf("3.Insert position\n");
        printf("4.Delete beginning\n");
        printf("5.Delete end\n");
        printf("6.Delete position\n");
        printf("7.Search\n");
        printf("8.Display\n");
        printf("9.Rotate\n");
        printf("10.Exit\n");
        printf("Enter choice: \n");
        scanf("%d",&choice);
        int value,pos,num,k;
        switch(choice)
        {
            case 1:
                printf("Enter element to be inserted: ");
                scanf("%d",&value);
                arr.insb(value);
                break;
            case 2:
                printf("Enter element to be inserted: ");
                scanf("%d",&value);
                arr.inse(value);
                break;
            case 3:
                printf("Enter element to be inserted: ");
                scanf("%d",&value);
                printf("Enter position to be inserted: ");
                scanf("%d",&pos);
                arr.insp(pos,value);
                break;
            case 4:
                arr.delb();
                break;
            case 5:
                arr.dele();
                break;
            case 6:
                printf("Enter position to be deleted: ");
                scanf("%d",&pos);
                arr.delp(pos);
                break;
            case 7:
                printf("Enter element to search: ");
                scanf("%d",&num);
                arr.search(num);
                break;
            case 8:
                arr.disp();
                break;
            case 9:
                printf("Enter no. of rotations: ");
                scanf("%d",&k);
                arr.rotate(k);
            case 10:
                break;
        }       
    }
    return 0;
}