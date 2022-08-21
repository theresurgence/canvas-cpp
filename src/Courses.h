#ifndef COURSES_H
#define COURSES_H

#include "Course.h"
#include <string>
#include <vector>

class Courses
{
public:
    Courses(std::string role);
    void download() const;
    void refresh();

    const std::string &role() const;

private:
    std::string m_role;
    std::vector<Course> m_courses;
};
#endif // COURSES_H
