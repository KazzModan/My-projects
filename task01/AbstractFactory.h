#pragma once
#include <iostream>

enum class OSType
{
	NONE,
	WINDOWS,
	LINUX,
	MACOS,
};

class Object abstract 
{
public:
	virtual void show() = 0;
};

class Button abstract : public Object
{
public:
	virtual void use() = 0;
};

class Window abstract : public Object
{
public:
	virtual void use() = 0;
};

class Cursor abstract : public Object
{
public:
	virtual void use() = 0;
};

class Menu abstract : public Object
{
public:
	virtual void use() = 0;
};

class Factory abstract
{
public:
	virtual Button* createButton() = 0;
	virtual Window* createWindow() = 0;
	virtual Menu* createMenu() = 0;
	virtual Cursor* createCursor() = 0;
};

//windows

class WindowsButton : public Button
{
public:
	void show() override;
	void use() override;
};

class WindowsWindow : public Window
{
public:
	void show() override;
	void use() override;
};

class WindowsCursor : public Cursor
{
public:
	void show() override;
	void use() override;
};

class WindowsMenu : public Menu
{
public:
	void show() override;
	void use() override;
}; 

class WindowsFactory : public Factory
{
public:
	Button* createButton() override;
	Window* createWindow() override;
	Menu* createMenu() override;
	Cursor* createCursor() override;
};

//linux

class LinuxButton : public Button
{
public:
	void show() override;
	void use() override;
};

class LinuxWindow : public Window
{
public:
	void show() override;
	void use() override;
};

class LinuxCursor : public Cursor
{
public:
	void show() override;
	void use() override;
};

class LinuxMenu : public Menu
{
public:
	void show() override;
	void use() override;
};

class LinuxFactory : public Factory
{
public:
	Button* createButton() override;
	Window* createWindow() override;
	Menu* createMenu() override;
	Cursor* createCursor() override;
};

//macos

class MacOsButton : public Button
{
public:
	void show() override;
	void use() override;
};

class MacOsWindow : public Window
{
public:
	void show() override;
	void use() override;
};

class MacOsCursor : public Cursor
{
public:
	void show() override;
	void use() override;
};

class MacOsMenu : public Menu
{
public:
	void show() override;
	void use() override;
};

class MacOsFactory : public Factory
{
public:
	Button* createButton() override;
	Window* createWindow() override;
	Menu* createMenu() override;
	Cursor* createCursor() override;
};

