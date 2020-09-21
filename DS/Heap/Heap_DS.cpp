#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#include <limits>
#include <vector>

class Heap
{
private:
	vector<int> heap;
public:
	Heap()
	{
		heap.clear();
	}
	void insert(int val);
	void BuildHeap(vector<int>& A);
	void swap(int a, int b);
	int parent(int index);
	int left(int index);
	int right(int index);
	void fixUp(int index);
	void fixDown(int index);  //heapify
	int Min(int a, int b);
	int Min3(int a, int b, int c);
	int returnMin();
	int returnMax();
	void HeapSort(vector<int>& A);
	void print();
	int size();
	int find();
	void deleteKey(int index);
	void extractMin();
	void decreaseKey(int oldIndex, int newVal);
};

void HeapSort()
{
	
}

void Heap::extractMin()
{
	deleteKey(0);
}

void Heap::deleteKey(int index)
{
	if(index >= heap.size()) return;
	if(heap.size() == 1 || index == heap.size()-1) heap.pop_back();
	swap(index,(int)heap.size()-1);
	heap.pop_back();
	fixDown(index);
}

int Heap::Min3(int a, int b, int c)
{
	int mini = Min(a,b);
	return Min(mini,c);
}

void Heap::fixDown(int index)
{
	while(index < (int)heap.size()/2)
	{
		int temp = Min3(index, left(index), right(index));
		if(temp == index) return;
		else{
			swap(temp, index);
			index = temp;
		}
	}
}

void Heap::decreaseKey(int oldIndex, int newVal)
{
	if(oldIndex >= heap.size()) return;
	if(heap[oldIndex] <= newVal ) return;
	heap[oldIndex] = newVal;
	fixUp(oldIndex);
}

int Heap::size()
{
	return heap.size();
}

int Heap::returnMin()
{
	if(heap.size() == 0) return INT_MAX;
	else return heap[0];
}

int Heap::returnMax()
{
	if(heap.size() == 0) return INT_MIN;
	int Max = heap[(int)heap.size()/2];
	for(int i = (int)(heap.size()/2)+1;i<heap.size();i++)
	{
		Max = max(Max,heap[i]);
	}
	return Max;
}

void Heap::swap(int a, int b)
{
	int t = heap[a];
	heap[a] = heap[b];
	heap[b] = t;
}

void Heap::insert(int val)
{
	heap.push_back(val);
	int index = heap.size()-1;
	if(parent(index) == -1) return;
	fixUp(index);
}

int Heap::parent(int index)
{
	if(index == 0) return -1;
	return (index-1)/2;
}

int Heap::left(int index)
{
	return 2*index+1;
}

int Heap::right(int index)
{
	return 2*(index+1);
}

int Heap::Min(int a, int b)
{
	if(heap[a] <= heap[b]) return a;
	else return b;
}

void Heap::fixUp(int index)
{
	if(index>= heap.size() || index == 0) return;
	while(index > 0)
	{
		if(Min(parent(index), index) == parent(index)) return;
		else{
			swap(index,parent(index));
			index = parent(index);
		} 
	}
}

void Heap::print()
{
	for(auto x: heap) cout<<x<<" ";
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	Heap myHeap;
	vector<int> v = {1,5,0,3,8,7,9,56,23,0,-4,47,15};
	cout<<"actual vector"<<endl;
	for(auto x: v) cout<<x<<" "; cout<<endl;
	for (int i = 0; i < v.size(); ++i)
	{
		myHeap.insert(v[i]);
	}
	myHeap.print();
	/*
		Functions left to implement : 		
			void HeapSort();
			int find();
	*/
	cout<<"Min val : "<<myHeap.returnMin()<<endl;
	cout<<"Max val : "<<myHeap.returnMax()<<endl;
	myHeap.extractMin();
	myHeap.print();
	myHeap.decreaseKey(2,-8);
	myHeap.print();
	myHeap.decreaseKey(0,-56);
	myHeap.print();
	myHeap.deleteKey(6);
	myHeap.print();
	return 0;
}