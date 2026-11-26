// list_stack.h
#pragma once
#include "../dlistD3/my_dlist.h"

class ListStack
{
private:
    MyDList list_;//组合双链表,不暴露双链表里面用不上的接口(功能函数)

public:
    std::size_t size() const { return list_.size(); }//取size_
    bool empty() const { return list_.empty(); }//判空

    void push(int value) { list_.push_front(value); }//压入栈(前面进)
    void pop() { list_.pop_front(); }//弹出栈(前面出)
    int &top() { return list_.front(); }//返回顶上的值
    const int &top() const { return list_.front(); }//返回顶上的值(const)
};