#include <windows.h>
#include <string>
#include <vector>
#include "SourceFile.h"
#include <unordered_map>

class Project {
private:
	std::string name;
	COLORREF accentColor;
	std::unordered_map<std::string, SourceFile> sourceFiles;
public:
	Project(std::string name);

	void addSourceFile(SourceFile sourceFile);
	void printProjectData() const;
};