#ifndef COURSES_H
#define COURSES_H

#include <string>
#include <vector>

class Courses
{
public:
    Courses(std::string role);
    void download();
    void refresh();

private:
    std::string m_role;
    std::vector<Courses> m_courses;
};
#endif // COURSES_H
