#pragma once
#include <vector>
#include <string>
#include <json/json.h>

typedef struct {
	std::string id;
	std::string name;
	std::string bday;
} jsonStruc;

std::vector<Birthday> configToBday(const std::vector<Json::Value>& data);