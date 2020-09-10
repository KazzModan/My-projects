#include "AbstractFactory.h"
#include "tinyxml2.h"

#pragma warning(disable : 26812)

OSType getOSTypeFromFile(std::string file);
namespace xml = tinyxml2;

#define CHECK_WINDOWS (type == "windows" || type == "Windows" || type == "WINDOWS" || type == "WIN" || type == "win")
#define CHECK_LINUX (type == "linux" || type == "Linux" || type == "LINUX")
#define CHECK_MACOS (type == "mac" || type == "macos" || type == "MACOS" || type == "MAC" || type == "MACINTOSH")

int main()
{
	Factory* factory = nullptr;

	Menu* menu = nullptr;
	Window* window = nullptr;
	Cursor* cursor = nullptr;
	Button* button = nullptr;

	OSType type = getOSTypeFromFile("os.xml");

	switch (type)
	{
	case OSType::WINDOWS:	factory = new WindowsFactory;			break;
	case OSType::LINUX:		factory = new LinuxFactory;				break;
	case OSType::MACOS:		factory = new MacOsFactory;				break;
	case OSType::NONE:		std::cout << "eror: file not found\n";	break;
	}

	if (factory != nullptr)
	{
		menu = factory->createMenu();
		window = factory->createWindow();
		cursor = factory->createCursor();
		button = factory->createButton();
	}

	delete factory;
	factory = nullptr;

	size_t size = 4;
	Object** objects = new Object * [size] { menu, window, cursor, button };

	for (size_t i = 0; i < size; i++)
		if (objects[i] != nullptr)
			objects[i]->show();

	for (size_t i = 0; i < size; i++)
	{
		delete objects[i];
		objects[i] = nullptr;
	}

	delete[] objects;

	return 0;
}

OSType getOSTypeFromFile(std::string file)
{
	xml::XMLDocument doc;

	if (doc.LoadFile(file.c_str()) == xml::XMLError::XML_ERROR_FILE_NOT_FOUND)
		return OSType::NONE;

	if (doc.LoadFile(file.c_str()) == xml::XMLError::XML_ERROR_FILE_READ_ERROR)
		return OSType::NONE;

	if (doc.FirstChildElement("settings") == nullptr)
		return OSType::NONE;;

	xml::XMLElement* element = doc.FirstChildElement("settings");

	if (element->FirstChildElement("os") == nullptr)
		return OSType::NONE;;

	element = element->FirstChildElement("os");

	if (element->FindAttribute("type") == nullptr)
		return OSType::NONE;;

	std::string type = element->FindAttribute("type")->Value();

	if (CHECK_WINDOWS)
		return OSType::WINDOWS;
	else if (CHECK_LINUX)
		return OSType::LINUX;
	else if (CHECK_MACOS)
		return OSType::MACOS;

	return OSType::NONE;
}
