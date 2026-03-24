#include <string>

template <typename T>
LinkedQueue<T>::LinkedQueue() : head(nullptr), last(nullptr) {
}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& copyObj) : head(nullptr), last(nullptr) {
    copy(copyObj);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template <typename T>
T LinkedQueue<T>::back() const {
    if (isEmpty()) {
        throw std::string("back: error, queue is empty, cannot access the back");
    }
    return last->value;
}

template <typename T>
void LinkedQueue<T>::clear() {
    while (head != nullptr) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }
    last = nullptr;
    this->length = 0;
}

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
    Node* src = copyObj.head;
    while (src != nullptr) {
        enqueue(src->value);
        src = src->next;
    }
}

template <typename T>
void LinkedQueue<T>::dequeue() {
    if (isEmpty()) {
        throw std::string("Queue is empty");
    }
    Node* toDelete = head;
    head = head->next;
    delete toDelete;
    this->length--;
    if (head == nullptr) {
        last = nullptr;
    }
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
    Node* newNode = new Node(elem, nullptr);
    if (last == nullptr) {
        head = last = newNode;
    } else {
        last->next = newNode;
        last = newNode;
    }
    this->length++;
}

template <typename T>
T LinkedQueue<T>::front() const {
    if (isEmpty()) {
        throw std::string("front: error, queue is empty, cannot access the front");
    }
    return head->value;
}

template <typename T>
int LinkedQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return this->length == 0;
}
