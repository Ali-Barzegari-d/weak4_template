#pragma once
#include <string>
#include <cstdio>

// Task: Implement RAII wrapper for FILE*

class FileRAII {
public:
    // open file with given name and mode
    FileRAII(const std::string& filename, const std::string& mode);

    // no copy
    FileRAII(const FileRAII&) = delete;
    FileRAII& operator=(const FileRAII&) = delete;

    // allow move
    FileRAII(FileRAII&& other) noexcept;
    FileRAII& operator=(FileRAII&& other) noexcept;

    // close file in destructor
    ~FileRAII();

    // check if file is valid
    bool valid() const;

    // expose FILE* for minimal usage
    FILE* get() const;

private:
    FILE* handle_{nullptr};
};
