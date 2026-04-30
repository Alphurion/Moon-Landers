#include "priorityQ.h"

template <class t1, class t2>
priorityQ<t1, t2>::priorityQ()
{

}

template <class t1, class t2>
void priorityQ<t1, t2>::push_back(const t1& key, const t2& priority)
{

}

template <class t1, class t2>
void priorityQ<t1, t2>::pop_front()
{

}

template <class t1, class t2>
void priorityQ<t1, t2>::update_element(const t1& key, const t2& priority)
{

}

template <class t1, class t2>
t2 priorityQ<t1, t2>::get_front_priority() const
{

}

template <class t1, class t2>
t1 priorityQ<t1, t2>::get_front_key() const
{

}

template <class t1, class t2>
t2 priorityQ<t1, t2>::get_element(t1 key)
{

}

template <class t1, class t2>
bool priorityQ<t1, t2>::isEmpty() const
{

}


template <class t1, class t2>
void priorityQ<t1, t2>::bubbleUp(std::size_t index)
{

}


template <class t1, class t2>
void priorityQ<t1, t2>::bubbleDown(std::size_t index)
{

}

template class priorityQ<std::string, int>;
template class priorityQ<std::string, lander>;
