#pragma once
#include <stdint.h>
#include <vector>
#include <string>

typedef struct _PluginList {
	std::string		pluginName;
	HMODULE			module;
	void*			processtickAddress;
} PluginList;
extern std::vector<_PluginList> loadedPlugins;

_PluginList getLoadedPluginByName(const char* name);
void addPluginToList(const char* pluginName, HMODULE module, void* processtickAddr);
void* tryGetProcAddr(_PluginList &plugin, const char* fnName);
void* tryGetProcAddr(HMODULE module, const char* fnName);