#include "TwoStacks.h"
#include <iostream>
using namespace std;


// Push a value to the first stack
template <class T>
void TwoStacks<T>::push_first(const T& val) {
    //cout << "1: " << firstCount << ", 2: " << secondCount << endl;
    if (firstCount+ secondCount == size_){
        doubleSize();
    }  
    
    //std::cout << "pushing to first at = " << firstCount << endl;
    array_[firstCount++] = val; 
}

// Push a value to the second stack
template <class T>
void TwoStacks<T>::push_second(const T& val) {
    int size = size_;
    //cout << "1: " << firstCount << ", 2: " << secondCount << endl;
    if (firstCount+ secondCount == size_){
        doubleSize();
    }  

    //cout << "pushing to second at = " << size-secondCount-1 << endl;
    array_[size - secondCount -1] = val;
    secondCount ++;
    
}

// Pop from the first stack and return the value
template <class T>
T TwoStacks<T>::pop_first() {
  try{
    T elem = array_[firstCount-1];
    array_[firstCount-1] = 0;
    firstCount--;
    //cout << "returning " << elem << endl;
    return elem;
  }catch (const std::out_of_range& e){
    //cout << "First Stack is empty" << endl;
    return -1;
  }
}

// Pop from the second stack and return the value
template <class T>
T TwoStacks<T>::pop_second() {
  try{
    T elem = array_[size_ - secondCount];
    array_[size_ - secondCount] = 0;
    secondCount--;
    //cout << "returning " << elem << endl;
    return elem;
  }catch (const std::out_of_range& e){
    //cout << "Second Stack is empty" << endl;
    return -1;
  }
}


template<class T>
void TwoStacks<T>::printStacks(){
  //cout << "-----------" << endl;
  for (int i = 0; i < size_; i++){
    cout << array_[i] << endl;
  }
}

template<class T>
void TwoStacks<T>::doubleSize(){
    //cout << "double called" << endl;
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

    array_ = bigArray;
    size_ = newSize;
    //std::cout << "newSize = " << newSize << std::endl;
}

// Return the size of the first stack
template <class T>
size_t TwoStacks<T>::size_first() const {
  return firstCount;
}
// Return the size of the second stack, -1 bc starting from the back off array = size-1
template <class T>
size_t TwoStacks<T>::size_second() const {
    return secondCount;
}