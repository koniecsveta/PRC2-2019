#ifndef __LIST_H__
#define __LIST_H__

template <typename ItemType>
struct Node {
    ItemType datum;
    Node *next;
};

template <typename ItemType>
class List {
public:
    // default constructor, copy constructor, assignment oerator, decsrutor
    List();
    List(const List& L);
    List& operator=(const List& L);
    ~List();


    //Check if a List instance is empty.
    bool empty() const;

    // Get the number of items in a List instance.
    unsigned length() const;

    //Insert an item into a List instance.
    void insert(const ItemType& x);

    // Remove an item from a List instance.
    void remove(const ItemType& x);

    // Test if an item is a member of a List instance.
    bool search(const ItemType& x) const;

    // Print the members of a List instance.
    void print() const;

private:

    Node<ItemType> *head;

};

template <typename ItemType>
static void deleteList(Node<ItemType> *head) {
    Node<ItemType> *current = 0;
    Node<ItemType> *next = head;
    while (next != 0) {
        current = next;
        next = current->next;
        delete current;
    }
}

template <typename ItemType>
static Node<ItemType> *duplicateList(Node<ItemType> *head) {
    if (head == 0)
        return 0;
    Node<ItemType> *H = new Node<ItemType>;
    Node<ItemType> *prev = H;
    H->datum = head->datum;
    for (Node<ItemType> *p = head->next; p != 0; p = p->next) {
        prev->next = new Node<ItemType>;
        prev->next->datum = p->datum;
        prev = prev->next;
    }
    prev->next = 0;
    return H;
}

template <typename ItemType>
List<ItemType>::List() {
    head = 0;
}

template <typename ItemType>
List<ItemType>::List(const List& L) {
    head = duplicateList(L.head);
}

template <typename ItemType>
List<ItemType>& List<ItemType>::operator=(const List& L) {
    if (&L != this) {
        Node<ItemType> *H = duplicateList(L.head);
        deleteList(head);
        head = H;
    }
    return *this;
}

template <typename ItemType>
List<ItemType>::~List() {
    deleteList(head);
}

template <typename ItemType>
bool List<ItemType>::empty() const {
    return head == 0;
}

template <typename ItemType>
unsigned List<ItemType>::length() const {
    unsigned len = 0;
    for (Node<ItemType> *p = head; p != 0; p = p->next)
        len++;
    return len;
}

template <typename ItemType>
void List<ItemType>::print() const {
    for (Node<ItemType> *p = head; p != 0; p = p->next) {
        cout << p->datum;
        if (p->next != 0)
            cout << ", ";
    }
    cout << endl;
}



//  locates where an item should be inserted.
// Argument(s):
//   x = item to search for
//   head = pointer to first node of the list, or null if list is empty
// Return:
//   Return the pointer to the node for which the datum is
//   strictly smaller than x, and for which there is either
//   no successor or else the successor has a datum no smaller
//   than x.  If such a node does not exist, then the null
//   pointer is returned.  There are two cases in which this is
//   true: (1) the list is empty, and (2) the item x is smaller
//   than every item in the list.  In either case, x should be
//   inserted in front of the head node.
template <typename ItemType>
static Node<ItemType> *searchList(const ItemType& x, Node<ItemType> *head) {
    Node<ItemType> *prev = 0;
    Node<ItemType> *curr = head;
    while (curr != 0 && curr->datum < x) {
        prev = curr;
        curr = curr->next;
    }
    return prev;
}

template <typename ItemType>
void List<ItemType>::insert(const ItemType& x) {

    // find out where to insert
    Node<ItemType> *prev = searchList(x, head);

    // create new node
    Node<ItemType> *H = new Node<ItemType>;
    H->datum = x;

    // insert
    if (prev != 0) {
        H->next = prev->next;
        prev->next = H;
    } else {
        H->next = head;
        head = H;
    }
}

template <typename ItemType>
bool List<ItemType>::search(const ItemType& x) const {
    Node<ItemType> *prev = searchList(x, head);
    if (prev != 0)
        return prev->next != 0 && prev->next->datum == x;
    else
        return head != 0 && head->datum == x;
}

template <typename ItemType>
void List<ItemType>::remove(const ItemType& x) {

    // find out where to remove
    Node<ItemType> *prev = searchList(x, head);

    // 2 cases: Target has a predecessor or not
    if (prev != 0) {
        // target has a predecessor

        // see if target is actually in list
        if (prev->next == 0 || prev->next->datum != x)
            return;

        // remove
        Node<ItemType> *p = prev->next;
        prev->next = p->next;
        delete p;

    } else {
        // target doesn't have a predecessor

        // see if target is actually in list
        if (head == 0 || head->datum != x)
            return;

        // remove
        Node<ItemType> *p = head;
        head = p->next;
        delete p;

    }
}

#endif