/**
 * C++ wrapper functions for raylib.
 */
#ifndef __FUNCTIONS__
#define __FUNCTIONS__

#include <string>
#include <vector>

#include <raylib.h>

namespace raylib {
    /**
     * Initialize window and OpenGL context
     */
    static void InitWindow(int const width, int const height, std::string const &title = "raylib");

    /**
     * Set title for window
     */
    static void SetWindowTitle(std::string const &title);

    /**
     * Get the human-readable, UTF-8 encoded name of the primary monitor
     */
    static std::string GetMonitorName(int const monitor = 0);

    /**
     * Set clipboard text content
     */
    static void SetClipboardText(std::string const &text);

    /**
     * Get clipboard text content
     */
    static std::string GetClipboardText();

    /**
     * Takes a screenshot of current screen (saved a .png)
     */
    static void TakeScreenshot(std::string const &fileName);

    /**
     * Load text data from file (read)
     */
    static std::string LoadFileText(std::string const &fileName);

    /**
     * Save text data to file (write)
     */
    static bool SaveFileText(std::string const &fileName, std::string const &text);

    /**
     * Check if file exists
     */
    static bool FileExists(std::string const &fileName);

    /**
     * Check if directory path exists
     */
    static bool DirectoryExists(std::string const &dirPath);

    /**
     * Check file extension (including point: .png, .wav)
     */
    static bool IsFileExtension(std::string const &fileName, std::string const &ext);

    /**
     * Get pointer to extension for a filename string (including point: ".png")
     */
    static std::string GetFileExtension(std::string const &fileName);

    /**
     * Get pointer to filename for a path string
     */
    static std::string GetFileName(std::string const &filePath);

    /**
     * Get filename string without extension
     */
    static std::string GetFileNameWithoutExt(std::string const &filePath);

    /**
     * Get full path for a given fileName with path
     */
    static std::string GetDirectoryPath(std::string const &filePath);

    /**
     * Get previous directory path for a given path
     */
    static std::string GetPrevDirectoryPath(std::string const &dirPath);

    /**
     * Get current working directory
     */
    static std::string GetWorkingDirectory();

    /**
     * Get filenames in a directory path
     */
    static std::vector<std::string> GetDirectoryFiles(std::string const &dirPath);

    /**
     * Change working directory, return true on success
     */
    static bool ChangeDirectory(std::string const &dir);

    /**
     * Get dropped files names
     */
    static std::vector<std::string> GetDroppedFiles();

    /**
     * Get file modification time (last write time)
     */
    static long GetFileModTime(std::string const &fileName);

    /**
     * Open URL with default system browser (if available)
     */
    static void OpenURL(std::string const &url);

    /**
     * Check gamepad name (if available)
     */
    static bool IsGamepadName(int const gamepad, std::string const &name);

    /**
     * Update camera depending on selected mode
     */
    static void UpdateCamera(const ::Camera& camera);

    /**
     * Load an image.
     */
    static ::Image LoadImage(std::string const &fileName);

    /**
     * Load an image from RAW file data
     */
    static ::Image LoadImageRaw(std::string const &fileName,
            int const width, int const height,
            int const format, int const headerSize);

    /**
     * Load animated image data
     */
    static ::Image LoadImageAnim(std::string const &fileName, int *frames);

    /**
     * Load image from memory buffer, fileType refers to extension like "png"
     */
    static ::Image LoadImageFromMemory(std::string const &fileType, unsigned char const *fileData, int const dataSize);

    /**
     * Export image data to file
     */
    static bool ExportImage(Image const &image, std::string const &fileName);

    /**
     * Export image as code file (.h) defining an array of bytes
     */
    static bool ExportImageAsCode(Image const &image, std::string const &fileName);
}

#endif  // __FUNCTIONS__
