#ifndef FILE_H
#define FILE_H

#include <filesystem>
#include <string>

class File
{
public:
    File(std::string id, std::string path, std::string size, std::string url);
    bool exists();
    bool same_size();
    void download();

private:
    int m_id;
    std::filesystem::path m_path;
    unsigned long m_size;
    std::string m_url;
    // TODO: enum file status? based on size <=>
};

#endif // FILE_H
