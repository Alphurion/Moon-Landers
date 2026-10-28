// Headers
#include "lander.h"
//Libraries
#include <unordered_map>
#include <cstdlib>
#include <string>

#ifndef PRIORITY_Q
#define PRIORITY_Q
/*
void push_back(const t1 &, const t2 &): Adds an element to the priority queue
void pop_front(): Removes the element with the highest priority from the queue
void update_element(const t1 &, const t2 &): Updates the priority of an element in the queue
t2 get_element(t1): Returns the priority of an element in the queue
t2 get_front_priority() const: Returns the priority of the element with the highest priority in the queue
t1 get_front_key() const: Returns the key of the element with the highest priority in the queue
bool isEmpty() const: Returns true if the queue is empty, false otherwise
*/
template <class t1, class t2> class priorityQ
{
public:
  priorityQ();

  ~priorityQ()
  {
    delete[] heapArray;
  }

  void push_back(const t1 &, const t2 &);
  void pop_front();
  void update_element(const t1 &, const t2 &);

  t2 get_element(t1);
  t2 get_front_priority() const;
  t1 get_front_key() const;
  bool isEmpty() const;

private:
  class priorityType
  {
  public:
    t1 key;
    t2 priority;

    priorityType() : key(t1()), priority(t2())
    {
    }
    priorityType(t1 k, t2 v) : key(k), priority(v)
    {
    }
  };

  void bubbleUp(std::size_t);
  void bubbleDown(std::size_t);

  priorityType *heapArray;
  std::size_t size;
  std::size_t capacity;
  std::unordered_map<t1, std::size_t> itemToPQ;
};

#endif
