/*
 * @Brief        : 
 * @Author       : dmjcb
 * @Date         : 2024-08-27 00:16:31
 * @LastEditors  : dmjcb@outlook.com
 * @LastEditTime : 2024-09-26 12:17:17
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
    std::string mStartNode = "";
    std::string mEndNode = "";
    double      mWeight;
    bool        mIsSelect;

    Line(std::string startNode, std::string endNode, double weight) {
        this->mStartNode = mStartNode;
        this->mEndNode = mEndNode;
        this->mWeight = weight;
        this->mIsSelect = false;
    }
} Line;


/**
 * @brief: defintion of Graph
 * @return {*}
 */
class Graph {
public:

    Graph(std::vector<Line> lines) {
        mLines = std::move(lines);

        // count the number of nodes
        std::set<std::string> nodes;
        for (auto line : mLines) {
            nodes.insert(line.mStartNode);
            nodes.insert(line.mEndNode);
        }

        // parent of each node is itself at initialization time
        for (auto node : nodes) {
            mParent[node] = node;
        }
    };

    /**
     * @brief 
     * @param {string} node
     * @return {*}
     */        
    std::string Find(std::string node) {
        if (mParent[node] == node) {
            return node;
        }

        std::string root = node;
        while (mParent[root] != root) {
            root = mParent[root];
        }

        std::string fatherNode = node;
        while (root != node) {
            fatherNode = mParent[node];
            mParent[node] = root;
            node = fatherNode;
        }

        return root;
    }

    void Merge(std::string node1, std::string node2) {
        mParent[Find(node1)] = Find(node2);
    }

    const double GetKruskal() {
        std::sort(mLines.begin(), mLines.end(), [=](const Line &e1, const Line &e2) { return e1.mWeight < e2.mWeight; });

        double sum = 0;
        for (auto &line : mLines) {
            if (Find(line.mStartNode) != Find(line.mEndNode)) {
                sum += line.mWeight;
                line.mIsSelect = true;

                Merge(line.mStartNode, line.mEndNode);
            }
        }
        return sum;
    }

    void PrintResult() const {
        for (auto line : mLines) {
            if (line.mIsSelect) {
                std::cout << "select Line: " << line.mStartNode << "-" << line.mEndNode << std::endl;
            }
        }
    }

private:
    std::map<std::string, std::string> mParent;
    std::vector<Line>                  mLines;
};

int main(void) {
    std::vector<Line> lines = {
        Line("A", "B", 1), Line("A", "C", 9), Line("A", "D", 7), Line("B", "D", 5), Line("B", "E", 2), Line("E", "D", 4),
        Line("E", "F", 7), Line("F", "D", 1), Line("F", "G", 3), Line("G", "D", 6), Line("G", "C", 2), Line("C", "D", 4),
    };

    Graph graph(lines);

    std::cout << "The minimum spanning tree mWeight = " << graph.GetKruskal() << std::endl;
    graph.PrintResult();

    return 0;
}