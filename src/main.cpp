#include "Config.h"

int main()
{
    auto Configure{Config()};
    Configure.readConfigFile();
}
