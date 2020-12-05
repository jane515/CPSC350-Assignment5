//Jane Yang
//2317614
//huayang@chapman.edu
//CPSC350-01
//Assignment 4
#include "ListNode.h"
#include <iostream>
using namespace std;
template <class t>
class DoubleList
{

public:
  ListNode<t>* front;
  ListNode<t> *back;
  unsigned int size;
  DoubleList();
  ~DoubleList();
  void insertFront(t d);
  void insertBack(t d);
  int find(t d);
  t removeFront();
  t removeBack();
  t getFront();
  ListNode<t>* remove(t d);
  t deletePos(int pos);
  //bool isEmpty();

  void printList();
  t printElement(int num);
  unsigned int getSize();
};
template <class t>
DoubleList<t>::DoubleList()
{
  typedef ListNode<t> Node;
  size=0;
  front=NULL;
  back=NULL;
}
template <class t>
DoubleList<t>::~DoubleList(){}

template <class t>
t DoubleList<t>::deletePos(int pos)
{
  ListNode<t> *curr=front;
  int count=0;
  while(count!=pos){
    curr=curr->next;
    count++;
  }
  return curr->data;
}
/*
template<class t>
bool DoubleList<t>::isEmpty()
{
  return(size==0);
}*/
template <class t>
int DoubleList<t>::find(t d)
{
  ListNode<t> *curr=front;
  int counter=0;
  if(curr->data==d){
    return counter;
  }
  while(curr->next!=NULL){
    counter++;
    curr=curr->next;
    if(curr->data==d){
      return counter;
    }
  }
  return -1;
}

template <class t>
void DoubleList<t>::insertFront(t d)
{
  ListNode<t> *node = new ListNode<t>(d);
  if(size==0){
    back=node;
  }
  else{
  node->next=front;
  front->prev=node;
}
front=node;
size++;
}

template <class t>
t DoubleList<t>::removeFront()
{
  ListNode<t> *f=front;
  if(front->next==NULL){

    back=NULL;
  }
  else{
    front->next->prev=NULL;
  }
  front=front->next;
  t temp =f->data;
  f->next=NULL;
  size--;
  delete f;
  return temp;
}

template <class t>
void DoubleList<t>::insertBack(t d)
{
  ListNode<t> *node = new ListNode<t>(d);
  if(size==0){
    front=node;
  }
  else{
  back->next=node;
  node->prev=back;
}
back=node;
size++;
}

template <class t>
t DoubleList<t>::removeBack()
{
  if(size==1){
    removeFront();
  }
  else{
    ListNode<t> *b=back;
    back=back->prev;
    b->prev=NULL;
    b->prev->next=NULL;
    t temp=b->data;
    delete b;
    size--;
    return temp;
  }
}

template <class t>
ListNode<t>* DoubleList<t>::remove(t d)
{
  ListNode<t> *curr=front;
  while(curr->data != d){
    curr=curr->next;
    if(curr==NULL){
      return NULL;
    }
  }
  if (curr==front){
    front=curr->next;
  }
  else
  {
      curr->prev->next=curr->next;
  }
  if(curr==back){
    back=curr->prev;
  }
  else{
    curr->next->prev=curr->prev;
  }
  curr->next=NULL;
  curr->prev=NULL;
  size--;
  return curr;
}

template <class t>
t DoubleList<t>::getFront()
{
  ListNode<t> *curr=front;
  t answer=curr->data;
  return answer;
}

template <class t>
void DoubleList<t>::printList()
{
  ListNode<t> *curr=front;
  while(curr!= NULL){
    cout<<curr->data<<endl;
    curr = curr->next;
  }
}

template <class t>
t DoubleList<t>::printElement(int num)
{
  int count=0;
  ListNode<t> *curr=front;
  while(count< num){
    curr = curr->next;
    count++;
  }
  return curr->data;
}

template <class t>
unsigned int DoubleList<t>::getSize()
{
  return size;
}
