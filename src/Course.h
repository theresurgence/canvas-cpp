#ifndef COURSE_H
#define COURSE_H

#include "Folder.h"
#include <filesystem>
#include <string>
#include <vector>

class Course
{
public:
    Course(std::string id, std::string name, std::string code, std::string role);
    void download() const;
    void createDirs() const;
    void refresh();

    int id() const;
    const std::string &name() const;
    int code() const;
    const std::string &role() const;
    const std::vector<Folder> &folders() const;

private:
    int m_id;
    std::string m_name;
    int m_code;
    std::string m_role; //TODO is this needed?
    std::vector<Folder> m_folders;
};

#endif // COURSE_H
