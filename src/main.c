#include "runner.h"

int main(int argc, char **argv)
{
    if (!launcher(argc, argv))
        return 84;
    return 0;
}
