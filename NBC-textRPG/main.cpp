#include "Character.h"
#include "GameManager.h"
#include <cstdlib>
#include <ctime>
#include <windows.h>

int main()
{
    // 한글 출력을 위한 설정
    SetConsoleOutputCP(CP_UTF8);
    setvbuf(stdout, nullptr, _IOFBF, 1000);

    srand(time(NULL));
    GameManager gm;
    gm.run();
    return 0;
}
