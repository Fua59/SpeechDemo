#include <cstdio>
#include <cstring>

class Speaker
{
private:
    int no;
    char name[10];
    double score;
public:
    static int idx;
    void Init();
    bool operator < (const Speaker &s);
    void Calscore();
    void Print();
    int Getno();
    double Getscore();
};
