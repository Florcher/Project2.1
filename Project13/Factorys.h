#ifndef __FACTORYS_H_
#define __FACTORYS_H_
#include "kernel_export.h"

template <typename TBase>
struct KERNEL_EXPORT Creator {

	virtual std::shared_ptr<TBase> create() = 0;
};

template <typename TBase, typename TDerived>
struct KERNEL_EXPORT ObjectCreator : public Creator<TBase> {

	std::shared_ptr<TBase> create() override
	{
		return std::make_shared<TDerived>();
	}

};
 
#endif __FACTORYS_H_

