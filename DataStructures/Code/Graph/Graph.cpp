#include <iostream>
#include <string>
#define MAXVERTICES 20
#define MAXWEIGHT 100
using namespace std;

typedef struct
{
    // 图中实际总顶点数
    int verCount;
    // 图中实际总边数
    int lineCount;
    // 顶点表
    char verTable[MAXVERTICES];
    // 邻接矩阵
    int matrix[MAXVERTICES][MAXVERTICES];
    // 用来表示点某个点是否被选过
    bool isSelect[MAXVERTICES];
} Graph;

// 查找某个在顶点表中的位置,不存在则返回-1
int GetVerIndex(Graph &g, char val)
{
    for (int i = 0; i < g.verCount; i++)
    {
        if (g.verTable[i] == val)
        {
            return i;
        }
    }
    return -1;
}

// 查找某个顶点的第一个邻接顶点,参数为顶点在顶点表中的位置
int FindFirstNeighborVer(Graph &g, int verPos)
{
    // 如果位置合法
    if (verPos != -1)
    {
        // 遍历顶点表
        for (int j = 0; j < g.verCount; j++)
        {
            // 找到一个合法的邻接点
            if (g.matrix[verPos][j] > 0 && g.matrix[verPos][j] < MAXWEIGHT)
            {
                // 返回该邻接点的位置
                return j;
            }
        }
    }
    return -1;
}

// 找出一个顶点除一个邻接顶点之外的另一个邻接顶点
int FindAnthorNeighborVer(Graph &g, int verPos1, int verPos2)
{
    if (verPos1 != -1 && verPos2 != -1)
    {
        // 直接从 verPos2 + 1判断, 因为verPos2之前的点肯定不是其邻接点
        for (int j = verPos2 + 1; j < g.verCount; j++)
        {
            if (g.matrix[verPos1][j] > 0 && g.matrix[verPos1][j] < MAXWEIGHT)
            {
                return j;
            }
        }
    }
    return -1;
}

// 初始化图函数,n,e代表顶点数和边数
void Init(Graph &g, int n, int e)
{
    g.verCount = n;
    g.lineCount = e;
    for (int i = 0; i < g.verCount; i++)
    {
        // 标记该点为未选状态
        g.isSelect[i] == false;
        char val;
        cout << "请输入顶点值" << endl;
        // 输入顶点值
        cin >> val;
        // 更新顶点表
        g.verTable[i] = val;
        for (int j = 0; j < g.verCount; j++)
        {
            // 对角线值为0
            if (i == j)
            {
                g.matrix[i][j] = 0;
            }
            else
            {
                g.matrix[i][j] = MAXWEIGHT;
            }
        }
    }
    // 初始化每一条边
    for (int i = 0; i < g.lineCount; i++)
    {
        char e1, e2;
        int weight;
        // 输入这个边的两个点和权值
        cout << "输入这个边的两个点和权值" << endl;
        cin >> e1 >> e2 >> weight;
        // 获取这两个点在顶点表中的坐标
        int position1 = GetVerIndex(g, e1);
        int position2 = GetVerIndex(g, e2);
        // 更新邻接矩阵
        g.matrix[position1][position2] = weight;
        g.matrix[position2][position1] = weight;
    }
}

// 查找节点
char GetVer(Graph &g, int verPos)
{
    if (verPos != -1)
    {
        return g.verTable[verPos];
    }
}

// 遍历图,形参为最开始遍历的节点位置
void DFS(Graph &g, int verPos)
{
    cout << "->" << GetVer(g, verPos);
    // 标记该位置为已选
    g.isSelect[verPos] = true;
    // firstNeighborVertex表示verPos的第一个邻接点
    int pos = FindFirstNeighborVer(g, verPos);
    // 当verPos的邻接点存在时
    while (pos != -1)
    {
        // 如果该点没有被选过
        if (g.isSelect[pos] == false)
        {
            // 递归访问 下一个邻接点
            DFS(g, pos);
        }
        // 否则取 verPos 的另一个邻接点 pos
        pos = FindAnthorNeighborVer(g, verPos, pos);
    }
}

