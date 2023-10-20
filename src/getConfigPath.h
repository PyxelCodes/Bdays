#pragma once

#include <sstream>
#include <iostream>

#ifdef _WIN32
#include <ShlObj.h>
#endif

#include <cstdlib>

void getConfigPath(char** str);