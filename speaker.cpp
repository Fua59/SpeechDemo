#include "speaker.hpp"
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

int Speaker::idx = 1;
bool Speaker::operator<(const Speaker &s)
{
    return score > s.score;
}
void Speaker::Calscore()
{
    int maxscore = 200;
    int minscore = 0;
    int sum = 0;
    for(int i = 0; i < 10; i++)
    {
        int tmp = rand() % 31 + 70; // 生成[70,100]的随机数，模拟打分
        maxscore = std::max(maxscore, tmp);
        minscore = std::min(minscore, tmp);
        sum += tmp;
    }
    sum -= maxscore + minscore;
    score = 1.0 * sum / 8;
}
void Speaker::Init()
{
    no = 10000 + idx;
    strcpy(name, "参赛者A");
    int len = strlen(name);
    name[len - 1] += idx - 1;
    Calscore();
    idx++; 
}
void Speaker::Print()
{
    printf("%d\t%s\t%.2f\n", no, name, score);
}
int Speaker::Getno()
{
    return no;
}
double Speaker::Getscore()
{
    return score;
}