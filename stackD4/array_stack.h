// array_stack.h
#pragma once
#include <cstddef>

class ArrayStack
{
private:
    int *data_ = nullptr;
    std::size_t size_ = 0;
    std::size_t capacity_ = 0;

public:
    ArrayStack() = default;
    ~ArrayStack() { delete[] data_; }

    ArrayStack(const ArrayStack &) = delete;
    ArrayStack &operator=(const ArrayStack &) = delete;

    std::size_t size() const { return size_; }
    bool empty() const { return size_ == 0; }

    void push(int value)//压入栈
    {
        if(size_ == capacity_)
        grow();
        data_[size_] = value;
        ++size_;
    }
    void pop()//弹出栈
    {
        if(size_ > 0)
        --size_;
    }
    int &top()//返回栈顶元素
    {
        return data_[size_-1];
    }
    const int &top() const//返回栈顶元素(const)
    {
        return data_[size_-1];
    }

private:
    void grow()
    {
        std::size_t new_cap = (capacity_ == 0) ? 1 : capacity_ * 2; // 条件成立取 值1，否则取 值2
        int *new_data = new int[new_cap];
        // 复制旧数据
        for (std::size_t i = 0; i < size_; ++i){
            new_data[i] = data_[i];
        }
        // 释放旧的、更新成员
        delete[] data_;
        data_ = new_data; // new_data 是局部指针，函数结束只消失变量本身，不释放堆内存。
        capacity_ = new_cap;
    }
};
