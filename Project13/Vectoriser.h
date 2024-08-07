#ifndef __VECTORISER_H_
#define __VECTORISER_H
#include "kernel_export.h"
#include <iostream>
#include "DataBase.h"
#include "DrawData.h"
#include "map"

class KERNEL_EXPORT Vectoriser {
public:

	void draw(std::shared_ptr<DataBase> db);

	DrawData::ptr getData(int entityID) const;

	using ptr = std::shared_ptr<Vectoriser>;

private:
	std::map<int, DrawData::ptr> data;
};

#endif __VECTORISER_H_
