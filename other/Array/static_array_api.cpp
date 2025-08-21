/**
 * 现在就是这样：如果说我想实现一个静态数组的 api，使用 c++
 * 
 *  我的思路是这样的：是用 class 来 定义数组
    类型 内容 大小  使用私有的属性



    其他的方法使用公共的属性供外界调
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */
 #include<iostrem>
 #include<stdexcept>
 #include<string>

 using namespace std;

 template<typename T, int N>
 class StaticArray {
    private:
        T data[N]; // 数组的内容
        int size; // 数组中元素的个数
    public:
        StaticArray():size(0){}

        // craete
        void push_back(const T& element){
            if(size >= N){
                throw out_of_range("Array is full");
            }
            data[size++] = element;
        }

        // read
        T& get(int index){
            if(index < 0 || index >= size){
                throw out_of_range("Index out of range");
            }
            return data[index];
        }
 }

 int main(){
 }