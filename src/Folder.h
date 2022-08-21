#ifndef FOLDER_H
#define FOLDER_H

#include <filesystem>
#include <string>
#include <vector>

class File;

class Folder
{
public:
    Folder(std::string id, std::string path);
    bool exists();
    void download();
    void create_dir();
    void refresh();

private:
    int m_id;
    std::filesystem::path m_path;
    std::vector<File> m_files;
};
#endif // FOLDER_H
