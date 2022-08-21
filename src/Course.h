#ifndef COURSE_H
#define COURSE_H

#include <filesystem>
#include <string>
#include <vector>

class Folder;

class Course
{
public:
    Course(std::string id, std::string name, std::string code, std::string role);
    void download();
    void create_dirs();
    void refresh();

private:
    int m_id;
    std::string m_name;
    int m_code;
    std::string m_role;
    std::vector<Folder> m_folders;
};

#endif // COURSE_H
