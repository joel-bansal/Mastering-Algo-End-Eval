class Solution {
public:

    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

    int scheduleCourse(vector<vector<int>>& courses) {
        // vector<vector<int>> sets;
        int sum=0;
        sort(courses.begin(),courses.end(),compare);

        priority_queue<int> maxH;

        for(auto i: courses){
            sum += i[0];
            maxH.push(i[0]);

            if(sum>i[1]){
                sum-=maxH.top();
                maxH.pop();
            }
        }

        // while(!maxH.empty()){
        //     cout<<maxH.top();
        //      maxH.pop();
        // }

        return maxH.size();
    }
};