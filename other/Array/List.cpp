#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// ==================== 1. 动态数组 (Dynamic Array) ====================
template<typename T>
class DynamicArray {
private:
    T* data; // 门牌号，指向数组的首地址
    int size; // 数组中元素的个数
    int capacity; // 数组的总容量
    // 扩容函数，当数组满时，扩容为原来的两倍
    void resize(int newCapacity) {
        T* newData = new T[newCapacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
    
public:
    // 构造函数
    DynamicArray() : data(nullptr), size(0), capacity(0) {}
    
    DynamicArray(int initialCapacity) : size(0), capacity(initialCapacity) {
        data = new T[capacity];
    }
    
    // 析构函数
    ~DynamicArray() {
        delete[] data;
    }
    
    // 增 - 在末尾添加元素
    void push_back(const T& element) {
        if (size >= capacity) {
            // 如果数组为空，则初始化为1，否则扩容为原来的两倍
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        data[size++] = element;
    }
    
    // 增 - 在指定位置插入元素
    void insert(int index, const T& element) {
        if (index < 0 || index > size) {
            throw out_of_range("Index out of range");
        }
        
        if (size >= capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        
        for (int i = size; i > index; i--) {
            data[i] = data[i-1];
        }
        data[index] = element;
        size++;
    }
    
    // 删 - 删除末尾元素
    T pop_back() {
        if (size == 0) {
            // 如果数组为空，则抛出异常
            throw out_of_range("Array is empty");
        }
        return data[--size];
    }
    
    // 删 - 删除指定位置的元素
    T remove(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        
        T element = data[index];
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i+1];
        }
        size--;
        return element;
    }
    
    // 改 - 修改指定位置的元素
    void set(int index, const T& element) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        data[index] = element;
    }
    
    // 查 - 获取指定位置的元素
    T& get(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }
    
    // 查 - 查找元素是否存在
    bool contains(const T& element) {
        for (int i = 0; i < size; i++) {
            if (data[i] == element) {
                return true;
            }
        }
        return false;
    }
    
    // 查 - 查找元素索引
    int indexOf(const T& element) {
        for (int i = 0; i < size; i++) {
            if (data[i] == element) {
                return i;
            }
        }
        return -1;
    }
    
    // 其他辅助方法
    int getSize() const { return size; }
    bool isEmpty() const { return size == 0; }
    void clear() { size = 0; }
    
    // 重载[]操作符
    T& operator[](int index) {
        return get(index);
    }
    
    // 打印数组
    void print() {
        cout << "[";
        for (int i = 0; i < size; i++) {
            cout << data[i];
            if (i < size - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
};

// ==================== 2. 双向链表 (Doubly Linked List) ====================
template<typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;
    
    Node(T data) : data(data), next(nullptr), prev(nullptr) {}
};

template<typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
    
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    
    ~DoublyLinkedList() {
        clear();
    }
    
    // 增 - 在末尾添加元素
    void push_back(const T& data) {
        Node<T>* newNode = new Node<T>(data);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    
    // 增 - 在开头添加元素
    void push_front(const T& data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }
    
    // 增 - 在指定位置插入元素
    void insert(int index, const T& data) {
        if (index < 0 || index > size) {
            throw out_of_range("Index out of range");
        }
        
        if (index == 0) {
            push_front(data);
            return;
        }
        
        if (index == size) {
            push_back(data);
            return;
        }
        
        Node<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        
        Node<T>* newNode = new Node<T>(data);
        newNode->prev = current->prev;
        newNode->next = current;
        current->prev->next = newNode;
        current->prev = newNode;
        size++;
    }
    
    // 删 - 删除末尾元素
    T pop_back() {
        if (tail == nullptr) {
            throw out_of_range("List is empty");
        }
        
        T data = tail->data;
        if (head == tail) {
            delete tail;
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
        size--;
        return data;
    }
    
    // 删 - 删除开头元素
    T pop_front() {
        if (head == nullptr) {
            throw out_of_range("List is empty");
        }
        
        T data = head->data;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
        }
        size--;
        return data;
    }
    
    // 删 - 删除指定位置的元素
    T remove(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        
        if (index == 0) {
            return pop_front();
        }
        
        if (index == size - 1) {
            return pop_back();
        }
        
        Node<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        
        T data = current->data;
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        size--;
        return data;
    }
    
    // 改 - 修改指定位置的元素
    void set(int index, const T& data) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        
        Node<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->data = data;
    }
    
    // 查 - 获取指定位置的元素
    T& get(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        
        Node<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }
    
    // 查 - 查找元素是否存在
    bool contains(const T& data) {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == data) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    
    // 查 - 查找元素索引
    int indexOf(const T& data) {
        Node<T>* current = head;
        int index = 0;
        while (current != nullptr) {
            if (current->data == data) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;
    }
    
    // 其他辅助方法
    int getSize() const { return size; }
    bool isEmpty() const { return size == 0; }
    
    void clear() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }
    
    // 打印链表
    void print() {
        Node<T>* current = head;
        cout << "[";
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) cout << " <-> ";
            current = current->next;
        }
        cout << "]" << endl;
    }
};

