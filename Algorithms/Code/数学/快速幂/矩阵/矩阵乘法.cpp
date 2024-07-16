#include<iostream>
#define N 2
using namespace std;
typedef long long ll;

class Matrix {
    public :
        Matrix() {}
        void input() ;
        Matrix operator * (Matrix &M2);
        void setX(int x1) {
            x=x1;
        }
        void setY(int y1) {
            y=y1;
        }
        void setM(int x,int y,ll num) {
            m[x][y]=num;
        }
        int getX() {
            return x;
        }
        int getY() {
            return y;
        }
        ll getM(int x,int y) {
            return m[x][y];
        }
    private:
        int x;
        int y;
        ll m[N][N];
};

void input(Matrix &a) {
    int x,y,num;
    cin>>x>>y;
    a.setX(x);
    a.setY(y);
    for(int i = 0; i<x; i++) {
        for(int j = 0; j<y; j++) {
            cin>>num;
            a.setM(i,j,num);
        }
    }
}

//A(n)(m)*B(m)(k)
Matrix multiplication(Matrix &a,Matrix &b) {
    Matrix c;
    c.getM(a.getX(),b.getY());
    for(int i =0; i<a.getX(); i++) {
        for(int j=0; j<b.getY(); j++) {
            for(int k=0; k<a.getY(); k++) {
                c.setM(i,j)+=(a.setM(i,k)*b.getM(k,j));
            }
        }
    }
    return c;
}

int main() {
    Matrix a,b;


}
