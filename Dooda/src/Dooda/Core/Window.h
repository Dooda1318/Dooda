#pragma once

#include "Ddpch.h"

#include "Dooda/Events/Event.h"

namespace Dooda 
{

	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Dooda Engine", unsigned int width = 2560, unsigned int height = 1440)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	// Interface representing a desktop system based Window
	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

	public: //Getters
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attributes
		virtual bool GetVSync() const = 0;
		virtual void* GetNativeWindow() const = 0;

	public: //Setters
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;

	public: //Static Functions
		static Scope<Window> SD_Create(const WindowProps& props = WindowProps());
	};
}