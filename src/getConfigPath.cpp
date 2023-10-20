#include "getConfigPath.h"

void getConfigPath(char** pathstr) {
	std::ostringstream path;

#if defined(_WIN32)
	PWSTR appDataPath = nullptr;

	if (SUCCEEDED(SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, NULL, &appDataPath)))
	{
		char appData[MAX_PATH];
		WideCharToMultiByte(CP_UTF8, 0, appDataPath, -1, appData, MAX_PATH, NULL, NULL);

		path << appData;
		path << "\\bdays.json";

		CoTaskMemFree(appDataPath);
	}
#else
	// unix
	char* homeDir = std::getenv("HOME");
	path << homeDir;
	path << "/.config/bdays.json";
#endif

	*pathstr = strdup(path.str().c_str());
}