// 求verPos的最短路径
void GetShortPath(Graph &g, int verPos, int distance[], int path[])
{
    // 最短路径顶点集合
    int path[MAXVERTICES];
    for (int i = 0; i < g.verCount; i++)
    {
        // 路径长度数组初始化,其值为verPos到其他每个点的距离
        distance[i] = g.matrix[verPos][i];
        // 表示顶点i是否求得最短路径
        path[i] = 0;
        // 如果从verPos到i有边,path[i]为该边始顶点号verPos
        if (i != verPos && distance[i] < MAXWEIGHT)
        {
            path[i] = verPos;
        }
        // 若没有边则path[i]为-1
        else
        {
            path[i] = -1;
        }
    }
    // 顶点verPos加入集合path
    path[verPos] = 1;
    distance[verPos] = 0;
    // 逐个求得path到其他顶点的最短路径
    for (int i = 0; i < g.verCount - 1; i++)
    {
        int min = MAXWEIGHT;
        // 选不在 path中具有最短路径的顶点point
        int point = verPos;
        for (int j = 0; j < g.verCount; j++)
        {
            // 如果该点j没有被选入且从verPos到该点的距离小于min
            if (!path[j] && distance[j] < min)
            {
                // 更新位置
                point = j;
                // 更新最短路径
                min = distance[j];
            }
        }
        // 将顶点point加入path集合
        path[point] = 1;
        // 修改经过point到其他顶点的路径长度
        for (int k = 0; k < g.verCount; k++)
        {
            // weight为点point到点k的距离
            int weight = g.matrix[point][k];
            /* 如果点k未被选过
            且 点point到点k有边
            且 verPos到点k的距离比verPos经点point到点k的距离长*/
            if (!path[k] && weight < MAXWEIGHT && distance[point] + weight < distance[k])
            {
                // verPos到点k的距离路径可以缩短
                distance[k] = distance[point] + weight;
                // verPos到点k的前一个顶点为point
                path[k] = point;
            }
        }
    }
}

// 图的插入(插入一条边)
void InsertLine(Graph &g, int point1, int point2, int weight)
{
    if (point1 != -1 && point2 != -1)
    {
        // 邻接矩阵中添加该边
        g.matrix[point1][point2] = weight;
        g.matrix[point2][point1] = weight;
    }
}

// 图的插入(插入一个顶点)
void InsertVer(Graph &g, char val)
{
    if (g.verCount < MAXVERTICES)
    {
        // 总节点数加1
        g.verCount++;
        // 更新节点
        g.verTable[g.verCount] = val;
    }
}

// 删除一条边
void DelLine(Graph &g, int point1, int point2)
{
    // 解除边的关系
    if (point1 != -1 && point2 != -1)
    {
        g.matrix[point1][point2] = MAXWEIGHT;
        g.matrix[point1][point2] = MAXWEIGHT;
    }
}

// 删除一个顶点和相应的边
void DelLineAndVer(Graph &g, char val)
{
    // 找到该点的位置
    int pos = GetVerIndex(g, val);
    // 将它换到顶点表的最后一位上去
    int temp = g.verTable[g.verCount];
    g.verTable[g.verCount] = g.verTable[pos];
    g.verTable[pos] = temp;
    // 转化边的关系
    for (int j = 0; j < g.verCount; j++)
    {
        g.matrix[pos][j] = MAXWEIGHT;
        g.matrix[j][pos] = MAXWEIGHT;
    }
    g.matrix[pos][pos] = 0;
    // 总顶点数减1
    g.verCount--;
}

int main()
{
    Graph g;
    Init(g, 4, 5);
    for (int i = 0; i < g.verCount; i++)
    {
        for (int j = 0; j < g.verCount; j++)
        {
            printf("%4d ", g.matrix[i][j]);
        }
        cout << endl;
    }
    cout << endl;
    DFS(g, 2);
    cout << endl;
    for (int i = 0; i < g.verCount; i++)
    {
        g.isSelect[i] == false;
    }
    int distance[MAXVERTICES], path[MAXVERTICES];
    GetShortPath(g, 0, distance, path);
    for (int i = 0; i < g.verCount; i++)
    {
        cout << distance[i] << endl;
    }
}
