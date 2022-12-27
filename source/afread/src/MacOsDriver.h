
#ifndef AFREAD_INCLUDE_MACOSDRIVER_H_
#define AFREAD_INCLUDE_MACOSDRIVER_H_

#include "Affinity/Archive.h"

namespace afread {

class MACOSDriver: public AffinityReader::Driver
{
public:
	MACOSDriver();

	bool                       Open(const std::string& file_name) override;
	void                       Close() override;
	void                       Read(void* data, size_t size, size_t* bytes_read = 0) override;
	AffinityReader::ByteBuffer Read(size_t size) override;
	bool                       Seek(uint64_t offset) override;
	bool                       IsEOF() override;
	AffinityReader::ByteBuffer DecompressZip(const AffinityReader::ByteBuffer& buf) override;
	AffinityReader::ByteBuffer DecompressZstd(const AffinityReader::ByteBuffer& buf) override;
	uint32_t                   Crc32(const AffinityReader::ByteBuffer& buf) override;

protected:
	std::string m_file_name;
	FILE*       m_file = {nullptr};
};

} // namespace afread

#endif /* AFREAD_INCLUDE_MACOSDRIVER_H_ */