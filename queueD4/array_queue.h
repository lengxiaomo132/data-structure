// array_queue.h
#pragma once
#include <cstddef>

class ArrayQueue
{
private:
    int *data_ = nullptr;
    std::size_t capacity_ = 0;
    std::size_t size_ = 0;
    std::size_t front_ = 0; // 队首下标
    std::size_t back_ = 0;  // "下一个"写入位置

    bool full() const { return size_ == capacity_; }
    void grow()
    {
        std::size_t new_cap = (capacity_ == 0) ? 1 : capacity_ * 2;
        int *new_data = new int[new_cap];

        for (std::size_t i = 0; i < size_; ++i)
        {
            std::size_t idx = (front_ + i) % capacity_; // 从队首开始绕圈
            new_data[i] = data_[idx];
        }

        delete[] data_;
        data_ = new_data;
        capacity_ = new_cap;
        front_ = 0;              // 新数组从 0 开始连续存放
        back_ = size_; // back是下一个写入位置所以要等于size_,因为刚刚扩容不用取模来限制back范围
    }

public:
    ArrayQueue() = default;
    ~ArrayQueue() { delete[] data_; }
    std::size_t size() const { return size_; }
    bool empty() const { return size_ == 0; }

    void push(int value) // 队尾进列
    {
        if (full())
            grow();

        data_[back_] = value;
        back_ = (back_ + 1) % capacity_; // 绕圈
        ++size_;
    }
    void pop() // 队首出列
    {
        if (size_ == 0)
            return;

        front_ = (front_ + 1) % capacity_; // 队首后移，绕圈
        --size_;
    }
    int &front() { return data_[front_]; }             // 取队首值
    const int &front() const { return data_[front_]; } // 取队首值(const)
};
