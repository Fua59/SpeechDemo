#include <cstdio>
#include <cstdlib>
#include "SpeechManager.hpp"

int main()
{
    SpeechManager sm;
    while(true)
    {
        Speaker::idx = 1;
        sm.Init();
        sm.Menu();

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // 开始演讲比赛
            sm.startSpeech();
            break;
        case 2: // 查看往届记录
            sm.printFile();
            break;
        case 3: // 清空比赛记录
            sm.clearFile();
            break;
        case 0: // 退出比赛程序
            sm.exitSys();
            break;
        default:
            system("cls");
            break;
        }

        system("cls");
    }

    return 0;
}