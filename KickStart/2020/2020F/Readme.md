# 2020 Round F

-   Score : -
-   Rank : -
-   早上八点，这谁起得来，打扰了hhh

---

## A

- 所有人按轮数为第一关键字，初始顺序为第二关键字排序

## B

- 贪心放机器人，算一算个数就行了

## C

- 其实想到了做法，但并没有估计好理论复杂度和实际运行的Gap
- 状态压缩去做博弈即可，核心在于理论复杂度是$O(2^{S^2})$，但实际上远远跑不满
- 代码很简单，就不写了

## D

- 不得不承认，DP的确是自己的弱项
- 这题精妙之处在于动态规划和概率的完美结合
- 这题基于一个显然的结论 : 50的划分数并不大，甚至划分数求和也不大
- 我们基于划分表示状态，并采用记忆化搜索来进行决策
- 核心的部分在于
    - 求出所有后继状态的步数期望以及由当前状态到达的概率
    - 如何求解最优后继状态的组合
- 细节参照题解的具体内容

​    
