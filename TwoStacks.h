// Assignment 2, exercise 2
#pragma once
#include <cstdio>
#include <stdexcept>

template <class T>
class TwoStacks {
  public:
  // Constructor, initialize the array to size_hint
  TwoStacks(size_t size_hint = 16) : size_(size_hint), array_(new T(size_hint)) {}
  // Destructor
  ~TwoStacks() { delete array_;}

  // Push a value to the first stack
  void push_first(const T& val);

  // Push a value to the second stack
  void push_second(const T& val);

  // Pop from the first stack and return the value
  T pop_first();

  // Pop from the second stack and return the value
  T pop_second();

  // Return the size of the first stack
  size_t size_first() const ;

  // Return the size of the second stack
  size_t size_second() const ;

  // Return true if the first stack is empty
  bool empty_first() const { return size_first() == 0; }

  // Return true if the second stack is empty
  bool empty_second() const { return size_second() == 0; }

  private:
  size_t size_;
  T *array_;

  int firstTop = 0;
  int secondTop = size_ -1;
};
