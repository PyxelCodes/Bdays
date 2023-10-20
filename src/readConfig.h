#pragma once

#include <iostream>
#include <fstream>
#include <json/json.h>

Json::Value readConfig(char** path);