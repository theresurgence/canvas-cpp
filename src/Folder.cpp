#include "Folder.h"
#include "Config.h"
#include "Web.h"

Folder::Folder(std::string id, std::string path, std::string courseCode)
    : m_id{std::stoi(id)}, m_path{std::filesystem::path(courseCode) / std::filesystem::path(path)}
{}

bool Folder::exists() const
{
    return std::filesystem::exists(m_path);
}

void Folder::download() const
{
    for (auto file : m_files) {
        file.download();
    }
}

void Folder::createDir() const
{
    std::filesystem::create_directories(absPath());
}

void Folder::refresh()
{
    const auto filesJson = Web::getJson(Web::epFilesInFolder(m_id));
    m_files.reserve(filesJson.size());


    for (const auto &file : filesJson) {
        // Skip folder if empty
        if (file.size() <= 1) {
            continue;
        }
        m_files.emplace_back(file["id"], file["filename"], file["size"].dump(), file["url"], m_path);
    }
}

std::filesystem::path Folder::absPath() const
{
    return Config::downloadDir() / m_path;
}

int Folder::id() const
{
    return m_id;
}

const std::filesystem::path &Folder::path() const
{
    return m_path;
}

const std::vector<File> &Folder::files() const
{
    return m_files;
}
