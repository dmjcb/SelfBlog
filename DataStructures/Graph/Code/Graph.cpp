#include <iostream>
#include <string>

#define MAX_NODE 20
#define MAX_WEIGHT 100

using namespace std;

typedef struct
{
    // 图中实际总顶点数
    int mNodeCount;
    // 图中实际总边数
    int mLineCount;
    // 顶点表
    char mNode[MAX_NODE];
    // 邻接矩阵
    int mNeigborMatrix[MAX_NODE][MAX_NODE];
    // 用来表示点某个点是否被选过
    bool mIsSelect[MAX_NODE];
} Graph;

// 查找某个在顶点表中的位置, 不存在则返回-1
int GetNodeIndex(Graph &graph, char mNode)
{
    for (int i = 0; i < graph.mNodeCount; i++)
    {
        if (graph.mNode[i] == mNode)
        {
            return i;
        }
    }
    return -1;
}

// 查找某个顶点的第一个邻接顶点, 参数为顶点在顶点表中的位置
int GetFirstNeighboringNode(Graph &graph, int pos)
{
    // 如果位置合法
    if (pos != -1)
    {
        // 遍历顶点表
        for (int j = 0; j < graph.mNodeCount; j++)
        {
            // 找到一个合法的邻接点
            if (graph.mNeigborMatrix[pos][j] > 0 && graph.mNeigborMatrix[pos][j] < MAX_WEIGHT)
            {
                // 返回该邻接点的位置
                return j;
            }
        }
    }
    return -1;
}

// 找出一个顶点除一个邻接顶点之外的另一个邻接顶点
int GetSecondNeighboringNode(Graph &graph, int pos1, int pos2)
{
    if (pos1 != -1 && pos2 != -1)
    {
        // 直接从 pos2 + 1判断, 因为vertexPosition2之前的点肯定不是其邻接点
        for (int j = pos2 + 1; j < graph.mNodeCount; j++)
        {
            if (graph.mNeigborMatrix[pos1][j] > 0 && graph.mNeigborMatrix[pos1][j] < MAX_WEIGHT)
            {
                return j;
            }
        }
    }
    return -1;
}

// 初始化图函数, n, e代表顶点数和边数
void InitGraph(Graph &graph, int nodeCount, int lineCount)
{
    graph.mNodeCount = nodeCount;
    graph.mLineCount = lineCount;
    for (int i = 0; i < graph.mNodeCount; i++)
    {
        // 标记该点为未选状态
        graph.mIsSelect[i] == false;
        char val;
        // 输入顶点值
        cin >> val;
        // 更新顶点表
        graph.mNode[i] = val;
        for (int j = 0; j < graph.mNodeCount; j++)
        {
            // 对角线值为0
            if (i == j)
            {
                graph.mNeigborMatrix[i][j] = 0;
            }
            else
            {
                graph.mNeigborMatrix[i][j] = MAX_WEIGHT;
            }
        }
    }
    // 初始化每一条边
    for (int i = 0; i < graph.mLineCount; i++)
    {
        char e1, e2;
        int weight;
        // 输入这个边的两个点和权值
        cout << "输入这个边的两个点和权值" << endl;
        cin >> e1 >> e2 >> weight;
        // 获取这两个点在顶点表中的坐标
        int pos1 = GetNodeIndex(graph, e1);
        int pos2 = GetNodeIndex(graph, e2);
        // 更新邻接矩阵
        graph.mNeigborMatrix[pos1][pos2] = weight;
        graph.mNeigborMatrix[pos2][pos1] = weight;
    }
}

// 查找节点
char GetNode(Graph &graph, int pos)
{
    if (pos != -1)
    {
        return graph.mNode[pos];
    }
}

// 遍历图, 形参为最开始遍历的节点位置
void DFS(Graph &graph, int pos)
{
    cout << "->" << GetNode(graph, pos);
    // 标记该位置为已选
    graph.mIsSelect[pos] = true;
    //  firstNeighborVertex表示vertexPosition的第一个邻接点
    int neighborPos = GetFirstNeighboringNode(graph, pos);
    // 当vertexPosition的邻接点存在时
    while (neighborPos != -1)
    {
        // 如果该点没有被选过
        if (graph.mIsSelect[neighborPos] == false)
        {
            // 递归访问 下一个邻接点
            DFS(graph, neighborPos);
        }
        // 否则取 pos 的另一个邻接点 neighborPos
        neighborPos = GetSecondNeighboringNode(graph, pos, neighborPos);
    }
}

