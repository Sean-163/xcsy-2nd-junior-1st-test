# 新斐波那契

## 题目描述

现在有一种新的斐波那契数列，它的每个项不是一个数，而是$\large{m}$个数。而其满足的递归关系也不是简单的$\large{F_{n} = F_{n - 1} + F_{n - 2}}$，而是$\large{F_{n} = \sum_{i = 1}^{\frac{n}{k}} M \times F_i }$
其中$\large{k \in \N+}$ 且 $\large{k \neq 1 }$，$\large{F_i}$以列向量形式表示，$\large{M}$为一$\large{m}$阶矩阵，$\large{\frac{n}{k}}$的运算结果向下取整。

现在给定$\large{m}$，$\large{n}$，$\large{t}$，$\large{k}$，$\large{M}$以及第一项$F_1$，你的任务是求出$\large{F_n}$的值。

## 输入说明

第一行是$\large{m}$，$\large{n}$，$\large{t}$，$\large{k}$，三者间由空格分隔
第二行至第$\large{m + 1}$行是一个$\large{m \times m}$的矩阵$\large M$，每项之间以空格分隔
接下来一行是$\large{m}$个数，以空格分隔，代表$\large{F_1}$
