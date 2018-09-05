
#pragma once

#include "json98.h"

namespace sdkbox
{
#define GAME_SERVICES_CHECK \
	if (nullptr == _game_services) \
	{ \
		sdkbox::Json::object_type ret; \
		ret["result"] = sdkbox::Json(ERROR_INVALID_GAME_SERVICES); \
        sdkbox::GPGWrapper::NotifyToScripting(callback_id, sdkbox::Json(ret).dump()); \
		return; \
	}

#define NULL_PTR_CHECK(pointer) \
    if (nullptr == pointer) \
    { \
		sdkbox::Json::object_type ret; \
        ret["result"] = sdkbox::Json(ERROR_NULL_POINTER); \
		sdkbox::GPGWrapper::NotifyToScripting(callback_id, sdkbox::Json(ret).dump()); \
        return; \
    }

	// template class to convert a vector into a json array given a conversion functor.
	template <class T>
	Json convert_vector_T(const std::vector<T>& input, Json(*functor)(const T&))
	{
		Json::array_type a;
		for (const auto i : input)
			a.push_back(functor(i));
		return Json(a);
	}
}