#include <cstdio>
#include <vector>
#include "speaker.hpp"

class SpeechManager
{
private:
    std::vector<Speaker> v;
public:
    void Init();
    void Menu();
    void exitSys();
    void startSpeech();
    void Print(int l, int r);
    void printFile();
    void clearFile();
};