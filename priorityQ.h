#include <unordered_map>
#include <cstdlib>
#include <string>
#include "lander.h"

#ifndef PRIORITY_Q
#define PRIORITY_Q

template <class t1, class t2>
class priorityQ
{
public:
    priorityQ();

    ~priorityQ() { delete [] heapArray; }

    void push_back(const t1&, const t2&);
    void pop_front();
    void update_element(const t1&, const t2&);

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

    priorityType() : key(t1()), priority(t2()) {}
    priorityType(t1 k, t2 v) : key(k), priority(v) {}
  };

  void bubbleUp(std::size_t);
  void bubbleDown(std::size_t);

  priorityType * heapArray;
  std::size_t size;
  std::size_t capacity;
  std::unordered_map<t1, std::size_t> itemToPQ;
};

#endif
