#include "./Functions.hpp"

void raylib::InitWindow(int const width, int const height, std::string const &title) {
    ::InitWindow(width, height, title.c_str());
}

void raylib::SetWindowTitle(std::string const &title) {
    ::SetWindowTitle(title.c_str());
}

std::string raylib::GetMonitorName(int const monitor) {
    return ::GetMonitorName(monitor);
}

void raylib::SetClipboardText(std::string const &text) {
    ::SetClipboardText(text.c_str());
}

std::string raylib::GetClipboardText() {
    return ::GetClipboardText();
}

void raylib::TakeScreenshot(std::string const &fileName) {
    ::TakeScreenshot(fileName.c_str());
}

std::string raylib::LoadFileText(std::string const &fileName) {
    /*unsigned char *text = ::LoadFileText(fileName.c_str());
    std::string output(text);
    ::UnloadFileText(text);
    return output;*/
    return "";
}

bool raylib::SaveFileText(std::string const &fileName, std::string const &text) {
    return ::SaveFileText(fileName.c_str(), const_cast<char*>(text.c_str()));
}

bool raylib::FileExists(std::string const &fileName) {
    return ::FileExists(fileName.c_str());
}

bool raylib::DirectoryExists(std::string const &dirPath) {
    return ::DirectoryExists(dirPath.c_str());
}

bool raylib::IsFileExtension(std::string const &fileName, std::string const &ext) {
    return ::IsFileExtension(fileName.c_str(), ext.c_str());
}

std::string raylib::GetFileExtension(std::string const &fileName) {
    return ::GetFileExtension(fileName.c_str());
}

std::string raylib::GetFileName(std::string const &filePath) {
    return ::GetFileName(filePath.c_str());
}

std::string raylib::GetFileNameWithoutExt(std::string const &filePath) {
    return ::GetFileNameWithoutExt(filePath.c_str());
}

std::string raylib::GetDirectoryPath(std::string const &filePath) {
    return ::GetDirectoryPath(filePath.c_str());
}

std::string raylib::GetPrevDirectoryPath(std::string const &dirPath) {
    return ::GetPrevDirectoryPath(dirPath.c_str());
}

std::string raylib::GetWorkingDirectory() {
    return ::GetWorkingDirectory();
}

std::vector<std::string> raylib::GetDirectoryFiles(std::string const &dirPath) {
    int count = 0;
    char **files = ::GetDirectoryFiles(dirPath.c_str(), &count);
    std::vector<std::string> output(files, files + count);
    ::ClearDirectoryFiles();
    return output;
}

bool raylib::ChangeDirectory(std::string const &dir) {
    return ::ChangeDirectory(dir.c_str());
}

std::vector<std::string> raylib::GetDroppedFiles() {
    int count;
    char **files = ::GetDroppedFiles(&count);
    std::vector<std::string> output(files, files + count);
    ::ClearDroppedFiles();
    return output;
}

long raylib::GetFileModTime(std::string const &fileName) { // NOLINT
    return ::GetFileModTime(fileName.c_str());
}

void raylib::OpenURL(std::string const &url) {
    return ::OpenURL(url.c_str());
}

bool raylib::IsGamepadName(int const gamepad, std::string const &name) {
    return ::IsGamepadName(gamepad, name.c_str());
}

void raylib::UpdateCamera(::Camera const &camera) {
    ::Camera* cameraPointer = (::Camera*)&camera;
    ::UpdateCamera(cameraPointer);
}

::Image raylib::LoadImage(std::string const &fileName) {
    return ::LoadImage(fileName.c_str());
}

::Image raylib::LoadImageRaw(std::string const &fileName,
        int const width, int const height,
        int const format, int const headerSize) {
    return ::LoadImageRaw(fileName.c_str(), width, height, format, headerSize);
}

::Image raylib::LoadImageAnim(std::string const &fileName, int *frames) {
    return ::LoadImageAnim(fileName.c_str(), frames);
}

::Image raylib::LoadImageFromMemory(std::string const &fileType,
        const unsigned char *fileData,
        int dataSize) {
    return ::LoadImageFromMemory(fileType.c_str(), fileData, dataSize);
}

bool raylib::ExportImage(Image const &image, std::string const &fileName) {
    return ::ExportImage(image, fileName.c_str());
}

bool raylib::ExportImageAsCode(Image const &image, std::string const &fileName) {
    return ::ExportImageAsCode(image, fileName.c_str());
}
