#include <string>
#include <vector>

using namespace std;
string num[3] = {"1", "2", "4"};

string solution(int n) {
    string answer = "";
    
    while(n) {
        n--;
        answer.insert(0, num[n % 3]);
        n /= 3;
    }
    return answer;
}