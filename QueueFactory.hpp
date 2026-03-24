#ifndef QUEUE_FACTORY_HPP
#define QUEUE_FACTORY_HPP

#include "ArrayQueue.hpp"
#include "LinkedQueue.hpp"
#include "Queue.hpp"

class QueueFactory {
public:
    static Queue<int>* GetQueue() { return new LinkedQueue<int>(); }

    static Queue<int>* GetQueue(int capacity) { return new ArrayQueue<int>(capacity); }
};

#endif
