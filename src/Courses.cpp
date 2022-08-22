#include "Courses.h"
#include "Course.h"
#include "Web.h"
#include <string>

Courses::Courses(std::string role) : m_role{role} {}

void Courses::download() const
{
    for (const auto &course : m_courses) {
        course.download();
    }
}

void Courses::refresh()
{
    const auto coursesJson = Web::getJson(Web::epCourses("student"));

    m_courses.reserve(coursesJson.size());

    for (const auto &course : coursesJson) {
        m_courses.emplace_back(course["id"], course["name"], course["course_code"]);
    }

    for (auto &course : m_courses) {
        course.refresh();
    }
}

const std::string &Courses::role() const
{
    return m_role;
}
