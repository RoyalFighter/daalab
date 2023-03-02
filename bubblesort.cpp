#include<iostream>
#include<stdlib.h>
#include<time.h>
#define SIZE 5000
using namespace std;

float count_steps=0;

void BestCaseinput(int* arr, int n)
	{
		for(int i=0; i<n; i++)
			{
				arr[i] = i+1;
			}
	}

void WorstCaseinput(int* arr, int n)
	{
		arr[0]=n;
		for(int i=1;i<n;i++)
		{
			arr[i] =arr[i-1]- 1;
		}
	}

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

int main()
{
	int arr[SIZE];
	int n;
	cout<<"Enter the size n: ";
	cin>>n;
	BestCaseinput(arr,n);
	BubbleSort(arr,n);
	cout<<"Best Case Steps: "<<count_steps<<endl;
	
	WorstCaseinput(arr, n);
	BubbleSort(arr,n);
	cout<<"Worst Case Steps: "<<count_steps<<endl;
	
	RandomInput(arr,n);
	BubbleSort(arr,n);
	cout<<"Random Case Steps: "<<count_steps<<endl;
	cout<<"Robin-23498-DAA-lab-Prime"<<endl;
	
	return 0;
}

