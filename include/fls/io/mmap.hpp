#ifndef FLS_IO_MMAP_HPP
#define FLS_IO_MMAP_HPP

#include "fls/common/common.hpp"
#include <filesystem>

namespace fastlanes {
class Mmap {
public:
	static std::byte* Resize(bsz_t bsz, int& fd);
	template <typename T>
	static T*   Resize(bsz_t bsz, int& fd);
	static void Close(void* p, bsz_t bsz, int& fd);
};
} // namespace fastlanes

#endif // FLS_IO_MMAP_HPP
