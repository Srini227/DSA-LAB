#include <cstdlib>
#include <cstdio>
void printarray(int arr[],int n)
{
for(int i=0;i<n;i++)
{
printf("%d ",arr[i]);
}
printf("\n");
}
void bubble(int arr[], int n) {
int i, j, temp;
for (i = 0; i < n - 1; i++)
{
for (j = 0; j < n - i - 1; j++)
{
if (arr[j] > arr[j + 1])
{
temp = arr[j];
arr[j] = arr[j + 1];
arr[j + 1] = temp;
}
}
}
printarray(arr,n);
}
void selection(int arr[], int n)
{
int i, j, minIndex, temp;
for (i = 0; i < n - 1; i++)
{
minIndex = i;
for (j = i + 1; j < n; j++)
{
if (arr[j] < arr[minIndex])
{
minIndex = j;
}
}
if (minIndex != i)
{
temp = arr[i];
arr[i] = arr[minIndex];
arr[minIndex] = temp;
}
}
printarray(arr,n);
}
void insertion(int arr[], int n)
{
int i, key, j;
for (i = 1; i < n; i++)
{
key = arr[i]; n
j = i - 1;
while (j >= 0 && arr[j] > key)
{
arr[j + 1] = arr[j];
j = j - 1;
}
arr[j + 1] = key;
}
printarray(arr,n);
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
int choice;
while(choice!=4)
{
printf("1.Bubble sort\n");
printf("2.Selection sort\n");
printf("3.INsertion sort\n");
printf("4.Exit\n ");
scanf("%d",&choice);
switch(choice)
{
case 1:
bubble(arr,n);
case 2:
selection(arr,n);
}
}
return 0;
}
