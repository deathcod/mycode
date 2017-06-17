#include <bits/stdc++.h>
using namespace std;

#ifndef INT_MAX
#define INT_MAX 1e9
#endif

#ifndef INT_MIN
#define INT_MIN -1e9
#endif

class binary_heap
{
public:
	int *heap_data;
	int cur_size;
	int max_size;
public:
	binary_heap(int capacity)
	{
		max_size = capacity;
		cur_size = 0;
		heap_data = new int[capacity];
	};
	~binary_heap()
	{
		delete(heap_data);
	};
	
	void minHeapify(int index);

	int parent(int i) {return (i-1)/2;}
	int Left(int i) { return 2*i + 1;}
	int Right(int i) { return 2*i + 2;}

	int extract_min();

	void decrease_key(int index, int value);
	void delete_key(int index);
	void insert_key(int value);
};

//utility function
void swap(int *x, int *y)
{
	int f = *x;
	*x = *y;
	*y = f;
}

// assuming zero based indexing
void binary_heap :: minHeapify(int index)
{
	int left  = Left(index);
	int right = Right(index);

	int smallest = index;
	if(left < cur_size && heap_data[left] < heap_data[index])
	{
		smallest = left;
	}

	if(right < cur_size && heap_data[right] < heap_data[smallest])
	{
		smallest = right;
	}

	if (smallest!=index)
	{
		swap(heap_data[smallest], heap_data[index]);
		minHeapify(smallest);
	}
}

int binary_heap :: extract_min()
{
	if(cur_size == 0)
		return INT_MAX;
	else if(cur_size == 1)
	{
		cur_size--;
		return heap_data[0];
	}

	int minimum = heap_data[0];

	//bring the new minimum
	heap_data[0] = heap_data[cur_size-1];
	cur_size--;
	minHeapify(0);
	return minimum;
}

// assuming zero based indexing
void binary_heap :: decrease_key(int index, int value)
{
	heap_data[index] = value;
	while(index>=0 && heap_data[parent(index)]>heap_data[index])
	{
		swap(heap_data[parent(index)], heap_data[index]);
		index = parent(index);
	}
}

// assuming zero based indexing
void binary_heap :: delete_key(int index)
{
	heap_data[index] = INT_MIN;
	while(index>=0 && heap_data[parent(index)]>heap_data[index])
	{
		swap(heap_data[parent(index)], heap_data[index]);
		index = parent(index);
	}
	extract_min();
}

void binary_heap :: insert_key(int value)
{
	if(cur_size == max_size)
	{
		cout << "Overflow cannot insert\n";
		return;
	}
	cur_size++;
	int index = cur_size -1;
	heap_data[index] = value;
	while(index>=0 && heap_data[parent(index)]>heap_data[index])
	{
		swap(heap_data[parent(index)], heap_data[index]);
		index = parent(index);
	}
}

// this function was created to test the functionality of the heap
void testing()
{
	binary_heap *h = new binary_heap(11);
	h->insert_key(3);
    h->insert_key(2);
    h->delete_key(1);
    h->insert_key(15);
    h->insert_key(5);
    h->insert_key(4);
    h->insert_key(45);

    cout << h->extract_min() << " ";
    cout << h->extract_min() << " ";
    h->decrease_key(0,1);
    cout << h->extract_min() << " ";
    cout << h->extract_min() << " ";
}