// ==================== 3. 栈 (Stack) ====================
template<typename T>
class Stack {
private:
    DynamicArray<T> data;
    
public:
    // 增 - 入栈
    void push(const T& element) {
        data.push_back(element);
    }
    
    // 删 - 出栈
    T pop() {
        return data.pop_back();
    }
    
    // 查 - 查看栈顶元素
    T& peek() {
        if (data.isEmpty()) {
            throw out_of_range("Stack is empty");
        }
        return data.get(data.getSize() - 1);
    }
    
    // 其他方法
    int size() const { return data.getSize(); }
    bool isEmpty() const { return data.isEmpty(); }
    void clear() { data.clear(); }
    
    // 打印栈
    void print() {
        cout << "Stack (top to bottom): ";
        data.print();
    }
};

// ==================== 4. 队列 (Queue) ====================
template<typename T>
class Queue {
private:
    DoublyLinkedList<T> data;
    
public:
    // 增 - 入队
    void enqueue(const T& element) {
        data.push_back(element);
    }
    
    // 删 - 出队
    T dequeue() {
        return data.pop_front();
    }
    
    // 查 - 查看队首元素
    T& front() {
        if (data.isEmpty()) {
            throw out_of_range("Queue is empty");
        }
        return data.get(0);
    }
    
    // 查 - 查看队尾元素
    T& back() {
        if (data.isEmpty()) {
            throw out_of_range("Queue is empty");
        }
        return data.get(data.getSize() - 1);
    }
    
    // 其他方法
    int size() const { return data.getSize(); }
    bool isEmpty() const { return data.isEmpty(); }
    void clear() { data.clear(); }
    
    // 打印队列
    void print() {
        cout << "Queue (front to back): ";
        data.print();
    }
};

// ==================== 测试函数 ====================
void testDynamicArray() {
    cout << "=== 测试动态数组 ===" << endl;
    DynamicArray<int> arr;
    
    // 增
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.insert(1, 5);
    cout << "插入后: ";
    arr.print();
    
    // 查
    cout << "索引1的元素: " << arr.get(1) << endl;
    cout << "包含2: " << (arr.contains(2) ? "是" : "否") << endl;
    cout << "2的索引: " << arr.indexOf(2) << endl;
    
    // 改
    arr.set(0, 10);
    cout << "修改后: ";
    arr.print();
    
    // 删
    cout << "删除索引1: " << arr.remove(1) << endl;
    cout << "删除后: ";
    arr.print();
    
    cout << endl;
}

void testDoublyLinkedList() {
    cout << "=== 测试双向链表 ===" << endl;
    DoublyLinkedList<int> list;
    
    // 增
    list.push_back(1);
    list.push_back(2);
    list.push_front(0);
    list.insert(2, 5);
    cout << "插入后: ";
    list.print();
    
    // 查
    cout << "索引1的元素: " << list.get(1) << endl;
    cout << "包含2: " << (list.contains(2) ? "是" : "否") << endl;
    cout << "2的索引: " << list.indexOf(2) << endl;
    
    // 改
    list.set(0, 10);
    cout << "修改后: ";
    list.print();
    
    // 删
    cout << "删除开头: " << list.pop_front() << endl;
    cout << "删除后: ";
    list.print();
    
    cout << endl;
}

void testStack() {
    cout << "=== 测试栈 ===" << endl;
    Stack<int> stack;
    
    // 增
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << "入栈后: ";
    stack.print();
    
    // 查
    cout << "栈顶元素: " << stack.peek() << endl;
    
    // 删
    cout << "出栈: " << stack.pop() << endl;
    cout << "出栈后: ";
    stack.print();
    
    cout << endl;
}

void testQueue() {
    cout << "=== 测试队列 ===" << endl;
    Queue<int> queue;
    
    // 增
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    cout << "入队后: ";
    queue.print();
    
    // 查
    cout << "队首元素: " << queue.front() << endl;
    cout << "队尾元素: " << queue.back() << endl;
    
    // 删
    cout << "出队: " << queue.dequeue() << endl;
    cout << "出队后: ";
    queue.print();
    
    cout << endl;
}

int main() {
    cout << "C++数据结构增删改查API演示" << endl;
    cout << "================================" << endl;
    
    testDynamicArray();
    testDoublyLinkedList();
    testStack();
    testQueue();
    
    return 0;
}