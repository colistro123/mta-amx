#include "StdInc.h"

_PluginList getLoadedPluginByName(const char* name) {
	for (const auto& plugin : loadedPlugins) {
		if (!strcmp(plugin.pluginName.c_str(), name)) {
			return plugin;
		}
	}
	return _PluginList{}; //Just return an unset struct to check against if it doesn't exist so they can != nullptr
}
void addPluginToList(const char* pluginName, HMODULE module, void* processtickAddr) {
	_PluginList new_plugin;
	memset(&new_plugin, 0, sizeof(PluginList));

	new_plugin.module = module;
	new_plugin.pluginName = std::string(pluginName);
	new_plugin.processtickAddress = tryGetProcAddr(module, "ProcessTick");
	loadedPlugins.push_back(new_plugin);
}
void* tryGetProcAddr(_PluginList &plugin, const char* fnName) {
	if (plugin.processtickAddress == nullptr) {
		plugin.processtickAddress = (void*)getProcAddr(plugin.module, fnName);
	}
	return plugin.processtickAddress;
}
void* tryGetProcAddr(HMODULE module, const char* fnName) {
	return (void*)getProcAddr(module, fnName);
}