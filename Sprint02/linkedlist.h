#ifndef LINKED_LIST
#define LINKED_LIST

template <class T>
class ListNode {
public:
    ListNode<T>* next;
    ListNode<T>* last;
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
    ListNode<T>* head;
    int num_elements;
};

template <class T>
LinkedList<T>::LinkedList() : head(nullptr), num_elements(0) {}

template <class T>
LinkedList<T>::LinkedList(T value) {
    head = new ListNode<T>();
    head->data = value;
    head->next = nullptr;
    head->last = nullptr;
    num_elements = 1;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) {
    if (other.head == nullptr) {
        head = nullptr;
        num_elements = 0;
    } else {
        head = new ListNode<T>();
        head->data = other.head->data;
        ListNode<T>* current = head;
        ListNode<T>* otherCurrent = other.head->next;
        while (otherCurrent != nullptr) {
            current->next = new ListNode<T>();
            current->next->data = otherCurrent->data;
            current->next->last = current;
            current->next->next = nullptr;
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
        num_elements = other.num_elements;
    }
}

template <class T>
void LinkedList<T>::add(T value) {
    if (head == nullptr) {
        head = new ListNode<T>();
        head->data = value;
        head->next = nullptr;
        head->last = nullptr;
        num_elements = 1;
    } else {
        ListNode<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new ListNode<T>();
        current->next->data = value;
        current->next->last = current;
        current->next->next = nullptr;
        num_elements++;
    }
}

template <class T>
void LinkedList<T>::addToFront(T value) {
    if (head == nullptr) {
        head = new ListNode<T>();
        head->data = value;
        head->next = nullptr;
        head->last = nullptr;
        num_elements = 1;
    } else {
        ListNode<T>* newHead = new ListNode<T>();
        newHead->data = value;
        newHead->last = nullptr;
        newHead->next = head;
        head->last = newHead;
        head = newHead;
        num_elements++;
    }
}

template <class T>
T LinkedList<T>::get(int index) {
    if (index < 0 || index >= num_elements) {
        throw std::out_of_range("Index out of bounds");
    }
    ListNode<T>* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

template <class T>
int LinkedList<T>::size() {
    return num_elements;
}

template <class T>
T LinkedList<T>::remove(int index) {
    if (index < 0 || index >= num_elements) {
        throw std::out_of_range("Index out of bounds");
    }
    ListNode<T>* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    if (current->last != nullptr) {
        current->last->next = current->next;
    }
    if (current->next != nullptr) {
        current->next->last = current->last;
    }
    if (index == 0) {
        head = current->next;
    }
    T value = current->data;
    delete current;
    num_elements--;
    return value;
}

template <class T>
bool LinkedList<T>::isEmpty() {
    return num_elements == 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
    ListNode<T>* current = head;
    while (current != nullptr) {
        ListNode<T>* next = current->next;
        delete current;
        current = next;
    }
}

template <class T>
T& LinkedList<T>::operator[] (int index) {
    return get(index);
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>& other) {
    if (this == &other) {
        return *this;
    }

    // Clear the current list
    while (head != nullptr) {
        ListNode<T>* next = head->next;
        delete head;
        head = next;
    }

    if (other.head == nullptr) {
        head = nullptr;
        num_elements = 0;
    } else {
        head = new ListNode<T>();
        head->data = other.head->data;
        ListNode<T>* current = head;
        ListNode<T>* otherCurrent = other.head->next;
        while (otherCurrent != nullptr) {
            current->next = new ListNode<T>();
            current->next->data = otherCurrent->data;
            current->next->last = current;
            current->next->next = nullptr;
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
        num_elements = other.num_elements;
    }

    return *this;
}

#endif
