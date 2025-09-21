#include "file_raii.hpp"

// TODO: Implement constructor, move, destructor, valid, get

FileRAII::FileRAII(const std::string& filename, const std::string& mode) {
    // TODO: open file
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
}

bool FileRAII::valid() const {
    // TODO
    return false;
}

FILE* FileRAII::get() const {
    return handle_;
}
