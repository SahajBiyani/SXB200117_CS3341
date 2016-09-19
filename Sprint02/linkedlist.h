#ifndef LINKED_LIST
#define LINKED_LIST

template <class T>
class ListNode {
public:

//Add functionality here to provide access to the ListNode Object. 

private:
    ListNode<T>*next;
    ListNode<T>*last;
    T data;
};


template<class T>
class LinkedList {

public:

    LinkedList();
    LinkedList(T);
    LinkedList(const LinkedList<T>&);

    void add(T);
    void addToFront(T);
    T get(int);
    int size();
    T remove(int);
    bool isEmpty();
    
    ~LinkedList();

    T& operator[] (int);
    LinkedList<T>& operator=(LinkedList<T>&);

private:

    ListNode<T>*head;
    int num_elements;

};

//Write your implementation here

#endif
