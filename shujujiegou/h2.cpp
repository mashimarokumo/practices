#include<iostream>

using namespace std;

class Point{
public:
    int x;
    int y;
    bool left = false;
    bool right = false;
    bool up = false;
    bool down = false;
    
    bool walkable;

    int dis = 0;

    Point(int _x, int _y){
        x = _x;
        y = _y;
    }
    Point(){}
};

template<typename T> class stack{    
public:
    stack(){
        pointer = -1;
    }
    void push(T p){
        ps[++pointer] = p;
    }
    void pop(){
        pointer--;
    }
    T top(){
        return ps[pointer];
    }
    int size(){
        return pointer + 1;
    }

    T ps[1005];
private:
    int pointer;
};

int main(){
    int m, n;
    cin >> m >> n;
    stack<Point*> st;
    stack<Point*> ans;

    Point* mize[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mize[i][j] = new Point(i, j);
            int a;
            cin >> a;
            mize[i][j]->walkable = a == 0 ? true : false;
        }
    }

    st.push(mize[0][0]);

    while (st.size() >= 1)
    {
        if(st.top()->x == m - 1 && st.top()->y == n - 1){
            if(ans.size() == 0 || ans.size() > st.size()) ans = st;
            st.top()->dis = st.size() - 1;
            st.top()->walkable = true;
            st.pop();
        }

        Point* p = mize[st.top()->x][st.top()->y];
        //left
        if (p->x > 0 && mize[p->x - 1][p->y]->walkable && (!p->left || mize[p->x - 1][p->y]->dis > st.size()))
        {
            st.push(mize[p->x - 1][p->y]);
            mize[p->x - 1][p->y]->walkable = false;
            p->left = true;
        }
        //right
        else if(p->x < m-1 && mize[p->x + 1][p->y]->walkable && (!p->right || mize[p->x + 1][p->y]->dis > st.size())){
            st.push(mize[p->x + 1][p->y]);
            mize[p->x + 1][p->y]->walkable = false;
            p->right = true;
        }//up
        else if (p->y > 0 && mize[p->x][p->y - 1]->walkable && (!p->up || mize[p->x][p->y - 1]->dis > st.size()))
        {
            st.push(mize[p->x][p->y - 1]);
            mize[p->x][p->y - 1]->walkable = false;
            p->up = true;
        }//down
        else if (p->y < n-1 && mize[p->x][p->y + 1]->walkable && (!p->down || mize[p->x][p->y + 1]->dis > st.size()))
        {
            st.push(mize[p->x][p->y + 1]);
            mize[p->x][p->y + 1]->walkable = false;
            p->down = true;
        }
        else{
            st.top()->dis = st.size() - 1;
            st.top()->walkable = true;
            st.pop();
        }
    }
    
    if(ans.size() > 0){
        cout << "(0,0)";
        for (int i = 1; i < ans.size(); i++)
        {
            cout << endl;
            cout << '(' << ans.ps[i]->x << "," << ans.ps[i]->y << ")";
        }
    }else{
        cout << "-1";
    }
    
    return 0;
    
}

// else if(st.size() > 1){
//             st.pop();
//         }else if(ans.size() == 0){
//             cout << -1;
//             return 0;
//         }else{
//             cout << "(0,0)";
//             for (int i = 1; i < ans.size(); i++)
//             {
//                 cout << endl;
//                 cout << '(' << ans.ps[i].x << "," << ans.ps[i].y << ")";
//             }
//             return 0;
//         }