#include <iostream>
using namespace std;
#define loop(x,start,end) for(int x = start; x < end; ++x)

void Swap(int* A, int index1, int index2)
{
	int t = A[index1];
	A[index1] = A[index2];
	A[index2] = t;
}

int Quicky(int* A, int start, int end)
{
	int less = start;
	//to store the point where large starts

	for(int i = start ; i<=end ; i++)
	{
		if(A[i] < A[end])
		{
			Swap(A,less,i);
			less++;
		}
	}
	Swap(A,less,end);
	return less;
}

//end included
void QuickSort(int* A, int start, int end)
{
	//ensures atleast two elements
	if(start < end)
	{
		int pivot = Quicky(A,start,end);
		QuickSort(A,start,pivot-1);
		QuickSort(A,pivot+1,end);
	}
}

int main(int argc, char const *argv[])
{
	int size;
	cout<<" Enter size"<<endl;
	cin>>size;
	cout<<" Enter array"<<endl;
	int array[size];
	for (int i = 0; i < size; ++i)
	{
		cin>>array[i];
	}
	QuickSort(array,0,size-1);
	for (int i = 0; i < size; ++i)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
	return 0;
}