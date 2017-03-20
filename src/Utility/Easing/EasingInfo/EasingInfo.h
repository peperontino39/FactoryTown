#pragma once
#include <functional>


template <class T>
class EasingInfo
{
public:
	EasingInfo(
		T _beginValue,
		T _endValue,
		float _startTime,
		float _endTime,
		std::function<float(float)> _easeFunction) {

		easeFunction = _easeFunction;
		startTime = _startTime;
		endTime = _endTime;
		beginValue = _beginValue;
		endValue = _endValue;
	};

	T getValue(float time) {
		return getLerpValue((time - startTime) / (endTime - startTime));
	}
	T getLerpValue(float t) {
		return lerp(beginValue, endValue, easeFunction(t));
	}
	void setEndFnction(std::function<void()> Fn){ endFnction = Fn}


private:
	template <class T>
	friend class EasingInfos;

	std::function<float(float)> easeFunction;
	float startTime;
	float endTime;
	T beginValue;
	T endValue;
	std::function<void()> endFnction = [] {};
};