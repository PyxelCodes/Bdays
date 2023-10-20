#include "readConfig.h"

Json::Value readConfig(char** path) {
	Json::Value root;
	std::ifstream jsonFile(*path, std::ifstream::binary);

	if (jsonFile.is_open()) {
		Json::CharReaderBuilder renderBuilder;
		std::string errs;

		Json::parseFromStream(renderBuilder, jsonFile, &root, &errs);
		jsonFile.close();

		std::cout << errs << std::endl;
		std::cout << jsonFile.binary;

		//if (strcmp("", errs.c_str())) {
			return root;
		//}
		//else {
			//std::cerr << "Error parsing JSON: " << errs << std::endl;
		//	exit(1);
		//}
	}
	else {
		std::cerr << "Failed to open JSON file" << std::endl;
	}
}