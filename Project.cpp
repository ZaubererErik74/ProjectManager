#include "Project.h"
#include <unordered_map>
#include <iostream>

#define SAC_GRAY RGB(200,200,200)

Project::Project(std::string name) {
	this->name = name;
	this->accentColor = SAC_GRAY;
	this->sourceFiles = std::unordered_map<std::string, SourceFile>();
}
void Project::addSourceFile(SourceFile sourceFile) {
	this->sourceFiles.emplace(sourceFile.getID(), sourceFile);
}
void Project::printProjectData() const{
	std::cout << "Name: " << this->name << std::endl;


}