// my_vector.h
#pragma once
#include <cstddef> // std::size_t
#include <iostream>
template <typename T>
class MyVector
{
private:
    T *data_ = nullptr;        // 堆上的数组
    std::size_t size_ = 0;     // 当前元素个数
    std::size_t capacity_ = 0; // 当前容量

public:
    // 构造 / 析构
    MyVector() = default;
    ~MyVector() { delete[] data_; }

    // 拷贝 深拷贝创建/拷贝赋值
    MyVector(const MyVector &other)
        : data_(nullptr), size_(0), capacity_(0) // 先初始化成空
    {
        if (other.size_ > 0) // 对方有数据才分配
        {
            data_ = new T[other.capacity_]; // 分配同样大小的内存
            for (std::size_t i = 0; i < other.size_; ++i)
                data_[i] = other.data_[i]; // 逐个复制元素
            size_ = other.size_;
            capacity_ = other.capacity_;
        }
    }
    MyVector &operator=(const MyVector &other) // other引用是别名，不存在一个单独变量，&other就是地址
    {
        if (this == &other) // 自赋值检查（this是指针，this是地址，*this是它指向的变量）
        {
            return *this;
        }
        T *new_data = nullptr;
        if (other.size_ > 0)
        {
            new_data = new T[other.capacity_]; // 先分配新内存，把数据复制过去
            for (std::size_t i = 0; i < other.size_; ++i)
                new_data[i] = other.data_[i];
        }
        delete[] data_;   // 复制成功后才释放旧的
        data_ = new_data; // 更新成员
        size_ = other.size_;
        capacity_ = other.capacity_;

        return *this;
    }

    // 元素访问，用[]，读改/只读
    T &operator[](std::size_t i)
    {
        return data_[i];
    }
    const T &operator[](std::size_t i) const
    {
        return data_[i];
    }

    // 容量
    std::size_t size() const { return size_; }
    std::size_t capacity() const { return capacity_; }
    bool empty() const { return size_ == 0; }

    // 修改
    void push_back(const T &value)//加到尾部
    {
        if (size_ == capacity_)
            grow();
        data_[size_] = value;
        ++size_;
    }
    void pop_back()//删除尾部
    {
        if (size_ > 0)
            --size_;
    }
    void reserve(std::size_t new_cap)//赋一个容量
    {
        if (capacity_ >= new_cap) // 不比现在大，什么都不做
            return;

        T *new_data = new T[new_cap];
        for (std::size_t i = 0; i < size_; ++i)
            new_data[i] = data_[i];
        delete[] data_;
        data_ = new_data;
        capacity_ = new_cap;
    }
    void clear() { size_ = 0; } // 注意 clear() 不释放内存——容量不变，只是把 size 归零。

private:
    void grow() // 扩容
    {
        // 第一组：算新容量
        std::cout << "扩容";
        std::size_t new_cap = (capacity_ == 0) ? 1 : capacity_ * 2; // 条件成立取 值1，否则取 值2
        // 第二组：分配新内存
        T *new_data = new T[new_cap];
        // 第三组：复制旧数据
        for (std::size_t i = 0; i < size_; ++i){
            new_data[i] = data_[i];
            std::cout << "复制";
        }
        // 第四组：释放旧的、更新成员
        delete[] data_;
        data_ = new_data; // new_data 是局部指针，函数结束只消失变量本身，不释放堆内存。
        capacity_ = new_cap;
    }
};