#ifndef WEB_H
#define WEB_H

#include "Config.h"
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
    static cpr::Response getRequest(const std::string &url);
    static json getJson(const std::string &api_endpoint);
    static void downloadFile(const File &file);

    static std::string epPersonalFolders();
    static std::string epCourses(const std::string &role);
    static std::string epFoldersInCourse(int courseId);
    static std::string epFilesInFolder(int folderId);

private:
    // static inline std::string EP_COURSES;
    // static inline std::string EP_PERSONAL_FOLDERS;
    static inline std::string URL_API_VERSION{"api/v1/"};
};

#endif // WEB_H
