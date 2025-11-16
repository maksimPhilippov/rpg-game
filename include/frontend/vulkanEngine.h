#include <vk_types.h>
#include <vk_initializers.h>

#include "VkBootstrap.h"

class VulkanEngine {
public:

	VkInstance _instance;// Vulkan library handle
	VkDebugUtilsMessengerEXT _debug_messenger;// Vulkan debug output handle
	VkPhysicalDevice _chosenGPU;// GPU chosen as the default device
	VkDevice _device; // Vulkan device for commands
	VkSurfaceKHR _surface;// Vulkan window surface

	void init_vulkan();
	void init_swapchain();
	void init_commands();
	void init_sync_structures();
}