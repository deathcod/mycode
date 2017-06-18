#include <bits/stdc++.h>
using namespace std;

#ifndef INT_MAX
#define INT_MAX 1e9
#endif

#ifndef INT_MIN
#define INT_MIN -1e9
#endif

typedef pair<int,int> pp;

class minheap
{
private:
	pp *heap_data;
	int cur_size;
	int max_size;
	int *pos;
public:
	minheap(int capacity)
	{
		max_size = capacity;
		cur_size = 0;
		heap_data = new pp[capacity];

		// This will keep record of all the nodes positioned inside the heap
		pos = new int[capacity];
	};
	~minheap()
	{
		delete(heap_data);
	};
	
	void minHeapify(int index);

	int parent(int i) {return (i-1)/2;}
	int Left(int i) { return 2*i + 1;}
	int Right(int i) { return 2*i + 2;}

	pp extract_min();

	void decrease_key(int node_index, int value);
	void delete_key(int node_index);
	void insert_key(pp node);

	bool isempty();
	int get_val(int node_index);

	//testing
	void output_pos();
};

//utility function
void swap(pp *x, pp *y)
{
	pp f = *x;
	*x = *y;
	*y = f;
}

// assuming zero based indexing
void minheap :: minHeapify(int index)
{
	int left  = Left(index);
	int right = Right(index);

	int smallest = index;
	if(left < cur_size && heap_data[left].second < heap_data[index].second)
	{
		smallest = left;
	}

	if(right < cur_size && heap_data[right].second < heap_data[smallest].second)
	{
		smallest = right;
	}

	if (smallest!=index)
	{
		//swaping the positions
		pos[heap_data[smallest].first] = index;
		pos[heap_data[index].first] = smallest;

		swap(heap_data[smallest], heap_data[index]);
		minHeapify(smallest);
	}
}

pp minheap :: extract_min()
{
	if(cur_size == 0)
		return pp(INT_MAX, INT_MAX);
	else if(cur_size == 1)
	{
		cur_size--;
		return heap_data[0];
	}

	pp minimum = heap_data[0];

	//swaping the positions
	pos[heap_data[0].first] = cur_size-1;
	pos[heap_data[cur_size-1].first] = 0;

	//bring the new minimum
	heap_data[0] = heap_data[cur_size-1];
	cur_size--;
	minHeapify(0);
	return minimum;
}

// assuming zero based indexing
void minheap :: decrease_key(int node_index, int value)
{
	int index = pos[node_index];
	heap_data[index].second = value;

	while(index>=0 && heap_data[parent(index)].second > heap_data[index].second)
	{
		//swaping the positions
		pos[heap_data[parent(index)].first] = index;
		pos[heap_data[index].first] = parent(index);

		swap(heap_data[parent(index)], heap_data[index]);
		index = parent(index);
	}
}

// assuming zero based indexing
void minheap :: delete_key(int node_index)
{
	int index = pos[node_index];
	heap_data[index].second = INT_MIN;

	while(index>=0 && heap_data[parent(index)].second > heap_data[index].second)
	{
		//swaping the positions
		pos[heap_data[parent(index)].first] = index;
		pos[heap_data[index].first] = parent(index);

		swap(heap_data[parent(index)], heap_data[index]);
		index = parent(index);
	}
	extract_min();
}

void minheap :: insert_key(pp node)
{
	if(cur_size == max_size)
	{
		cout << "Overflow cannot insert\n";
		return;
	}
	
	cur_size++;
	int index = cur_size -1;
	heap_data[index] = node;
	pos[heap_data[index].first] = index;

	while(index>=0 && heap_data[parent(index)].second > heap_data[index].second)
	{
		//swaping the positions
		pos[heap_data[parent(index)].first] = index;
		pos[heap_data[index].first] = parent(index);

		swap(heap_data[parent(index)], heap_data[index]);
		index = parent(index);
	}
}

void minheap :: output_pos()
{
	for(int i=0;i<max_size; i++)
		cout << pos[i] << " ";
	cout << "\n";
}

bool minheap :: isempty()
{
	return(cur_size == 0);
}

int minheap :: get_val(int node_index)
{
	int index = pos[node_index];
	return heap_data[index].second;
}

void testing()
{
	minheap *h = new minheap(6);
	h->insert_key(pp(0,3));
    h->insert_key(pp(5,45));
    //h->delete_key(1);
    h->insert_key(pp(2,15));
    h->insert_key(pp(3,5));
    h->insert_key(pp(4,4));
    h->insert_key(pp(1,2));

    h->output_pos();

    pp x = h->extract_min();
    cout << x.first << " " << x.second << "\n";

    h->output_pos();

    h->decrease_key(2,1);

    h->output_pos();

    x = h->extract_min();
    cout << x.first << " " << x.second << "\n";
	/*

	

    
    cout << h->extract_min() << " ";
    h->decrease_key(0,1);
    cout << h->extract_min() << " ";
    cout << h->extract_min() << " ";
	*/
}