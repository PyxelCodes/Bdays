// Birthdays.cpp : Defines the entry point for the application.
//

#include "Birthdays.h"
#include "Bday.h"
#include "getConfigPath.h"
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <filesystem>
#include <fstream>
#include <json/json.h>
#include "readConfig.h"
#include <time.h>
#include "printTable.h"
#include "configToBday.h"

namespace fs = std::filesystem;

int main(int argc, char* argv)
{
	Birthdays bdays;

	char* configPath;
	
	getConfigPath(&configPath);

	if (!fs::exists(configPath)) {
		std::ofstream ofs(configPath);
		ofs << "[]";
		ofs.close();
	}

	std::cout << "Found config path: " << configPath;

	Json::Value config = readConfig(&configPath);

	if (config.isArray()) {
		for (unsigned int i = 0; i < config.size(); i++) {
				const Json::Value& val = config[i];
				bdays.push_back(val);
			}
	}
	else { 
		std::cerr << "Invalid JSON formatting"; 
		exit(1);
	}

	time_t current_time;
	struct tm* time_info;

	time(&current_time);
	time_info = localtime(&current_time);

	if(!argv[1]) {
		std::cout << "Please provide a valid command";
		exit(1);
	}

	char* cmd = &argv[1];

	std::vector<Birthday> bdays_f = configToBday(bdays);

	printTable(bdays_f);

	if (strcmp(cmd, "ls")) {

	}
}