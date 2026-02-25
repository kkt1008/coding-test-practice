#include <vector>
#include <climits>
using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    answer.reserve(queries.size());

    for (const auto& q : queries) {
        int s = q[0], e = q[1], k = q[2];

        int best = INT_MAX;
        for (int i = s; i <= e; ++i) {
            if (arr[i] > k) best = min(best, arr[i]);
        }

        answer.push_back(best == INT_MAX ? -1 : best);
    }

    return answer;
}
