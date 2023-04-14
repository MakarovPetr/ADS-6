// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
 private:
int first;
int last;
int count;
T* arr;

 public:
TPQueue() :first(0), last(0), count(0) { arr = new T[size]; }
bool isEmpty() const {
return 0 == count;
}
bool isFull() const {
return size == count;
}
void push(const T& value) {
if (isFull())
throw std::string("is Full!");
else {
int flag = last; 
}
for (int i = first; i < last;i++) {
if (value.prior > arr[i].prior) {
flag = i;
break; 
}
}
for (int i = last; i < flag;i--) {
arr[i % size] = arr[(i - 1) % size];
}
arr[flag % size] = value;
count++;
last++;
}
}
const T& pop() {
if (isEmpty()) {
throw std::string("Empty!");
} else {
count--;
return arr[first++ % size];
}
}
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
