```c++
// 所有的数据结构的模板类  单一指责/开闭原则/依赖倒置
class DataStructure {
public:
    // Create (增)
    void insert(const T& element);
    void push_back(const T& element);
    
    // Read (查)
    T& get(int index);
    bool contains(const T& element);
    
    // Update (改)
    void set(int index, const T& element);
    
    // Delete (删)
    T remove(int index);
    void clear();
};
```