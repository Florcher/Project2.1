#include "Vectoriser.h"
#include "Drawer.h"
#include "FileType.h"
#include "DataBase.h"

std::shared_ptr<Drawer> getDrawer(const FileType& filetype, const std::string& fileName) {

	if (filetype == FileType::txt)
		return std::make_shared<TextDrawer>(fileName);

	if (filetype == FileType::binary)
		return std::make_shared<BinaryDrawer>(fileName);;

	if (filetype == FileType::console)
		return std::make_shared<ConsoleDrawer>();
}

void Vectoriser::draw(std::shared_ptr<DataBase> db, const std::string& filename) {

	auto f = getFileType(filename);

	if (f == FileType::unknown)
		throw std::exception();

	auto drawer = getDrawer(f, filename);

	for (int i = 0; i < db->objects.size(); ++i) {

		int typeId = db->typeIds[i];

		for (int j = 1; j <= db->objects.at(typeId).size(); ++j) {

			int objectId = db->objects.at(typeId).at(j)->getId();
			auto obj = db->objects.at(typeId).at(objectId);
			obj->draw(drawer);
		}
	}

}