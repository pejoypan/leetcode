#include "c++utils.h"

class Solution {
public:
    int find_place(const vector<vector<int>> &people, const vector<int> & person) {
        int h = person[0];
        int k = person[1];

        int num = 0;
        int i = 0;
        int res = 0;
        for (; i < people.size(); i++) {
            if (people[i][0] >= h) {
                num++;
            } else {
                continue;
            }

            if (num == k) {
                res = i;
                break;
            }
        }

        i = res;

        for (; i < people.size(); i++) {
            if (people[i][1] == k && people[i][0] < h)
                res = i;
        }
        

        return res;
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        auto func = [](const vector<int> &lhs, const vector<int> &rhs){
            return lhs[1] < rhs[1] || (lhs[1] == rhs[1] && lhs[0] < rhs[0]);
        };

        sort(people.begin(), people.end(), func);

        vector<vector<int>> res;

        res.push_back(people.front());
        for (int i = 1; i < people.size(); i++) {
            const auto& person = people[i];
            int idx = find_place(res, person);
            res.insert(res.begin() + idx + 1, person);
        }

        return res;

    }
};

int main()
{
    vector<vector<int>> people = {{6,0},{5,0},{4,0},{3,2},{2,2},{1,4}};
    Solution solve;
    auto res = solve.reconstructQueue(people);
    print(res);
}