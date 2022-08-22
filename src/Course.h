#ifndef COURSE_H
#define COURSE_H

#include "Folder.h"
#include <filesystem>
#include <string>
#include <vector>

class Course
{
public:
    Course(std::string id, std::string name, std::string code);
    void download() const;
    void createDirs() const;
    void refresh();

    int id() const;
    const std::string &name() const;
    const std::string &code() const;
    const std::vector<Folder> &folders() const;

private:
    int m_id;
    std::string m_name;
    std::string m_code;
    std::vector<Folder> m_folders;
};

#endif // COURSE_H
