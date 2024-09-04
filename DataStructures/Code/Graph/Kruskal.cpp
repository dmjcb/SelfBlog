/*
 * @Author       : dmjcb@outlook.com
 * @Date         : 2024-08-27 00:16:31
 * @LastEditors  : dmjcb@outlook.com
 * @LastEditTime : 2024-09-05 00:34:57
 */


#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>


/**
 * @brief: defintion of Line
 * @return {*}
 */
typedef struct Line
{
    std::string startNode = "";
    std::string endNode = "";
    double weight;

    bool isSelect;

    Line(std::string startNode, std::string endNode, double weight)
    {
        this->startNode = startNode;
        this->endNode = endNode;
        this->weight = weight;
        this->isSelect = false;
    }
} Line;


/**
 * @brief: defintion of Graph
 * @return {*}
 */
class Graph
{
public:

    Graph(std::vector<Line> lines)
    {
        mLines = std::move(lines);

        // count the number of nodes
        std::set<std::string> nodes;
        for (auto line : mLines)
        {
            nodes.insert(line.startNode);
            nodes.insert(line.endNode);
        }

        // parent of each node is itself at initialization time
        for (std::string node : nodes)
        {
            mParent[node] = node;
        }
    };

    /**
     * @brief 
     * @param {string} node
     * @return {*}
     */        
    std::string Find(std::string node)
    {
        if (mParent[node] == node)
        {
            return node;
        }

        std::string root = node;
        while (mParent[root] != root)
        {
            root = mParent[root];
        }

        std::string fatherNode = node;
        while (root != node)
        {
            fatherNode = mParent[node];
            mParent[node] = root;
            node = fatherNode;
        }

        return root;
    }

    void Merge(std::string node1, std::string node2)
    {
        mParent[Find(node1)] = Find(node2);
    }

    void PrintResult()
    {
        for (auto line : mLines)
        {
            if (line.isSelect)
            {
                std::cout << "select Line: " << line.startNode << "-" << line.endNode << std::endl;
            }
        }
    }

    double RunKruskal()
    {
        std::sort(mLines.begin(), mLines.end(), [=](const Line &e1, const Line &e2) { return e1.weight < e2.weight; });

        double sum = 0;
        for (auto &line : mLines)
        {
            if (Find(line.startNode) != Find(line.endNode))
            {
                sum += line.weight;
                line.isSelect = true;

                Merge(line.startNode, line.endNode);
            }
        }
        return sum;
    }

private:
    std::map<std::string, std::string> mParent;
    std::vector<Line> mLines;
};

int main(void)
{
    std::vector<Line> lines = {
        Line("A", "B", 1),
        Line("A", "C", 9),
        Line("A", "D", 7),
        Line("B", "D", 5),
        Line("B", "E", 2),
        Line("E", "D", 4),
        Line("E", "F", 7),
        Line("F", "D", 1),
        Line("F", "G", 3),
        Line("G", "D", 6),
        Line("G", "C", 2),
        Line("C", "D", 4),
    };

    Graph graph(lines);

    std::cout << "The minimum spanning tree weight = " << graph.RunKruskal() << std::endl;
    graph.PrintResult();

    return 0;
}