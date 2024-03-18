#ifndef __OPERATIONWITHDATABASE_H_
#define __OPERATIONWITHDATABASE_H_

#include <iostream>
#include "DataBase.h"


struct OperationWithDataBase {

	std::shared_ptr<DataBase> loadDb(const std::string& filename);
	void saveDb(std::shared_ptr<DataBase> db, const std::string& filename);

	void addEntity(std::shared_ptr<DataBase> db);
	void removeEntity(std::shared_ptr<DataBase> db, const int typeId, const int objectId);
	void editEntity(std::shared_ptr<DataBase> db);
	void listEntities(std::shared_ptr<DataBase> db);
	void drawObject(std::shared_ptr<DataBase> db, const std::string& filename);
};








#endif __OPERATIONWITHDATABASE_H_
