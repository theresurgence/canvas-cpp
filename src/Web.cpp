#include "Web.h"
#include "File.h"
#include <fmt/core.h>

json Web::getJson(const std::string &api_endpoint)
{
    auto url = Config::baseUrl() + api_endpoint;

    cpr::Response r = cpr::Get(cpr::Url{url},
                               cpr::HttpVersion{cpr::HttpVersionCode::VERSION_2_0},
                               cpr::Header{{"Accept", "application/json+canvas-string-ids"},
                                           {"Authorization",
                                            fmt::format("Bearer {}", Config::authToken())}});
    return json::parse(r.text);
}

//TODO how to deal with partially downloaded files/ modified files
void Web::downloadFile(const File &file)
{
    const auto file_abs_path = Config::downloadDir() / file.path();
    fmt::print("{}\n", file_abs_path.generic_string());

    if (!std::filesystem::exists(file_abs_path)) {
        std::ofstream of(file_abs_path, std::ios::binary);
        cpr::Response r = cpr::Download(of, cpr::Url{file.url()});

        fmt::print("Downloading.... {}\n", file_abs_path.generic_string());
    } else {
        fmt::print("Skipped {}\n", file_abs_path.generic_string());
    }
}

std::string Web::epPersonalFolders()
{
    return "users/self/folders";
}

std::string Web::epCourses(const std::string &role)
{
    return "courses";
}

std::string Web::epFoldersInCourse(int courseId)
{
    return fmt::format("courses/{}/folders/", courseId);
}

std::string Web::epFilesInFolder(int folderId)
{
    return fmt::format("folders/{}/files/", folderId);
}
