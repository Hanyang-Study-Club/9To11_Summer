using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = money;
    for(int i = 1; i <= count; i++)
    {
        answer -= price * i;
    }
    if(answer > 0)
        return 0;
    else
        return -answer;

    return answer;
}