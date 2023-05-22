#include <string>
#include <vector>
#include <queue>
using namespace std;

long long sum1, sum2;
int answer, index1, index2;

int solution(vector<int> queue1, vector<int> queue2) {
    queue<int> q1, q2;

    for (int i = 0; i < queue1.size(); i++) {
        q1.push(queue1[i]);
        sum1 += queue1[i];
        
        q2.push(queue2[i]);
        sum2 += queue2[i];
    }

    int maxIndex = queue1.size() + queue2.size();

    while (index1 < maxIndex && index2 < maxIndex) { 
        if (sum1 == sum2) {
            return answer;
        }

        if (sum1 < sum2) {
            int cur = q2.front();
            q2.pop();
            q1.push(cur);
            sum1 += cur;
            sum2 -= cur;
            index2++;
        }
        else {
            int cur = q1.front();
            q1.pop();

            q2.push(cur);
            sum2 += cur;
            sum1 -= cur;
            index1++;
        }
        answer++;
    }

    return -1;
}