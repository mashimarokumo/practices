#include<iostream>

using namespace std;

class Point{
public:
    int x;
    int y;
    Point(int _x, int _y){
        x = _x;
        y = _y;
    }
    Point(){}
};

class stack{    
public:
    stack(){
        pointer = -1;
    }
    void push(Point p){
        ps[++pointer] = p;
    }
    void pop(){
        pointer--;
    }
    Point top(){
        return ps[pointer];
    }
    int size(){
        return pointer + 1;
    }

    Point ps[100];
private:
    int pointer;
};

int main(){
    int m, n;
    cin >> m >> n;
    stack st;
    stack ans;

    int mize[m][n];
    bool hasChecked[m][n] = {false};
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mize[i][j];
        }
    }

    st.push(Point(0, 0));
    hasChecked[0][0] = true;
    while (st.size() >= 1)
    {
        if(st.top().x == m - 1 && st.top().y == n - 1){
            if(ans.size() == 0 || ans.size() > st.size()) ans = st;
            st.pop();
            st.pop();
        }

        Point p = Point(st.top().x, st.top().y);
        //right
        if(p.x < m-1 && mize[p.x + 1][p.y] == 0 && !hasChecked[p.x + 1][p.y]){
            st.push(Point(p.x + 1, p.y));
            hasChecked[p.x + 1][p.y] = true;
        }//down
        else if (p.y < n-1 && !mize[p.x][p.y + 1] && !hasChecked[p.x][p.y + 1])
        {
            st.push(Point(p.x, p.y + 1));
            hasChecked[p.x][p.y + 1] = true;
        }//left
        else if (p.x > 0 && !mize[p.x - 1][p.y] && !hasChecked[p.x - 1][p.y])
        {
            st.push(Point(p.x - 1, p.y));
            hasChecked[p.x - 1][p.y] = true;
        }//up
        else if (p.y > 0 && !mize[p.x][p.y - 1] && !hasChecked[p.x][p.y - 1])
        {
            st.push(Point(p.x, p.y - 1));
            hasChecked[p.x][p.y - 1] = true;
        }else if(st.size() > 1){
            st.pop();
        }else if(ans.size() == 0){
            cout << -1;
            return 0;
        }else{
            cout << "(0,0)";
            for (int i = 1; i < ans.size(); i++)
            {
                cout << endl;
                cout << '(' << ans.ps[i].x << "," << ans.ps[i].y << ")";
            }
            return 0;
        }
    }
    
    
}