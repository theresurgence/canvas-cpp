#ifndef FOLDER_H
#define FOLDER_H

#include "File.h"
#include <filesystem>
#include <string>
#include <vector>

class Folder
{
public:
    Folder(std::string id, std::string path, std::string courseCode);
    bool exists() const;
    void download() const;
    void createDir() const;
    void refresh();
    std::filesystem::path absPath() const;

    int id() const;
    const std::filesystem::path &path() const;
    const std::vector<File> &files() const;

private:
    int m_id;
    std::filesystem::path m_path;
    std::vector<File> m_files;
};
#endif // FOLDER_H
