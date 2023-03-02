#include <iostream>
#include <stdlib.h>
#include<time.h>
#define MAX 5000
using namespace std;

float count_steps = 0;

void BestCaseinput(int* arr, int n){
	srand(time(0));
	for(int i=0;i<n;i++)
		{
			arr[i]=1+(rand()%n);
		}
}

void heapify(int arr[], int n, int i){
	count_steps++;
    int largest = i;
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
 
    if (l < n && arr[l] > arr[largest])
        largest = l;
        
    if (r < n && arr[r] > arr[largest])
        largest = r;
        
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
 
void heapSort(int* arr, int n){
    for (int i = n / 2 - 1; i >= 0; i--){
    	heapify(arr, n, i);
    	count_steps++;
	}
        
 
    for (int i = n - 1; i >= 0; i--){
    	count_steps++;
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main(){
	int arr[MAX], n, ch;
	cout << "Enter the input size: ";
	cin >> n;
	
	BestCaseinput(arr, n);
			
	heapSort(arr, n);
	cout << "Number of steps: " << count_steps<<endl;
	    cout<<"Robin-23498-DAA-lab-Prime"<<endl;
	return 0;
}
