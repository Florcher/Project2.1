#include "objects.h"
#include "objectFactory.h"
#include "Header.h"
#include "Input.h"
#include "InputFiler.h"
#include "DataBase.h"
#include "FileType.h"


std::shared_ptr<InputFiler> createFiler(const FileType& filetype, const std::string& fileName) {

	if (filetype == FileType::txt) 
		return std::make_shared<InTextFiler>(fileName);

	if (filetype == FileType::binary)
        return std::make_shared<InBinaryFiler>(fileName);;
	
	if(filetype == FileType::console)
		return std::make_shared<InConsoleFiler>();
}


std::shared_ptr<DataBase> Input::input(const std::string& fileName) {

	auto f = getFileType(fileName);

	if (f == FileType::unknown)
		throw std::exception();

	auto filer = createFiler(f, fileName);

	auto objFactory = std::make_shared<ObjectFactory>();

	int count = filer->readInt();

	if ((count > std::numeric_limits<int32_t>::max()) or (count < 0))
		throw std::exception();

	auto db = std::make_shared<DataBase>();

	for (int i = 0; i < count; ++i) {

		int typeId = filer->readInt();
		auto name = filer->readString();
		int objectId = filer->readInt();
		auto obj = objFactory->getObject(typeId);
		obj->setId(objectId);
		obj->setName(name);
		obj->input(filer);
		db->addObject(typeId,obj);
	}

	return db;
}