#include <cassert>
#include "file_raii.hpp"

int main() {
    {
        FileRAII f("test_output.txt", "w");
        assert(f.valid());

        FILE* raw = f.get();
        assert(raw != nullptr);

        // write something
        const char* msg = "Hello RAII\n";
        std::fputs(msg, raw);
    } // f goes out of scope -> file should be closed automatically

    // reopen file to check content
    {
        FILE* check = std::fopen("test_output.txt", "r");
        assert(check != nullptr);

        char buffer[64];
        char* ok = std::fgets(buffer, sizeof(buffer), check);
        assert(ok != nullptr);
        assert(std::string(buffer) == "Hello RAII\n");

        std::fclose(check);
    }

    return 0;
}
