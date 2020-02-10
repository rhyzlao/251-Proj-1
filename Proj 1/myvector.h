/*myvector.h*/

// 
// <Rhyz Lao>
// U. of Illinois, Chicago
// CS 251: Fall 2019
// 
// Project #01: myvector class that mimics std::vector, but with my own
// implemenation outlined as follows:
//
// ???
//

#pragma once

#include <iostream>  // print debugging
#include <cstdlib>   // malloc, free

using namespace std;

template<typename T>
class myvector
{
private:
  T*   A;
  int  Size;
  int  Capacity;
  
  struct node { 
     T data;
     struct node* next;
  };
  
  struct node* head;
  struct node* tail;
  struct node* lastNode;
  int lastIndex;
  //node* curr;

public:

  // default constructor:
  myvector()
  {
     head = nullptr;
     tail = nullptr;
     
     lastNode = 0;
     lastIndex = -1;

     
     Size = 0;
    
  }

  // constructor with initial size:
  myvector(int initial_size)
  {
     Size = 0;
     for(int i = 0; i < initial_size; i++){
        push_back(T{});
     } 
  }

   //copy constructor for parameter passing:,
 myvector(const myvector& other)
 {
 //set my head to other head
    node* i = other.head;
    Size = 0;
    node* b = new node;
    b->data = i->data;
    node* z = b;
    Size++;
    this->head = z;
//traverse other linked list  
    while(i->next != nullptr){
       node* t = new node;
       t->data = i->next->data;
       z->next = t;
       z = z->next;
       Size++;
       i = i->next;
    }
    this->tail = z;
    z->next = nullptr;
 }

  int size()
  {   
    return Size;
  }

  T& at(int i)
  {
    node* curNode = head;
   if(i == 0){
      lastNode = head;
      lastIndex = 0;
      return head->data;
   }
   else if (i == lastIndex + 1){
      lastNode = lastNode->next;
      lastIndex++;
      return lastNode->data;
   }
   else{
      for(int x = 0; x < i; x++){
       curNode = curNode->next;
     }
     return curNode->data;
   }

  }

  void push_back(T value)
  {
     struct node* newNode = new struct node();
    newNode->data = value;
    newNode->next = nullptr;
    //condition if empty
    if(head == nullptr){
       head = newNode;
       tail = newNode;
    }
    
    else{
       tail->next = newNode;
       tail = newNode;
    }
    Size = Size + 1;
  }
  
  T erase(int i){
  node* curNode = head;
  node* preNode;
    T values;
    //check if linked list is empty
    if(curNode == nullptr){
    return values;
    }
    //head is deleted
    if(i == 1){
    head = curNode->next;
    values = curNode->data;
    delete curNode;
    Size = Size - 1;
    return values;
    }
    //traverse linked list
    for(int a = 0; a != i; a++){
        preNode = curNode;
        curNode = curNode->next;
    }
    if(curNode == nullptr){
        return values;
    }
    else{
        preNode->next = curNode->next;
        values = curNode->data;
        delete curNode;
        Size = Size - 1;
    }
    return values;
    }
  
  T& operator[](int i){
      return at(i);
  }
  
  T& rangeof(int i, int j){
      node* curNode = head;
      int ll_count = (j-i) + 1;
       T* array = new int[ll_count];

      for(int a = 0; a < i; a++){
          curNode = curNode->next;
      }  
      
      for(int b = 0; b < ll_count; b++){
          &array[b] = curNode->data;
          curNode = curNode->next;
      }
      
      return array;
  
}
  
};
