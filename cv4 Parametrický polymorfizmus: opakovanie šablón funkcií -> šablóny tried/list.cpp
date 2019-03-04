#include <iostream>
#include <cassert>

using namespace std;

#include "list.h"

List::List() {
  // List is initially empty
  data_count = 0;
}

bool List::empty() const {
  // List is empty when size is zero
  return data_count == 0;
}

bool List::full() const {
  // List is full when size is MAX_LENGTH
  return data_count == MAX_LENGTH;
}

unsigned List::length() const {
  return data_count;
}

void List::insert(ItemType x) {
  // Enforce precondition
  assert( ! full() );
  // Previously inserted elements are stored in the 
  // subarray data[0:data_count]. Next empty location
  // is at data[data_count].
  data[data_count] = x;
  // Update size of List
  ++data_count;
}


// Purpose: Locate the first occurrence of x in the array A.
// Argument(s):
//   x : An ItemType item to be sought for.
//   A : An array of ItemType in which the search is to be conducted.
//   N : An unsigned integer indicating the scope of the search.
// Return: If x occurs in A[0:N], then the index of the first 
//         occurrence will be returned.  Otherwise, N will be returned.
static unsigned find(ItemType x, const ItemType A[], unsigned N) {
  unsigned i;
  for (i = 0; i < N; i++)
    if (x == A[i])
      return i;
  return N;
}

void List::remove(ItemType x) {

  // Locate items to be deleted

  unsigned i = find(x, data, data_count);

  // If no such item can be located then return

  if (i == data_count)
    return;

  // Overwrite deleted item by last element of the array

  data[i] = data[data_count - 1];

  // Update size

  data_count--;
}

bool List::search(ItemType x) const {
  return find(x, data, data_count) != data_count;
}


// Purpose: Copy the content of array A to array B.
// Argument(s):
//   A : An array of ItemType from which elements are copied.
//   B : An array of ItemType to which elements are copied.
//   N : Common size of arrays A and B.
// Side Effect: Array B[0:N] will contain an exact duplicate
//              of the content of A[0:N].
// Return: N/A.
static void copy(const ItemType A[], ItemType B[], unsigned N) {
  for (unsigned i = 0; i < N; i++)
    B[i] = A[i];
}

// Purpose: Find the index of the minimum element in a subarray of A.
// Argument(s):
//   A : An array of ItemType in which the subarray is embedded.
//   begin : The index of the first element in the subarray.
//   end : The index of the first element beyond the subarray.
// Precondition(s): begin <= end
// Return: Index of the minimum element in the subarray A[begin..end].
//
static unsigned min(const ItemType A[], unsigned begin, unsigned end) {
  assert(begin <= end);
  unsigned m = begin;
  for (unsigned i = begin + 1; i < end; i++)
    if (A[m] > A[i])
      m = i;
  return m;
}


// Purpose: Swap the values of two ItemType variables.
// Argument(s):
//  x : Reference to an ItemType variable.
//  y : Reference to another ItemType variable.
// Side Effect: The values of x and y will be swapped.
// Return: N/A.
static void swap(ItemType& x, ItemType& y) {
  ItemType tmp = x;
  x = y;
  y = tmp;
}


// Purpose: Sort array A in ascending order.
// Argument(s):
//   A : An array of ItemType to which sorting is performed.
//   N : The size of array A.
// Side Effect: A[0:N] is sorted in ascending order.
static void sort(ItemType A[], unsigned N) {
  for (unsigned i = 0; i < N; i++) {
    unsigned m = min(A, i, N);
    swap(A[i], A[m]);
  }
}

void List::print() const {

  // Create a duplicate of the data array

  ItemType B[MAX_LENGTH];
  copy(data, B, data_count);

  // Sort the duplicate

  sort(B, data_count);

  // Print the sorted duplicate
  
  for (unsigned i = 0; i < data_count; i++) {
    if (i != 0)
      cout << ", ";  // comma separation for all but the first member
    cout << B[i];
  }
}

