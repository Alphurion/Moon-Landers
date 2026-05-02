#include "priorityQ.h"

template <class t1, class t2> priorityQ<t1, t2>::priorityQ()
{
  this->capacity = 5;
  this->size = 0;
  this->heapArray = new priorityType[this->capacity + 1];
}

template <class t1, class t2> void priorityQ<t1, t2>::push_back(const t1 &key, const t2 &priority)
{
  if ((this->size) >= this->capacity)
  {
    this->capacity *= 2;
    priorityType *tempArr = new priorityType[this->capacity + 1];

    for (size_t i = 1; i <= this->size; i++)
    {
      tempArr[i].key = this->heapArray[i].key;
      tempArr[i].priority = this->heapArray[i].priority;
    }

    delete[] this->heapArray;
    this->heapArray = tempArr;
  }
  this->size++;
  this->heapArray[this->size].priority = priority;
  this->heapArray[this->size].key = key;
  itemToPQ[key] = this->size;
  bubbleUp(this->size);
}
/*
Left Child: heapArray[2*i + 1]
Right Child: heapArray[2*i + 2]
Parent of: heapArray[(i-1)/2]
*/
template <class t1, class t2> void priorityQ<t1, t2>::pop_front()
{
  this->heapArray[1] = this->heapArray[size];
  this->size -= 1;
  bubbleDown(1);
}

template <class t1, class t2>
void priorityQ<t1, t2>::update_element(const t1 &key, const t2 &priority)
{
  bool isBigger = (this->heapArray[itemToPQ[key]].priority < priority);
  this->heapArray[itemToPQ[key]].priority = priority;
  if (isBigger)
  {
    bubbleDown(itemToPQ[key]);
  }
  else
  {
    bubbleUp(itemToPQ[key]);
  }
}

template <class t1, class t2> t2 priorityQ<t1, t2>::get_front_priority() const
{
  return this->heapArray[1].priority;
}

template <class t1, class t2> t1 priorityQ<t1, t2>::get_front_key() const
{
  return this->heapArray[1].key;
}

template <class t1, class t2> t2 priorityQ<t1, t2>::get_element(t1 key)
{
  return this->heapArray[itemToPQ[key]].priority;
}

template <class t1, class t2> bool priorityQ<t1, t2>::isEmpty() const
{
  return size == 0;
}

template <class t1, class t2> void priorityQ<t1, t2>::bubbleUp(std::size_t index)
{
  /*
Left Child: heapArray[2*i + 0]
Right Child: heapArray[2*i + 1]
Parent of: heapArray[(floor(i/2))]
*/
  size_t current = index;
  size_t parent = size_t(index / 2);
  while ((this->heapArray[current].priority < this->heapArray[parent].priority) && (parent >= 1))
  {
    std::swap(this->heapArray[current], this->heapArray[parent]);
    std::swap(itemToPQ[this->heapArray[current].key], itemToPQ[this->heapArray[parent].key]);
    current = parent;
    parent = size_t(current / 2);
  }
}

template <class t1, class t2> void priorityQ<t1, t2>::bubbleDown(std::size_t index)
{
  /*
Left Child: heapArray[2*i + 0]
Right Child: heapArray[2*i + 1]
Parent of: heapArray[(floor(i/2))]
*/

  // 1 5 6 9 8 10 11 14
  // 14 5 6 9 8 10 11
  //         14
  //       5     6
  //     9   8  10 11
  //  k1 [1] 14   -> [2]
  //  k2 [2] 5    -> [1]
  // [k1] -> 1
  // [k2] -> 2
  size_t parent = index;
  size_t LChild = 2 * index, RChild = 2 * index + 1;

  while (LChild <= this->size)
  {
    if (heapArray[LChild].priority < heapArray[parent].priority ||
        (RChild <= this->size && heapArray[RChild].priority < heapArray[parent].priority))
    {
      if (RChild <= this->size && heapArray[RChild].priority < heapArray[LChild].priority)
      {
        std::swap(heapArray[RChild], heapArray[parent]);
        std::swap(itemToPQ[heapArray[RChild].key], itemToPQ[heapArray[parent].key]);
        parent = RChild;
      }
      else
      {
        std::swap(heapArray[LChild], heapArray[parent]);
        std::swap(itemToPQ[heapArray[LChild].key], itemToPQ[heapArray[parent].key]);
        parent = LChild;
      }
    }
    LChild = 2 * parent;
    RChild = 2 * parent + 1;
  }
}

template class priorityQ<std::string, int>;
template class priorityQ<std::string, lander>;
