#ifndef __DATABASE_H_
#define __DATABASE_H_

#include <map>
#include "Header.h"
#include <vector>
#include <iostream>
#include "Objects.h"

class PROJECT_EXPORT DataBase {
public:

	DataBase() = default;
	~DataBase() = default;

	void addObject(object::ptr obj);
	void removeObject(const int objectId);
	int getObjectsCount() const;

	std::vector<object::ptr> getObjects() const;
	object::ptr getObject(const int objectId) const;

	using ptr = std::shared_ptr<DataBase>;

private:

	std::vector<object::ptr> objects;
};


#endif __DATABASE_H_
