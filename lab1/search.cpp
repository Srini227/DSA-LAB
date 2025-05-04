#include <cstdlib>
#include <cstdio>
void Linear(int arr[],int search,int n)
{
int count=0;
for(int i=0;i<n;i++)
{
if(arr[i]==search)
{
printf("Element found\n");
count++;
break;
}
}
if (count==0)
{
printf("Element not found\n");
}
}
void binary(int arr[],int search,int n)
{
int count=0;
int left=0;
int right=n-1;
int mid=(left+right)/2;
while(left<right)
{
if(arr[mid]==search)
{
printf("Element found\n");
count++;
break;
}
else if(search>arr[mid])
{
left=mid+1;
}
else if(search<arr[mid])
{
right=mid-1;
}
mid=(right+left)/2;
}
if(count==0)
{
printf("Element not found\n");
}
}

int main()
{
int n;
printf("Enter no. of elements: \n");
scanf("%d",&n);
int arr[n];
for(int i=0;i<n;i++)
{
printf("Enter element: \n");
scanf("%d",&arr[i]);
}
int choice,search;
while(choice!=3)
{
printf("1.Linear search\n");
printf("2.BInary search\n");
printf("3.Exit\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
{
printf("Enter element to search: ");
scanf("%d",&search);
Linear(arr,search,n);
}
case 2:
{
printf("Enter element to search: ");
scanf("%d",&search);
binary(arr,search,n);
}
case 3:
{
break;
}
}
}
return 0;
}

