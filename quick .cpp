
#include<iostream>
#include<stdlib.h>
#include<time.h>
#define SIZE 5000
using namespace std;

float count_steps=0;

void WorstCaseinput(int* arr, int n)
	{
		arr[0]=n;
		for(int i=1;i<n;i++)
		{
			arr[i] =arr[i-1]- 1;
		}
	}

void BestCaseinput(int* arr, int n )
	{
		srand(time(0));
		for(int i=0;i<n;i++)
		{
			arr[i]=(rand()%n);
		}
	}
	
void swap(int *x,int *y)
	{
 		int temp=*x;
 		*x=*y;
 		*y=temp;
 		count_steps++;
	}

int partition(int A[],int l,int h)
{
	int pivot=A[l];
	int i=l,j=h;
	count_steps++;
	do
 	{
 		count_steps++;
 		do{i++;	count_steps++;}while(A[i]<=pivot);
 		do{j--;	count_steps++;}while(A[j]>pivot);

 		if(i<j)swap(&A[i],&A[j]); 
 	}while(i<j);
 	swap(&A[l],&A[j]);
 	return j;
}
void QuickSort(int A[],int l,int h)
{
 	int j;
 	if(l<h)
 	{
 		count_steps++;
 		j=partition(A,l,h);
 		QuickSort(A,l,j);
 		QuickSort(A,j+1,h);
 	}
}

int main()
{
	int arr[SIZE];
	int n;
	cout<<"Enter the size n: ";
	cin>>n;
	BestCaseinput(arr,n);
	QuickSort(arr,0,n-1);
	cout<<"Best Case Steps: "<<count_steps<<endl;
	count_steps=0;
	WorstCaseinput(arr, n);
	QuickSort(arr,0,n-1);
	cout<<"Worst Case Steps: "<<count_steps<<endl;
	cout<<"Robin-23498-DAA-lab-Prime"<<endl;
	
	return 0;
}

