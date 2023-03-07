# 新斐波那契（`newfib.cpp`）

## 题目描述

现在有一种新的斐波那契数列，其满足的递归关系不是简单的$\large{F_{n} = F_{n - 1} + F_{n - 2}}$，而是$\large{F_n = 所有F_i的和}$，其中$\large{i}$为由$\large{1}$至$\large{\frac{n}{k}}$的正整数，$\large{k}$为正整数且 $\large{k \neq 1 }$，$\large{\frac{n}{k}}$的运算结果向下取整。

现在给定$\large{n}$，$\large{k}$，以及第一项$F_1$，你的任务是求出$\large{F_n}$的值。

## 输入说明

仅一行，分别为正整数$\large{n}$，$\large{k}$与$\large{F_1}$，三者间由空格分隔

## 输出说明

仅一行一个数，为$\large{F_n}$的值

## 输入样例

## 样例解释

## 数据规模
对于$\large{\%50}$的数据，$\large{n \leqslant 500}$
对于$\large{\%100}$的数据，$\large{n \leqslant 2e4}$
输入数据保证$\large{F_i}$在长整型范围内