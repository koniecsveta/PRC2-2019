#ifndef __LIST_H__
#define __LIST_H__

const unsigned MAX_LENGTH = 500;

typedef int ItemType;

class List {
public:

  // Default constructor
  // Initialize an empty List instance.
  List();


  // Check if a List instance is empty.
  bool empty() const;

  //Check if a List instance is full.
  bool full() const;


  // Get the number of items in a List instance.
  unsigned length() const;


  // Insert an item into a List instance.
  void insert(ItemType x);


  // Remove an item from a List instance.
  void remove(ItemType x);


  //  Test if an item is a member of a List instance.
  bool search(ItemType x) const;


  //  Print the members of a List instance.
  void print() const;

private:

  unsigned data_count;
  ItemType data[MAX_LENGTH];

};

#endif
