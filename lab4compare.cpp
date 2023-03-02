#include<iostream>
#include<stdlib.h>
#include<time.h>
#define SIZE 5000
using namespace std;

float count_steps=0;

void RandomInput(int* arr, int n )
	{
		srand(time(0));
		for(int i=0;i<n;i++)
		{
			arr[i]=(rand()%n);
		}
	}

void swap(int *a, int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void BubbleSort(int A[],int n)
{	
	count_steps=0;
 	int i,j,x;
	for(i=0;i<n-1;i++)
 	{
 		count_steps++;
 		for(j=i+1;j<n;j++)
 		{
 			
 			if(A[i]>A[j])
 			{
 				count_steps++;
 				swap(&A[i],&A[j]);
			 }
		 }
	 }
}

void SelectionSort(int A[],int n)
{	
	count_steps=0;
 	int i,j,k;
	for(i=0;i<n-1;i++)
 	{
 		count_steps++;
 		for(j=k=i;j<n;j++)
 		{
 			if(A[j]<A[k])
 			{
 				k=j;
 				count_steps++;
			 }
		 }
		 swap(&A[i],&A[k]);
	 }
}

void InsertionSort(int A[],int n)
{	
	count_steps=0;
 	int i,j,x;
	for(i=1;i<n;i++)
 	{
 		j=i-1;
 		x=A[i];
 		count_steps++;
 		while(j>-1 && A[j]>x)
 		{
 			count_steps++;
 			A[j+1]=A[j];
 			j--;
	 	}
 		A[j+1]=x;
	 }
}

int main()
{
	int arr[SIZE];
	int n;
	cout<<"Enter the size n: ";
	cin>>n;
	
	RandomInput(arr,n);
	BubbleSort(arr,n);
	cout<<"Bubble Sort Steps: "<<count_steps<<endl;
//	count_steps=0;
	RandomInput(arr,n);
	SelectionSort(arr,n);
	cout<<"Selection Sort Steps: "<<count_steps<<endl;
//	count_steps=0;
	RandomInput(arr,n);
	InsertionSort(arr,n);
	cout<<"Insertion Sort Steps: "<<count_steps<<endl;
	cout<<"Robin-23498-DAA-lab-Prime"<<endl;
	return 0;
}

