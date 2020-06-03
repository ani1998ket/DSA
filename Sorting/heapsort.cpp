#include <iostream>
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>
using std::swap;

//Zero based indexing
inline int parent( int i ) {  return ( ( i - 1) / 2 ); }
inline int left  ( int i ) {  return ( i * 2  + 1 ); }
inline int right ( int i ) {  return ( i * 2  + 2 ); }

void max_heapify( vector<int>&, int, int); 
void build_max_heap( vector<int>& arr );
void heap_sort( vector<int>& arr );

void max_heapify( vector<int>& arr, int i, int heap_size ){
    int l = left ( i );
    int r = right( i );
    int largest = i;
    
    // Swap the largest among the node and immediate children in case of a invalid node
    if( l < heap_size && arr[l] > arr[i] ){
        largest = l;
    }
    if( r < heap_size && arr[r] > arr[ largest ] ){
        largest = r;
    }

    if( largest != i ){
        swap( arr[i], arr[ largest ] );
        max_heapify( arr, largest, heap_size );
    }
}
//Binary Max Heap
void build_max_heap( vector<int>& arr ){

    // Start building from center of the array
    for( int i = arr.size() / 2 - 1; i >= 0; i-- ){
        max_heapify( arr, i, arr.size());
    }  
}

void heap_sort( vector<int>& arr ){
    build_max_heap( arr );
    int heap_size = arr.size();
    //Place the max element at the back and heapify the remaining
    for( int i = 0; i < arr.size(); i++ ){
        swap( arr[0], arr[ heap_size - 1] );
        heap_size--;
        max_heapify( arr, 0, heap_size );
    }
}

int main(){
    vector<int> arr = { 4, 10, 14, 7, 3, 2, 8, 9, 1, 16 };
    heap_sort( arr );
    for( auto i : arr ){
        cout << i << " ";
    }
}
