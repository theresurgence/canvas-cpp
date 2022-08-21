#include "Config.h"
#include "Courses.h"

//https://canvas.instructure.com/doc/api/files.html

int main()
{
    Config::readConfigFile();
    auto courses = Courses("student");

    courses.refresh();
    courses.download();
}
