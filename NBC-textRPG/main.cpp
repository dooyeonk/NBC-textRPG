#include "Character.h"
#include "GameManager.h"
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(NULL));
    GameManager gm;
    gm.run();
    return 0;
}
