#include "File.h"
#include "Config.h"
#include "Web.h"

File::File(std::string id, std::string path, std::string size, std::string url)
    : m_id{std::stoi(id)}, m_path{std::filesystem::path(path)}, m_size{std::stoul(size)}, m_url{url}
{}

bool File::exists()
{
    return std::filesystem::exists(m_path);
}

bool File::sameSize()
{
    return std::filesystem::file_size(absPath()) == m_size;
}

void File::download()
{
    Web::downloadFile(*this);
}

std::filesystem::path File::absPath()
{
    return Config::downloadDir() / m_path;
}

int File::id() const
{
    return m_id;
}

const std::filesystem::path &File::path() const
{
    return m_path;
}

unsigned long File::size() const
{
    return m_size;
}

const std::string &File::url() const
{
    return m_url;
}
