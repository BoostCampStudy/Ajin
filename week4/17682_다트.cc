#include <string>
#include <cmath>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int temp = 0, num = 0;
    
    for(int i = 0; i < dartResult.size(); i++)
    {   
        if(isdigit(dartResult[i]))
        {
            temp = num;
            
            if(dartResult[i + 1] == '0')
            {
                num = 10;
                i++;
            }
            else
                num = dartResult[i] - '0';
        }
        else if(isalpha(dartResult[i]))
        {
            if(dartResult[i] == 'D')
                num = pow(num, 2);
            else if(dartResult[i] == 'T')
                num = pow(num, 3);
            
            if(dartResult[i + 1] == '*')
            {
                answer -= temp;
                temp *= 2;
                num *= 2;
                i++;
                answer += temp;
            }
            else if(dartResult[i + 1] == '#')
            {
                num *= -1;
                i++;
            }
            answer += num;
        }
    }
    return answer;
}