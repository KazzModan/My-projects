#include "AbstractFactory.h"

//windows

void WindowsButton::show()
{
	std::cout << "this is windows batton\n";
}

void WindowsButton::use()
{
	std::cout << "we use windows batton\n";
}

void WindowsWindow::show()
{
	std::cout << "this is windows window\n";
}

void WindowsWindow::use()
{
	std::cout << "we use windows window\n";
}

void WindowsCursor::show()
{
	std::cout << "this is windows cursor\n";
}

void WindowsCursor::use()
{
	std::cout << "we use window cursor\n";
}

void WindowsMenu::show()
{
	std::cout << "this is windows menu\n";
}

void WindowsMenu::use()
{
	std::cout << "we use windows menu\n";
}

Button* WindowsFactory::createButton()
{
	return new WindowsButton;
}

Window* WindowsFactory::createWindow()
{
	return new WindowsWindow;
}

Menu* WindowsFactory::createMenu()
{
	return new WindowsMenu;
}

Cursor* WindowsFactory::createCursor()
{
	return new WindowsCursor;
}

//linux

void LinuxButton::show()
{
	std::cout << "this is linux batton\n";
}

void LinuxButton::use()
{
	std::cout << "we use linux batton\n";
}

void LinuxWindow::show()
{
	std::cout << "this is linux window\n";
}

void LinuxWindow::use()
{
	std::cout << "we use linux window\n";
}

void LinuxCursor::show()
{
	std::cout << "this is linux cursor\n";
}

void LinuxCursor::use()
{
	std::cout << "we use linux cursor\n";
}

void LinuxMenu::show()
{
	std::cout << "this is linux menu\n";
}

void LinuxMenu::use()
{
	std::cout << "we use linux menu\n";
}

Button* LinuxFactory::createButton()
{
	return new LinuxButton;
}

Window* LinuxFactory::createWindow()
{
	return new LinuxWindow;
}

Menu* LinuxFactory::createMenu()
{
	return new LinuxMenu;
}

Cursor* LinuxFactory::createCursor()
{
	return new LinuxCursor;
}

//macos

void MacOsButton::show()
{
	std::cout << "this is macos batton\n";
}

void MacOsButton::use()
{
	std::cout << "we use macos batton\n";
}

void MacOsWindow::show()
{
	std::cout << "this is macos window\n";
}

void MacOsWindow::use()
{
	std::cout << "we use macos window\n";
}

void MacOsCursor::show()
{
	std::cout << "this is macos cursor\n";
}

void MacOsCursor::use()
{
	std::cout << "we use macos cursor\n";
}

void MacOsMenu::show()
{
	std::cout << "this is macos menu\n";
}

void MacOsMenu::use()
{
	std::cout << "we use macos menu\n";
}

Button* MacOsFactory::createButton()
{
	return new MacOsButton;
}

Window* MacOsFactory::createWindow()
{
	return new MacOsWindow;
}

Menu* MacOsFactory::createMenu()
{
	return new MacOsMenu;
}

Cursor* MacOsFactory::createCursor()
{
	return new MacOsCursor;
}

