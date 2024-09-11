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
/*
 *
 * */
std::byte* Mmap::Open(bsz_t init_bsz, int& fd, const std::filesystem::path& path) {
	/**/
#if defined(_WIN32)
	// Use _open() on Windows
	fd = open(path.c_str(), _O_RDWR | _O_CREAT, _S_IREAD | _S_IWRITE);
#else
	// Use POSIX open() on Linux/macOS
	fd = open(path.c_str(), O_RDWR | O_CREAT, 0777);
#endif

	if (fd == -1) {
		/**/
		throw std::runtime_error(strerror(errno));
	}

	struct stat file_info {};
	if (stat(path.c_str(), &file_info) == -1) { throw std::runtime_error("stat"); }

	if (file_info.st_size == 0) {
		if (ftruncate(fd, static_cast<off_t>(init_bsz)) == -1) { throw std::runtime_error("Error resizing the file"); }
		if (stat(path.c_str(), &file_info) == -1) { throw std::runtime_error("stat"); }
	}

	auto* p = reinterpret_cast<std::byte*>(
	    mmap(nullptr, static_cast<size_t>(file_info.st_size), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0));
	return p;
}

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

template <typename T>
T* Mmap::Open(bsz_t bsz, int& fd, const std::filesystem::path& path) {
	return reinterpret_cast<T*>(Open(bsz, fd, path));
}

template int64_t*  Mmap::Open<>(bsz_t bsz, int& fd, const std::filesystem::path& path);
template uint64_t* Mmap::Resize<>(bsz_t bsz, int& fd);

} // namespace fastlanes