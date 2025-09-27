class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        long double area = 0;
        for(int i=0; i<points.size(); i++)
        {
            for(int j=i+1; j<points.size(); j++)
            {
                for(int k=j+1; k<points.size(); k++)
                {
                    long long int x1 = points[i][0], y1 = points[i][1];
                    long long int x2 = points[j][0], y2 = points[j][1];
                    long long int x3 = points[k][0], y3 = points[k][1];
                    long double currarea = x1*(y2-y3) + (x2*(y3-y1)) + (x3*(y1-y2));
                    currarea = abs(currarea);
                    currarea = currarea/2;
                    area = max(area, currarea);
                }
            }
        }
        return area;
    }
};