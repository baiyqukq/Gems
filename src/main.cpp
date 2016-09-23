#include "Engine.h"

int main(int argc, char **argv)
{
    Engine *e = Engine::Instance();

    return e->exec();
}

