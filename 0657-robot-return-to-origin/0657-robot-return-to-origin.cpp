class Solution {
public:
    bool judgeCircle(string moves) {
        long long int hori = 0, vert = 0;
        long long int n = moves.size();
        for(int i=0; i<n; i++)
        {
            if(moves[i] == 'L') hori = hori-1;
            else if(moves[i] == 'R') hori = hori+1;
            else if(moves[i] == 'U') vert = vert+1;
            else if(moves[i] == 'D') vert = vert-1;
        }
        if(hori==0 && vert==0) return true;
        else return false;
    }
};