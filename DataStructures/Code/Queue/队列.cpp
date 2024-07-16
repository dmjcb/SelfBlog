#include <stdio.h>
#include <stdlib.h>
#include <iostream>

const int MAXPARKSPORT = 5;

typedef struct
{
    char flag;
    int licensePlate;

} Car, *CarList;

typedef struct
{
    Car *base;
    int front;
    int rear;
} Road, *RoadList;

void Init(Road &r)
{
    r.base = (CarList)malloc(MAXPARKSPORT * sizeof(Road));
    if (!r.base)
    {
        exit(0);
    }

    r.front = r.rear = 0;
}

void Driving(Road &r, Car &elem)
{
    if ((r.rear + 1) % MAXPARKSPORT == r.front)
    {
        return;
    }

    r.base[r.rear] = elem;

    r.rear = (r.rear + 1) % MAXPARKSPORT;
}

void Leave(Road &r, Car &c)
{
    if (r.front == r.rear)
    {
        return;
    }
    c = r.base[r.front];

    r.front = (r.front + 1) % MAXPARKSPORT;
}

int GetCarIndex(Road &r, Car &elem)
{
    for (int i = r.rear; i >= r.front; i--)
    {
        if (elem.licensePlate == r.base[i].licensePlate)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    Car c;
    Road r;

    Init(r);
    for (int i = 0; i < 3; i++)
    {
        std::cin >> c.flag >> c.licensePlate;
        Driving(r, c);
    }
    std::cin >> c.flag >> c.licensePlate;
    std::cout << GetCarIndex(r, c);
}
