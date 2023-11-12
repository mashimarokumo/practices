class Solution {
public:
    int distMoney(int money, int children) {
        if((money == 4 && children == 1) || money < children) return -1;
        int l = 0, r = children;

        while (l < r)
        {
            int mid = (l + r + 1) / 2;
            if(check(money, children, mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        
        return check(money, children, l) ? l : 0;
    }

    bool check(int m, int ch, int ei){
        m -= ei * 8;
        if(m < 0 || ei == 0) return false;
        ch -= ei;

        if((m == 4 && ch == 1) || (m < ch) || (ch == 0 && m > 0)) return false;
        return true;
    }
};