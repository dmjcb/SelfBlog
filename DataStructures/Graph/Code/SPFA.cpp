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
    SPFAAlgorithm(std::vector<Line> lines)
    {
        std::set<std::string> _node;
        for (auto line : lines)
        {
            _node.insert(line.startNode);
            _node.insert(line.endNode);
        }
        mNode.assign(_node.begin(), _node.end());

        mLines = std::move(lines);

        for (auto node : mNode)
        {
            mShortestPath[node] = 0x7FFFFFFF;
            mIsInQueue[node] = false;
        }
    }

    void SPFA(std::string node)
    {
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

    void PrintShortestPath()
    {
        for (auto k : mShortestPath)
        {
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
    std::vector<Line> lines = {Line("A", "B", 13), Line("A", "E", 70), Line("B", "D", 4), Line("B", "C", 28), Line("C", "D", 23), Line("C", "E", 15)};
    std::string node = "A";

    SPFAAlgorithm spfa = SPFAAlgorithm(lines);
    spfa.SPFA(node);
    spfa.PrintShortestPath();

    return 0;
}