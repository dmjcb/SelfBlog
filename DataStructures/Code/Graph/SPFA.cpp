/*
 * @Description: SPFA求最短路径
 * @Version: 1.0
 * @Author: dmjcb
 * @Email:
 * @Date: 2022-04-13 22:33:00
 * @LastEditors: dmjcb
 * @LastEditTime: 2024-07-30 13:22:33
 */

#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <vector>

// defintion of line
typedef struct Line
{
    std::string startNode;
    std::string endNode;
    double weight;

    Line(std::string s, std::string e, int w) : startNode(s), endNode(e), weight(w) {}
} Line;


class SPFAAlgorithm
{
public:
    SPFAAlgorithm(std::vector<Line> lines)
    {
        std::set<std::string> _node;
        for (const auto line : lines)
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
            for (const auto line : mLines) {
                if (startNode == line.startNode) {
                    endNode = line.endNode;
                    // 若从点node经过点x到点end的距离比node直接到end的距离短
                    if (mShortestPath[startNode] + line.weight < mShortestPath[endNode]) {
                        // 距离更新为点node到x的距离与x到end的距离之和
                        mShortestPath[endNode] = mShortestPath[startNode] + line.weight;
                        if (!mIsInQueue[endNode])
                        {
                            queue.push(endNode);
                            mIsInQueue[endNode] = true;
                        }
                    }
                }
            }
        }
    }

    void PrintShortestPath()
    {
        for (auto k : mShortestPath)
        {
            std::cout << k.first << "---" << k.second << std::endl;
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
    std::vector<Line> lines = {
        Line("A", "B", 13),
        Line("A", "E", 70),
        Line("B", "D", 4),
        Line("B", "C", 28),
        Line("C", "D", 23),
        Line("C", "E", 15)
    };

    std::string node = "A";

    SPFAAlgorithm spfa = SPFAAlgorithm(lines);
    spfa.SPFA(node);
    spfa.PrintShortestPath();

    return 0;
}