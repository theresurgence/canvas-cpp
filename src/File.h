#ifndef FILE_H
#define FILE_H

#include <filesystem>
#include <string>

class File
{
public:
    File(std::string id, std::string path, std::string size, std::string url);
    bool exists();
    bool sameSize();
    void download();
    std::filesystem::path absPath();

    int id() const;
    const std::filesystem::path &path() const;
    unsigned long size() const;
    const std::string &url() const;

private:
    int m_id;
    std::filesystem::path m_path;
    unsigned long m_size;
    std::string m_url;
    // TODO: enum file status? based on size <=>
};

#endif // FILE_H
