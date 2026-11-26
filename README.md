# 数据结构与 Gameplay 学习（C++）

用 C++17 系统学习数据结构与算法，并为 Gameplay 客户端面试做准备。

**状态**：🟢 进行中（D1–D3 已完成）

## 前置

已完成 [`cpp-learning`](../cpp-learning) 的全部 19 课 + 19.5 专题：

- C++ 语法完整（变量、分支、循环、函数、类、继承、模板）
- 内存模型（栈/堆、`unique_ptr`、移动语义）
- 工程能力（多文件、`#pragma once`、`static`）
- 安全意识（未定义行为、边界检查）

**尚未系统学过**：O 复杂度、手写数据结构、算法专题。

## 目录

| 文件 / 目录 | 内容 |
|---|---|
| `arrayD2/` | D2 动态数组：`my_vector.h` + `my_vector.cpp` |
| `listD3/` | D3 单链表：`my_list.h` + `my_list.cpp` |
| `dlistD3/` | D3 双链表：`my_dlist.h` + `my_dlist.cpp` |
| `stackD4/` | D4 栈：`array_stack.h` + `list_stack.h` |
| `queueD4/` | D4 队列：`array_queue.h`（循环数组）+ `list_queue.h` |
| `practiceD1.md` | D1 练习（复杂度题） |
| `docs/` | 课表、进度、教学规则、作业单 |

> 后续每课一个大写字母 + 课号的目录（如 `hashD5/`、`treeD6/`）。

## 课程进度

### 第一阶段：数据结构（D1–D12）

| 课次 | 主题 | 状态 |
|---|---|---|
| D1 | 复杂度、内存布局、缓存局部性 | ✅ 完成（20/20） |
| D2 | 数组与动态数组 | ✅ 完成（13 函数全通） |
| D3 | 链表 | ✅ 完成（单链表 + 双链表） |
| D4 | 栈、队列、双端队列 | ✅ 完成（数组 + 链表各一版） |
| D5 | 哈希表 | ⬜ **下一步** |
| D6 | 递归、二叉树与遍历 | ⬜ |
| D7 | 二叉搜索树（BST） | ⬜ |
| D8 | 堆与优先队列 | ⬜ |
| D9 | 图与 BFS / DFS | ⬜ |
| D10 | 并查集 | ⬜ |
| D11 | 空间划分：Grid | ⬜ |
| D12 | 项目：Enemy Manager | ⬜ |

### 第二阶段：基础算法（A1–A7，与 D 并行）

| 课次 | 主题 | 状态 |
|---|---|---|
| A1 | 二分查找 | ⬜ |
| A2 | 双指针 | ⬜ |
| A3 | 滑动窗口 | ⬜ |
| A4 | 排序 | ⬜ |
| A5 | 递归与回溯 | ⬜ |
| A6 | 基础动态规划 | ⬜ |
| A7 | 位运算与字符串基础 | ⬜ |

## 已完成的结构

| 课次 | 文件 | 关键点 |
|---|---|---|
| D2 | `arrayD2/my_vector.h` | 三要素（指针/size/capacity）、2 倍扩容、深拷贝、`reserve` |
| D3 | `listD3/my_list.h` | 节点串接、`tail_` 优化、两种 `remove`（普通 / 虚拟头） |
| D3+ | `dlistD3/my_dlist.h` | `prev` 指针、端部全 O(1)、`pop_back` 不需遍历 |
| D4 | `stackD4/` + `queueD4/` | 栈 LIFO、队列 FIFO、循环数组绕圈、组合包装 |

## 分层要求

| 层 | 内容 | 要求 |
|---|---|---|
| 🟢 **必须手写完整实现** | 动态数组、链表、栈、队列、哈希表、BST、堆、图、并查集 | 完整实现 + 测试 + 复杂度分析 |
| 🟢 **必须能手写** | 二分、双指针、基础排序、简单回溯/DP | 能独立写出核心代码 |
| 🟡 **必须会用** | `vector`、`string`、`unordered_map`、`map`、`stack`、`queue`、`deque`、`priority_queue`、`sort` | 工作代码优先用 STL |
| ⚪ **会读会用** | 红黑树、AVL、四叉树、BVH/KD-tree、KMP、线段树 | 知道用途和复杂度，不手写 |

## 如何编译

```bash
cd arrayD2   # 或 listD3 等
g++ -std=c++17 -Wall -Wextra -o test.exe 源文件.cpp
./test.exe
```

**性能测试加 `-O2`：**

```bash
g++ -std=c++17 -O2 -Wall -Wextra -o bench.exe bench.cpp
```

## 文档索引

| 文件 | 内容 |
|---|---|
| [`docs/START-HERE.md`](docs/START-HERE.md) | 新对话启动指令 |
| [`docs/data-structure-schedule.md`](docs/data-structure-schedule.md) | **完整课表**（D1–D12 / A1–A7）与验收标准 |
| [`docs/progress.md`](docs/progress.md) | 学习进度、已掌握、易错点、遗留问题 |
| [`docs/teaching-notes.md`](docs/teaching-notes.md) | 教学规则（9 条主规则 + D1–D10）与环境 |
| [`docs/assignments.md`](docs/assignments.md) | 作业单 |

## 教学方式（与 C++ 基础课不同）

**数据结构课采用「分步骤实现」：**

| 步骤 | 内容 |
|---|---|
| 1 | 讲原理 + 给核心算法的骨架 |
| 2–4 | 每步加 2–5 个函数，每步都能编译运行 |
| 进阶 | 有额外优化（如 `tail_`）时可选做 |

**不一次给完整实现**——给答案等于剥夺练习。详见 [`docs/teaching-notes.md`](docs/teaching-notes.md) 的「一之二」节。

## 与刷题的关系

**刷题并行**，不等学完再刷。每学完一个结构，至少做 3 道对应 LeetCode 题。

题单见 [`docs/data-structure-schedule.md`](docs/data-structure-schedule.md) 的「与刷题的配合」一节。

## 后续路线

本仓库覆盖的是 [roadmap-after-cpp.md](../roadmap-after-cpp.md) 的 **S1（数据结构与算法）+ S2（刷题）**。

地图上其他 **P0** 领域在后续阶段：

| 阶段 | 主题 |
|---|---|
| S3 | 内存与并发 |
| S4 | C++ 深度 |
| S5 | 游戏数学 |
| S6 | 引擎与 Gameplay（UE 项目） |
| S7 | 网络与同步 |
