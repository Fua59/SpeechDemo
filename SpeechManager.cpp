#include "SpeechManager.hpp"
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
typedef std::vector<Speaker>::iterator iter;
void SpeechManager::Init()
{
    v.clear();
}
void SpeechManager::Menu()
{
    printf("********************************\n");
    printf("******* 欢迎参加演讲比赛 *******\n");
    printf("******** 1. 开始演讲比赛 *******\n");
    printf("******** 2. 查看往届记录 *******\n");
    printf("******** 3. 清空比赛记录 *******\n");
    printf("******** 0. 退出比赛程序 *******\n");
    printf("********************************\n\n");
}
void SpeechManager::exitSys()
{
    printf("欢迎下次使用！\n");
    system("pause");
    exit(0);
}
void SpeechManager::Print(int l, int r)
{
    printf("编号\t姓名\t成绩\t\n");
    for(int i = l; i < r; i++)
        v[i].Print();
    printf("=============================\n\n");
}
void SpeechManager::startSpeech()
{
    printf("开始第<<1>>次比赛\n");
    system("pause");

    Speaker sk;
    for(int j = 0; j < 12; j++)
    {
        sk.Init();
        v.push_back(sk);
    }

    for(int i = 0; i < 2; i++) // 分组并排序
    {
        printf("这是第%d组\n", i + 1);
        std::sort(v.begin()+ i * 6, v.begin() + 6 + i * 6);
        Print(0 + i * 6, 6 + i * 6);
    }
    system("pause");

    printf("开始第<<2>>次比赛\n");
    system("pause");

    iter it = v.begin() + 3;
    v.erase(it, it + 3);
    for(int i = 0; i < 3; i++)
        v.pop_back();
    std::sort(v.begin(), v.end());
    Print(0, 6);

    std::ofstream file("data.csv", std::ios::app); // 将结果写入文件
    if(!file.is_open())
        printf("打开文件失败\n");
    else
    {
        for(int i = 0; i < 3; i++)
        {
            if(i)
                file << ",";
            file << std::to_string(v[i].Getno()) << "," << std::to_string(v[i].Getscore());
        } 
        file << std::endl;
        file.close();
        printf("记录完毕\n");
    }
    system("pause");
}
void SpeechManager::printFile() // 读取文件
{
    const char info[3][10] = {"冠军","亚军","季军"};

    std::ifstream file("data.csv", std::ios::in);
    if(!file.is_open())
       printf("打开文件失败\n");
    else
    {
        std::string line;
        std::istringstream iss;
        int idx = 1;
        while(std::getline(file, line))
        {
            printf("第%d届演讲比赛\n", idx++);
            iss.clear();
            iss.str(line);
            std::string token;
            for(int i = 0; i < 3; i++)
            {
                printf("%s:", info[i]);
                std::getline(iss, token, ',');
                std::cout << token << "\t";
                std::getline(iss, token, ',');
                printf("%.2f\n", std::stod(token));
            }
        }
        file.close();
    }
    printf("打印完毕\n");
    system("pause");
}
void SpeechManager::clearFile()
{
    std::ofstream file("data.csv", std::ios::trunc);
    printf("清空完毕\n");
    system("pause");
}