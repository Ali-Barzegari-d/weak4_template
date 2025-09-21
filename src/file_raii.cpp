#include "file_raii.hpp"

// TODO: Implement constructor, move, destructor, valid, get

FileRAII::FileRAII(const std::string& filename, const std::string& mode) {
    // TODO: open file
    handle_ = std::fopen(filename.c_str(), mode.c_str());
}

FileRAII::FileRAII(FileRAII&& other) noexcept
    : handle_(other.handle_) {
    other.handle_ = nullptr;
}

FileRAII& FileRAII::operator=(FileRAII&& other) noexcept {
    if (this != &other) {
        if (handle_) std::fclose(handle_);
        handle_ = other.handle_;
        other.handle_ = nullptr;
    }
    return *this;
}

FileRAII::~FileRAII() {
    // TODO: close file if open
    if (handle_) {
        std::fclose(handle_);
        handle_ = nullptr;
    }
}

bool FileRAII::valid() const {
    // TODO
    return handle_ != nullptr;
    //return false;
}

FILE* FileRAII::get() const {
    return handle_;
}