// 求vertexPosition的最短路径
void GetShorestPath(Graph &graph, int pos, int dis[], int path[])
{
    // 最短路径顶点集合
    int path[MAX_NODE];
    for (int i = 0; i < graph.mNodeCount; i++)
    {
        // 路径长度数组初始化, 其值为vertexPosition到其他每个点的距离
        dis[i] = graph.mNeigborMatrix[pos][i];
        // 表示顶点i是否求得最短路径
        path[i] = 0;
        // 如果从vertexPosition到i有边, path[i]为该边始顶点号vertexPosition
        if (i != pos && dis[i] < MAX_WEIGHT)
        {
            path[i] = pos;
        }
        // 若没有边则path[i]为-1
        else
        {
            path[i] = -1;
        }
    }
    // 顶点vertexPosition加入集合isGetShortestPath
    path[pos] = 1;
    dis[pos] = 0;
    // 逐个求得isGetShortestPath到其他顶点的最短路径
    for (int i = 0; i < graph.mNodeCount - 1; i++)
    {
        int min = MAX_WEIGHT;
        // 选不在 isGetShortestPath中具有最短路径的顶点point
        int point = pos;
        for (int j = 0; j < graph.mNodeCount; j++)
        {
            // 如果该点j没有被选入且从vertexPosition到该点的距离小于min
            if (!path[j] && dis[j] < min)
            {
                // 更新位置
                point = j;
                // 更新最短路径
                min = dis[j];
            }
        }
        // 将顶点point加入isGetShortestPath集合
        path[point] = 1;
        // 修改经过point到其他顶点的路径长度
        for (int k = 0; k < graph.mNodeCount; k++)
        {
            // weight为点point到点k的距离
            int weight = graph.mNeigborMatrix[point][k];
            /* 如果点k未被选过
            且 点point到点k有边
            且 vertexPosition到点k的距离比vertexPosition经点point到点k的距离长*/
            if (!path[k] && weight < MAX_WEIGHT && dis[point] + weight < dis[k])
            {
                // vertexPosition到点k的距离路径可以缩短
                dis[k] = dis[point] + weight;
                //  vertexPosition到点k的前一个顶点为point
                path[k] = point;
            }
        }
    }
}

// 图的插入(插入一条边)
void InsertLine(Graph &graph, int node1, int node2, int weight)
{
    if (node1 != -1 && node2 != -1)
    {
        // 邻接矩阵中添加该边
        graph.mNeigborMatrix[node1][node2] = weight;
        graph.mNeigborMatrix[node2][node1] = weight;
    }
}

// 图的插入(插入一个顶点)
void InsertNode(Graph &graph, char value)
{
    if (graph.mNodeCount < MAX_NODE)
    {
        // 总节点数加1
        graph.mNodeCount++;
        // 更新节点
        graph.mNode[graph.mNodeCount] = value;
    }
}

// 删除一条边
void DelLine(Graph &graph, int node1, int node2)
{
    // 解除边的关系
    if (node1 != -1 && node2 != -1)
    {
        graph.mNeigborMatrix[node1][node2] = MAX_WEIGHT;
        graph.mNeigborMatrix[node1][node2] = MAX_WEIGHT;
    }
}

// 删除一个顶点和相应的边
void DelNodeAndLine(Graph &graph, char value)
{
    // 找到该点的位置
    int pos = GetNodeIndex(graph, value);
    // 将它换到顶点表的最后一位上去
    int temp = graph.mNode[graph.mNodeCount];
    graph.mNode[graph.mNodeCount] = graph.mNode[pos];
    graph.mNode[pos] = temp;
    // 转化边的关系
    for (int j = 0; j < graph.mNodeCount; j++)
    {
        graph.mNeigborMatrix[pos][j] = MAX_WEIGHT;
        graph.mNeigborMatrix[j][pos] = MAX_WEIGHT;
    }
    graph.mNeigborMatrix[pos][pos] = 0;
    // 总顶点数减1
    graph.mNodeCount--;
}

int main()
{
    Graph graph;
    InitGraph(graph, 4, 5);
    for (int i = 0; i < graph.mNodeCount; i++)
    {
        for (int j = 0; j < graph.mNodeCount; j++)
        {
            printf("%4d ", graph.mNeigborMatrix[i][j]);
        }
        cout << endl;
    }
    cout << endl;
    DFS(graph, 2);
    cout << endl;
    for (int i = 0; i < graph.mNodeCount; i++)
    {
        graph.mIsSelect[i] == false;
    }
    int dis[MAX_NODE], path[MAX_NODE];
    GetShorestPath(graph, 0, dis, path);
    for (int i = 0; i < graph.mNodeCount; i++)
    {
        cout << dis[i] << endl;
    }
}
