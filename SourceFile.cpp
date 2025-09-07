#include "SourceFile.h"
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

fs::path SourceFile::getFileName() const {
	return this->filePath.filename();
}
fs::path SourceFile::getExtension() const {
	return this->filePath.extension();
}
fs::path SourceFile::getParentPath() const {
	return this->filePath.parent_path();
}

std::string SourceFile::getFileNameString() const {
	return this->filePath.filename().string();
}
std::string SourceFile::getExtensionString() const {
	return this->filePath.extension().string();
}
std::string SourceFile::getParentPathString() const {
	return this->filePath.parent_path().string();
}
std::string SourceFile::getID() const {
	return this->id;
}

SourceFile::SourceFile(fs::path filePath) {
	this->filePath = filePath;
	this->id = generateGUID();
}

std::string generateGUID() {
    GUID guid;
    CoCreateGuid(&guid);

    std::ostringstream oss;
    oss << std::hex << std::setfill('0')
        << std::setw(8) << guid.Data1
        << "-"
        << std::setw(4) << guid.Data2
        << "-"
        << std::setw(4) << guid.Data3
        << "-";
    for (int i = 0; i < 2; i++)
        oss << std::setw(2) << (int)guid.Data4[i];
    oss << "-";
    for (int i = 2; i < 8; i++)
        oss << std::setw(2) << (int)guid.Data4[i];
        return oss.str();
}