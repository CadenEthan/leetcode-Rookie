// 单链表
#include<iostream>
#include<stdexcept>
#include<string>
#include<vector>
using namespace std;

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

int main(){ 
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.print();
    return 0;
}