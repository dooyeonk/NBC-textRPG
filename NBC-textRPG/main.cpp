#include <cstdlib>
#include <ctime>
#include <windows.h>

#include "Core/GameManager/GameManager.h"
#include "Entities/Character/Character.h"

int main()
{
    // 한글 출력을 위한 설정
    SetConsoleOutputCP(CP_UTF8);
    // 한글 입력
    SetConsoleCP(CP_UTF8);
    setvbuf(stdout, nullptr, _IOFBF, 1000);

    srand(time(NULL));
    GameManager gm;
    gm.run();
    return 0;
}
