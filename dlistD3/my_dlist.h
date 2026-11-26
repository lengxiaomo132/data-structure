// my_dlist.h
#pragma once

#include <cstddef>
#include <iostream>

class MyDList
{
private:
    struct Node // 定义Node节点,放在class里
    {
        int value;
        Node *next;
        Node *prev;
    };

    Node *head_ = nullptr; // 头指针
    Node *tail_ = nullptr;
    std::size_t size_ = 0; // 元素个数

public:
    // 创建/析构
    MyDList() = default;
    ~MyDList()
    {
        Node *cur = head_;
        while (cur != nullptr)
        {
            Node *next = cur->next; // 先记住下一个
            delete cur;             // 再删当前
            cur = next;             // 走到下一个
        }
    }

    // 禁用拷贝
    MyDList(const MyDList &) = delete; // 它让这个函数[存在但不可用]
    MyDList &operator=(const MyDList &) = delete;

    // getter
    std::size_t size() const { return size_; }
    bool empty() const { return size_ == 0; }

    int *find(int value) // 返回找到相同数值在堆上面的地址
    {
        Node *cur = head_;
        while (cur != nullptr)
        {
            if (cur->value == value)
                return &cur->value; // 返回值的地址
            cur = cur->next;
        }
        return nullptr;
    }
    const int *find(int value) const // const版本
    {
        Node *cur = head_;
        while (cur != nullptr)
        {
            if (cur->value == value)
                return &cur->value; // 返回值的地址
            cur = cur->next;
        }
        return nullptr;
    }

    int &front() { return head_->value; }             // 取第一个数，可读，返回引用可改，空链表不可调用
    const int &front() const { return head_->value; } // 同上，只读类型

    // 功能函数
    void push_back(int value) // 尾部加节点
    {
        Node *new_node = new Node{value, nullptr, tail_}; // 新节点prev指向老尾部
        if (head_ == nullptr)
            head_ = tail_ = new_node; // 空链表则头尾都指向新节点
        else
        {
            tail_->next = new_node; // 不空，则老尾部指向新节点
            tail_ = new_node;       // 新节点成为尾部
        }
        ++size_; // 链表容量+1
    }
    void push_front(int value) // 头部添加节点
    {
        Node *new_node = new Node{value, head_, nullptr}; // 新节点指向老头
        if (head_ == nullptr)
            head_ = tail_ = new_node;
        else
        {
            head_->prev = new_node; // 老头的prev指新节点
            head_ = new_node;       // 新节点成为头
        }
        ++size_;
    }
    void pop_front() // 头部删除节点
    {
        if (head_ == nullptr) // 空链表什么都不做
            return;

        Node *old = head_;   // 记住要删的头节点内存地址
        head_ = head_->next; // 头指针向后移一个，指向后一个内存
        if (head_ != nullptr)
            head_->prev = nullptr;
        delete old; // 把旧头节点堆上内存删掉，这个放最后，不然head_找不到下一个节点地址
        --size_;

        if (head_ == nullptr) // ← 新增：删完变空
            tail_ = nullptr;  // 尾巴也要清空
    }
    void pop_back() // 尾部删除节点
    {
        if (head_ == nullptr)
            return;
        Node *old = tail_;   // 指向尾部
        tail_ = tail_->prev; // 尾部向前挪一格
        if (tail_ != nullptr)
            tail_->next = nullptr; // 把新尾部指向空
        else
            head_ = nullptr; // 如果删完没有了，那头也需要指向空
        delete old;
        --size_;
    }
    void print() const // 打印链表
    {
        const Node *cur = head_;
        while (cur != nullptr)
        {
            std::cout << cur->value << " -> ";
            cur = cur->next;
        }
        std::cout << "null\n";
    }
    void print_reverse() const
    {
        std::cout << "null";
        const Node *cur = tail_;
        while (cur != nullptr)
        {
            std::cout << " <- " << cur->value;
            cur = cur->prev;
        }
        std::cout << '\n';
    }

    void remove(int value) // 移除特定数值的节点
    {
        // 先测试头要不要删除，用pop_front逻辑
        while (head_ != nullptr && head_->value == value)
        {
            Node *old = head_;
            head_ = head_->next;
            if (head_ != nullptr)
                head_->prev = nullptr;
            else
                tail_ = nullptr;
            delete old;
            --size_;
        }

        // 再看中间和尾部，cur->next1->next2,cur等于头节点，看下一个节点next1要不要删除，删除就接后一个节点next2，重复，直到尾部
        Node *cur = head_;
        while (cur != nullptr && cur->next != nullptr)
        {
            if (cur->next->value == value)
            {
                Node *old = cur->next;
                cur->next = old->next;
                if (old->next != nullptr)
                    old->next->prev = cur; //[cur]->[old]->[?],old指向被删除项，如果old下一项?如果存在，那?的prve要指向cur
                else
                    tail_ = cur;

                delete old;
                --size_;
            }
            else
            {
                cur = cur->next;
            }
        }
    }
};