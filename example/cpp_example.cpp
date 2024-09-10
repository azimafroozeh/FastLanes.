#include "data/fastlanes_data.hpp"
#include "fastlanes.hpp"
#include "fls/connection.hpp"
#include <iostream>

using namespace fastlanes; // NOLINT
int main() {
	Connection con;
	const path fastlanes_repo_data_path {CMAKE_SOURCE_DIR};
	const path arade_dir_path     = fastlanes_repo_data_path / string(public_bi::Arade);
	const path example_1_dir_path = fastlanes_repo_data_path / string(GENERATED::EXAMPLE_1);
	const path example_2_dir_path = fastlanes_repo_data_path / string(GENERATED::EXAMPLE_2);
	const path fls_dir_path       = fastlanes_repo_data_path / "data" / "fls";

	{
		// example 1: single column encoding from memory:
		constexpr int64_t     N_TUP {64 * 1024};
		array<int64_t, N_TUP> input_arr {};
		array<int64_t, N_TUP> encoded_arr {};
		array<int64_t, N_TUP> output_arr {};
		bsz_t                 encoded_bsz = 0;

		for (size_t i = 0; i < N_TUP; ++i) {
			input_arr[i] = 1370;
		}

		Connection::encode_from_memory(input_arr.data(), //
		                               N_TUP,
		                               encoded_arr.size() * 8,
		                               encoded_arr.data(),
		                               &encoded_bsz,
		                               DataType::INT64,
		                               1);
		Connection::decode_to_memory(encoded_arr.data(), output_arr.data(), DataType::INT64);

		for (size_t i = 0; i < N_TUP; ++i) {
			if (output_arr[i] != input_arr[i]) { throw std::runtime_error("decoding failed"); }
		}

		std::cout << encoded_bsz << "\n";

		exit(EXIT_SUCCESS);
	}
	{
		// Example 2: [WIP] Process a CSV file
		// Step 1: Reset the connection and read the CSV file from the specified directory path
		con.reset().read(example_2_dir_path);

		// Step 2: Write the data to the FastLanes file format in the specified directory
		con.to_fls(fls_dir_path);

		// Step 3: Reset the connection again and obtain a FastLanes reader for the previously stored data
		auto& fls_reader = con.reset().read_fls(fls_dir_path);

		// Step 4: Write the data from the FastLanes format back to a CSV file in the specified directory
		fls_reader.to_csv(fls_dir_path);
	}

	return 0;
}
