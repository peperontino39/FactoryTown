#pragma once
#include "../EasingInfo/EasingInfo.h"
#include <List>


template <class T>
class EasingInfos
{

public:
	bool update() {
		if (easingInfos.size() == 0)
			return false;

		auto begin = easingInfos.begin();
		*target = begin->getValue(getElapsedSeconds());
		if (begin->endTime < getElapsedSeconds())
		{
			*target = begin->endValue;	//イージングが終了したらTargetをその値にする
			
			easingInfos.erase(begin);
		}
		return true;
	}
	EasingInfo<T>& apply(
		T& _terget,
		const T& _endValue,
		std::function<float(float)> _easeFunction,
		const float& _time) {

		T bigin_value;
		float one_ease_start_time_;

		if (easingInfos.size() == 0) {
			target = &_terget;
			startTime = getElapsedSeconds();

			bigin_value = _terget;
			one_ease_start_time_ = startTime;

		}
		else
		{
			bigin_value = easingInfos.back().endValue;
			one_ease_start_time_ = easingInfos.back().endTime;
		}
		easingInfos.push_back(EasingInfo<T>(
			bigin_value,
			_endValue,
			one_ease_start_time_,
			one_ease_start_time_ + _time,
			_easeFunction));
		return easingInfos.back();
	}
private:
	T* target;
	float startTime;
	std::list<EasingInfo<T>> easingInfos;
};