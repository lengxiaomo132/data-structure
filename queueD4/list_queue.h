// list_queue.h
#pragma once
#include "../dlistD3/my_dlist.h"

class ListQueue
{
private:
    MyDList list_;//包装,会直接调用MyDList的创建和析构,不用再写一遍

public:
    std::size_t size() const { return list_.size(); }
    bool empty() const { return list_.empty(); }

    void push(int value) { list_.push_back(value); }    // 队尾入
    void pop() { list_.pop_front(); }                   // 队首出
    int &front() { return list_.front(); }
    const int &front() const { return list_.front(); }
};