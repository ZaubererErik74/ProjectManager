#pragma once
#include <Windows.h>
#include <filesystem>
#include <string>
#include <sstream>
#include <iomanip>
#include <objbase.h>

namespace fs = std::filesystem;

class SourceFile {
private:
	fs::path filePath;
    std::string id;
public:
	SourceFile() = default;
	explicit SourceFile(fs::path filePath);

	fs::path getFileName() const;
	fs::path getExtension() const;
	fs::path getParentPath() const;

	std::string getFileNameString() const;
	std::string getExtensionString() const;
	std::string getParentPathString() const;
    std::string getID() const;
};
std::string generateGUID();