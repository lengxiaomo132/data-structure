// my_list.h
#pragma once

#include <cstddef>
#include <iostream>

class MyList
{
private:
    struct Node // 定义Node节点,放在class里
    {
        int value;
        Node *next;
    };

    Node *head_ = nullptr; // 头指针
    Node *tail_ = nullptr;
    std::size_t size_ = 0; // 元素个数

public:
    // 创建/析构
    MyList() = default;
    ~MyList()
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
    MyList(const MyList &) = delete; // 它让这个函数[存在但不可用]
    MyList &operator=(const MyList &) = delete;

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
        Node *new_node = new Node{value, nullptr}; // 给新节点分配内存，并初始化成员
        if (head_ == nullptr)                      // 如果是空链表就把头接上新节点
        {
            head_ = tail_ = new_node; // 有tail_那尾也接上
        }
        else
        {
            // 无tail_版
            // Node *cur = head_;
            // while (cur->next != nullptr) // 不是空链表就找到链表结尾
            // cur = cur->next;
            // cur->next = new_node; // 使尾巴上空指针接上新节点，此时新节点的next还是空指针

            // tail_版
            tail_->next = new_node;
            tail_ = new_node;
        }
        ++size_; // 链表容量+1
    }
    void push_front(int value) // 头部添加节点
    {
        Node *new_node = new Node{value, head_}; // 新节点指向老的头所指的堆上内存地址
        head_ = new_node;                        // 头重新指向新节点的堆上内存地址
        if (tail_ == nullptr)                    // ← 新增：如果是空链表来的
            tail_ = new_node;                    // 尾巴也要指向它
        ++size_;
    }
    void pop_front() // 头部删除节点
    {
        if (head_ == nullptr) // 空链表什么都不做
            return;

        Node *old = head_;   // 记住要删的头节点内存地址
        head_ = head_->next; // 头指针向后移一个，指向后一个内存
        delete old;          // 把旧头节点堆上内存删掉，这个放最后，不然head_找不到下一个节点地址
        --size_;

        if (head_ == nullptr) // ← 新增：删完变空
            tail_ = nullptr;  // 尾巴也要清空
    }
    void pop_back()// 尾部删除节点
    {
        if (head_ == nullptr) return;
        if (head_ == tail_)
        {
            delete head_;
            head_ = tail_ = nullptr;
            --size_;
            return;
        }
        Node *cur = head_;
        while(cur->next != tail_)
           cur = cur->next;
        delete tail_;
        tail_ = cur;
        tail_->next = nullptr;
        --size_;
    }
    void print() const // 打印链表
    {
        Node *cur = head_;
        while (cur != nullptr)
        {
            std::cout << cur->value << " -> ";
            cur = cur->next;
        }
        std::cout << "null\n";
    }

    void remove(int value) // 移除特定数值的节点
    {
        // 先测试头要不要删除，用pop_front逻辑
        while (head_ != nullptr && head_->value == value)
        {
            Node *old = head_;
            head_ = head_->next;
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
                delete old;
                --size_;
            }
            else
            {
                cur = cur->next;
            }
        }
        // ← 新增：链表可能被删空
        if (head_ == nullptr)
            tail_ = nullptr;
        else
        {
            // 重新找尾巴（因为可能删掉的是原来的尾巴）
            Node *p = head_;
            while (p->next != nullptr)
                p = p->next;
            tail_ = p;
        }
    }
    void dummy_remove(int value) // 移除的虚拟头写法
    {
        Node dummy{0, head_};        // 变成 [0]->[头]->[next1]...新加了一个虚拟头[0]
        Node *cur = &dummy;          // cur指向虚拟头
        while (cur->next != nullptr) // 从[头]开始遍历,和上面一样,在1看2接3
        {
            if (cur->next->value == value)
            {
                Node *old = cur->next;
                cur->next = old->next;
                delete old;
                --size_;
            }
            else
            {
                cur = cur->next;
            }
        }
        head_ = dummy.next; // 最后把头指针重新指向remove后的头,虚拟头在栈上,生命周期结束后自动析构.
    }
};

inline void test_tail()
{
    std::cout << "\n=== tail_ 正确性测试 ===\n";

    // 1. 空链表 push_back
    MyList a;
    a.push_back(1);
    a.print(); // 1 -> null

    // 2. 连续 push_back
    a.push_back(2);
    a.push_back(3);
    a.print(); // 1 -> 2 -> 3 -> null

    // 3. 空链表 push_front（考验 tail_）
    MyList b;
    b.push_front(10);
    b.print();       // 10 -> null
    b.push_back(20); // 这里会用到 tail_
    b.print();       // 10 -> 20 -> null

    // 4. pop 到空（考验 tail_ 清空）
    MyList c;
    c.push_back(1);
    c.pop_front();
    c.push_back(2); // 如果 tail_ 没清空，这里会崩
    c.print();      // 2 -> null

    // 5. remove 删掉尾巴
    MyList d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.remove(3);    // 删尾巴
    d.push_back(4); // 如果 tail_ 没更新，这里会崩
    d.print();      // 1 -> 2 -> 4 -> null

    // 6. remove 删空
    MyList e;
    e.push_back(5);
    e.push_back(5);
    e.remove(5);
    e.push_back(6); // 空之后能正常 push
    e.print();      // 6 -> null
}
