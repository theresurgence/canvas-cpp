#ifndef WEB_H
#define WEB_H

#include <cpr/cpr.h>
#include <fmt/core.h>
#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

class File;

class Web
{
public:
    Web() = delete; //TODO check if correct
    static json getJson(const std::string &api_endpoint);
    static void downloadFile(const File &file);

    static std::filesystem::path getDownloadDir();

    static std::string epPersonalFolders();
    static std::string epCourses(const std::string &role);
    static std::string epFoldersInCourse(int courseId);
    static std::string epFilesInFolder(int folderId);

private:
    static std::filesystem::path DOWNLOAD_DIR;
    static std::string URL_BASE;
    static std::string EP_COURSES;
    static std::string EP_PERSONAL_FOLDERS;
};

#endif // WEB_H
