#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long queue1_sum, queue2_sum, half_sum, queue1_max, queue2_max;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    
    for(int i = 0; i < queue1.size(); i++) {
        queue1_sum += queue1[i];
        queue2_sum += queue2[i];
        if(queue1_max < queue1[i]) {
            queue1_max = queue1[i];
        }
        if(queue2_max < queue2[i]) {
            queue2_max = queue2[i];
        }
    }

    if((queue1_sum + queue2_sum) % 2 == 1) {
        return -1;
    }
    half_sum = ceil((queue1_sum + queue2_sum) / 2);
    if((queue1_max > half_sum) || (queue2_max > half_sum)) {
        return -1;
    }

    int queueSize = queue1.size() + queue2.size();
    while(queue1_sum != queue2_sum) {
        if(queue1_sum > queue2_sum) {
            queue2.push_back(queue1[0]);
            queue1_sum -= queue1[0];
            queue2_sum += queue1[0];
            queue1.erase(queue1.begin());
        }
        else if(queue1_sum < queue2_sum) {
            queue1.push_back(queue2[0]);
            queue1_sum += queue2[0];
            queue2_sum -= queue2[0];
            queue2.erase(queue2.begin());
        }
        answer++;
    }
    
    return answer;
}
