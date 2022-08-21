#include "Course.h"
#include "File.h"
#include "Web.h"

Course::Course(std::string id, std::string name, std::string code, std::string role)
    : m_id{std::stoi(id)}, m_name{name}, m_code{std::stoi(code)}, m_role{role}
{}

void Course::download() const
{
    for (const auto &folder : m_folders) {
        folder.download();
    }
}

void Course::createDirs() const
{
    for (const auto &folder : m_folders) {
        folder.createDir();
    }
}

void Course::refresh()
{
    const auto foldersJson = Web::getJson(Web::epFoldersInCourse(m_id));
    m_folders.reserve(foldersJson.size());

    for (const auto &folder : foldersJson) {
        m_folders.emplace_back(folder["id"], folder["path"]);
    }

    for (auto folder : m_folders) {
        folder.refresh();
    }
}

int Course::id() const
{
    return m_id;
}

const std::string &Course::name() const
{
    return m_name;
}

int Course::code() const
{
    return m_code;
}

const std::string &Course::role() const
{
    return m_role;
}

const std::vector<Folder> &Course::folders() const
{
    return m_folders;
}
