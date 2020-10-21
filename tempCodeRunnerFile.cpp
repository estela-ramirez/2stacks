#include <cstdio>
#include <stdexcept>
using namespace std;

template <class T>
class TwoStacks {
  public:
  // Constructor, initialize the array to size_hint
  TwoStacks(size_t size_hint = 16) : size_(size_hint), array_(new T(size_hint)) {}
  // Destructor
  ~TwoStacks() { delete array_; }

  // Push a value to the first stack
  void push_first(const T& val) {
    cout << "1: " << firstCount << ", 2: " << secondCount << endl;
    if (firstCount+ secondCount == size_){
        doubleSize();
    }  
    
    std::cout << "pushing to first at = " << firstCount << endl;
    array_[firstCount++] = val;
  }

  // Push a value to the second stack
  void push_second(const T& val) {
    int size = size_;
    cout << "1: " << firstCount << ", 2: " << secondCount << endl;
    if (firstCount+ secondCount == size_){
        doubleSize();
    }  

    cout << "pushing to second at = " << size-secondCount-1 << endl;
    array_[size - secondCount -1] = val;
    secondCount ++;
  }

  // Pop from the first stack and return the value
  T pop_first() {
    try{
      T elem = array_[firstCount-1];
      array_[firstCount-1] = 0;
      firstCount--;
      cout << "returning " << elem << endl;
      return elem;
    }catch (const std::out_of_range& e){
      cout << "First Stack is empty" << endl;
      return -1;
    }
  }

  // Pop from the second stack and return the value
  T pop_second() {
    try{
      T elem = array_[size_ - secondCount];
      array_[size_ - secondCount] = 0;
      secondCount--;
      cout << "returning " << elem << endl;
      return elem;
    }catch (const std::out_of_range& e){
      cout << "Second Stack is empty" << endl;
      return -1;
    }
  }

  // Return the size of the first stack
  size_t size_first() const {
    return firstCount;
  }

  // Return the size of the second stack
  size_t size_second() const {
    return secondCount;
  }

  // Return true if the first stack is empty
  bool empty_first() const { return size_first() == 0; }

  // Return true if the second stack is empty
  bool empty_second() const { return size_second() == 0; }

  void printStacks(){
    cout << "-----------" << endl;
    for (int i = 0; i < size_; i++){
      cout << array_[i] << endl;
    }
  }

  void doubleSize(){
    cout << "double called" << endl;
    printStacks();
    int newSize = size_*2;
    T *bigArray = new T(newSize);

    // copy elements from first stack
    for (int i = 0; i < firstCount; i++){
      bigArray[i] = array_[i];
    }

    //copy elements from second stack
    for (int i = 0; i < secondCount; i++){
      bigArray[newSize-1-i] = array_[size_-1-i];
    }

    delete array_;
    array_ = bigArray;
    size_ = newSize;
    std::cout << "newSize = " << newSize << std::endl;
  }


  private:
  size_t size_;
  T *array_;

  int firstCount = 0;
  int secondCount = 0;
};


int main(){
    size_t a = 6;
    TwoStacks<size_t>s(a);    

    
    s.push_second(20);
    s.push_second(19);
    s.push_second(18);

    s.push_first(1);
    s.push_first(2);
    s.push_first(3);
    s.push_first(4);
    s.push_first(5);

    cout << s.size_first() << endl;
    cout << s.size_second() << endl;
    s.printStacks();

    s.pop_first();
    s.pop_second();

    cout << s.size_first() << endl;
    cout << s.size_second() << endl;
    s.printStacks();
    

    return 0;
  
}