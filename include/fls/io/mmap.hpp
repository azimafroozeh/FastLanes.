#ifndef FLS_IO_MMAP_HPP
#define FLS_IO_MMAP_HPP

#include "fls/common/common.hpp"
#include <filesystem>

namespace fastlanes {
class Mmap {
public:
	static std::byte* Open(bsz_t bsz, int& fd, const std::filesystem::path& path);
	template <typename T>
	static T*         Open(bsz_t bsz, int& fd, const std::filesystem::path& path);
	static std::byte* Resize(bsz_t bsz, int& fd);
	template <typename T>
	static T*   Resize(bsz_t bsz, int& fd);
	static void Close(void* p, bsz_t bsz, int& fd);
};
} // namespace fastlanes

#endif // FLS_IO_MMAP_HPP
