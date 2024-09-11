#include "fls/io/mmap.hpp"
#include <cstring>
#include <sys/fcntl.h>
#if defined(_WIN32)
#include <windows.h> // For Windows memory-mapping
#define open  _open
#define close _close
#else
#include <sys/mman.h> // For POSIX memory-mapping
#endif
#include <sys/stat.h>
#include <unistd.h>

namespace fastlanes {

void Mmap::Close(void* p, bsz_t bsz, int& fd) {
	/**/
	if (munmap(p, bsz) == -1) { throw std::runtime_error(strerror(errno)); }
	close(fd);
}

std::byte* Mmap::Resize(bsz_t bsz, int& fd) {
	if (ftruncate(fd, static_cast<off_t>(bsz)) == -1) { throw std::runtime_error("Error resizing the file"); }
	auto* p = reinterpret_cast<std::byte*>(mmap(nullptr, bsz, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0));
	return p;
}

template <typename T>
T* Mmap::Resize(bsz_t bsz, int& fd) {
	return reinterpret_cast<T*>(Resize(bsz, fd));
}

template uint64_t* Mmap::Resize<>(bsz_t bsz, int& fd);

} // namespace fastlanes