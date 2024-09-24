<!--
 * @Description: 
 * @Version: 1.0
 * @Author: dmjcb
 * @Email:  
 * @Date: 2022-02-13 19:00:24
 * @LastEditors: dmjcb
 * @LastEditTime: 2024-07-06 23:28:05
-->

# SPFA

![](https://raw.githubusercontent.com/dmjcb/SelfImgur/main/2022-4-4-0152.svg)

求$A$到其他点的最短路

## 理论

建立一个队列, 存入开始节点, 队列不为空时:

$1)$ 取出队头节点 $X$, 出队

$2)$ 遍历与 $X$ 相通的节点 $Y$, 若 $X$ 到 $Y$ 的距离可缩小(松弛), 且 $Y$ 不在队列中, 将 $Y$ 入队, 继续 $1)$

$3)$ 若队列为空则结束

## 过程

$1)$ 求 $A$ 节点到其余节点的最短路, 设定 $p[i]$为 $A$ 到 $i$ 节点的路径

初始状态, 建立点 $A$ 到其余各点的最短路径设为$∞$

|        | A   | B   | C   | D   | E   |
| ------ | --- | --- | --- | --- | --- |
| $p[i]$ | $0$ | $∞$ | $∞$ | $∞$ | $∞$ |

$2)$ 点 $A$ 进入队列, 队列为$[A]$, 队列非空时, 

队头$A$ 出队, 对以 $A$ 为起点的所有边松弛, 涉及点 $B, E$

|        | A   | B    | C   | D   | E    |
| ------ | --- | ---- | --- | --- | ---- |
| $p[i]$ | $0$ | `13` | $∞$ | $∞$ | `70` |

![](https://raw.githubusercontent.com/dmjcb/SelfImgur/main/2022-4-4-0156.svg)

点 $B, E$ 的最短路径变小, 且其未在队列中, 故点 $B, E$ 入队

队列为 $[B, E]$

$3)$ 队头 $B$ 出队, 对以 $B$ 为起点的所有边进行松弛, 涉及点 $C, D$

|        | A   | B    | C    | D    | E    |
| ------ | --- | ---- | ---- | ---- | ---- |
| $p[i]$ | $0$ | $13$ | `41` | `17` | $70$ |

![](https://raw.githubusercontent.com/dmjcb/SelfImgur/main/2022-4-4-0158.svg)

到点 $C, D$ 的路径变小, 且点其未在队列中, 故点 $C, D$ 入队

队列为 $[E, C, D]$

$4)$ 队头 $E$ 出队, 对以 $E$ 为起点的所有边的终点进行松弛操作

$5)$ 队头 $C$ 出队, 对以 $C$ 为起点的所有边的终点进行松弛操作, 涉及点$D, E$

|        | A   | B    | C    | D    | E    |
| ------ | --- | ---- | ---- | ---- | ---- |
| $p[i]$ | $0$ | $13$ | $41$ | $17$ | `56` |

![](https://raw.githubusercontent.com/dmjcb/SelfImgur/main/2022-4-4-0159.svg)

到点 $E$ 的最短路径改变, 且其未在队列中, 点 $E$ 入队

队列中结点为 $[D, E]$

$6)$ 队头 $D$ 出队, 对以 $D$ 为起点的边进行松弛

队列为$[E]$

$7)$ 队头 $E$ 出队, 对以 $E$ 为起点的边进行松弛

队列为空, 结束

点 $A$ 到其他点的最短路径为

|        | A   | B    | C    | D    | E    |
| ------ | --- | ---- | ---- | ---- | ---- |
| $p[i]$ | `0` | `13` | `41` | `17` | `56` |


## 代码

```c++
/*
 * @Description:
 * @Version: 1.0
 * @Author: dmjcb
 * @Email:
 * @Date: 2022-04-13 22:33:00
 * @LastEditors: dmjcb
 * @LastEditTime: 2022-07-19 21:59:52
 */

#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <vector>

const int SIZE = 5;
const int MAXV = 10000;

typedef struct Line
{
    std::string startNode;
    std::string endNode;
    int weight;

    Line(std::string s, std::string e, int w) : startNode(s), endNode(e), weight(w) {}
} Line;


class SPFAAlgorithm
{
public:
    SPFAAlgorithm(std::vector<Line> lines) {
        std::set<std::string> _node;
        for (auto line : lines) {
            _node.insert(line.startNode);
            _node.insert(line.endNode);
        }
        mNode.assign(_node.begin(), _node.end());

        mLines = std::move(lines);

        for (auto node : mNode) {
            mShortestPath[node] = 0x7FFFFFFF;
            mIsInQueue[node] = false;
        }
    }

    void RunSPFA(std::string node) {
        std::queue<std::string> queue;

        queue.push(node);
        mShortestPath[node] = 0;
        mIsInQueue[node] = true;

        std::string startNode;
        std::string endNode;
        while (!queue.empty())
        {
            startNode = queue.front();
            queue.pop();
            mIsInQueue[startNode] = false;
            // 遍历所有与a所连通的节点, 进行松弛操作
            for (int i = 0; i < mLines.size(); i++)
            {
                if (startNode != mLines[i].startNode)
                {
                    continue;
                }
                // 某个边的起点是a,获取该边的终点e
                endNode = mLines[i].endNode;
                // 若从点node经过点x到点end的距离比S直接到end的距离短, 则可松弛
                if (mShortestPath[startNode] + mLines[i].weight < mShortestPath[endNode])
                {
                    // 从点S到点end的距离更新为点S到X的距离与X到end的距离之和
                    mShortestPath[endNode] = mShortestPath[startNode] + mLines[i].weight;
                    if (!mIsInQueue[endNode])
                    {
                        queue.push(endNode);
                        mIsInQueue[endNode] = 1;
                    }
                }
            }
        }
    }

    void PrintShortestPath() {
        for (auto k : mShortestPath) {
            std::cout << k.first << k.second << std::endl;
        }
    }


private:
    std::vector<Line> mLines;
    std::vector<std::string> mNode;
    std::map<std::string, double> mShortestPath;
    std::map<std::string, bool> mIsInQueue;
};


int main()
{
    std::vector<Line> lines = { Line("A", "B", 13), Line("A", "E", 70), Line("B", "D", 4), Line("B", "C", 28), Line("C", "D", 23), Line("C", "E", 15) };
    
    std::string node = "A";
    
    SPFAAlgorithm spfa = SPFAAlgorithm(lines);

    spfa.RunSPFA(node);
    spfa.PrintShortestPath();

    return 0;
}
```
