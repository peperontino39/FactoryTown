#pragma once
#include "cinder/app/App.h"
#include <unordered_map>
#include "cinder/CinderMath.h"
#include "EasingInfos/EasingInfos.h"
#include "cinder/Easing.h"

template <class T>
class Easing
{
public:
	static void update() {

		for (auto it = easingInfos().begin();
		it != easingInfos().end();)
		{
			if (!it->second.update()) {
				it = easingInfos().erase(it);
			}
			else {
				it++;
			}
		}
	}
	template <class T>
	static EasingInfo<T>& apply(
		T& _terget,
		const T& _endValue,
		std::function<float(float)> _easeFunction,
		float _time = 1.f)		//�C�[�W���O��ςݏグ�čs��
	{
		return easingInfos()[&_terget].apply(_terget, _endValue, _easeFunction, _time);
	}

	template <class T>
	static void clear(T& _terget)	//�ςݏグ���C�[�W���O�����ׂ�
	{
		
		auto it = easingInfos().find(&_terget);
		if (it == easingInfos().end())return;
		easingInfos().erase(it);
	}

private:
	static std::unordered_map <void*, EasingInfos<T>>&  easingInfos();

};

template<class T>
inline std::unordered_map<void*, EasingInfos<T>>& Easing<T>::easingInfos()
{
	static std::unordered_map <void*, EasingInfos<T>>  _easingInfos;
	return _easingInfos;
}

/*�C�[�W���O�֐��Q
//
EaseInQuad()
EaseOutQuad()
EaseInOutQuad()
EaseOutInQuad()

EaseInCubic()
EaseOutCubic()
EaseInOutCubic()
EaseOutInCubic()

EaseInQuart()
EaseOutQuart()
EaseInOutQuart()
EaseOutInQuart()

EaseInQuint()
EaseOutQuint()
EaseInOutQuint()
EaseOutInQuint()

EaseInSine()
EaseOutSine()
EaseInOutSine()
EaseOutInSine()

EaseInExpo()
EaseOutExpo()
EaseInOutExpo()
EaseOutInExpo()

EaseInCirc()
EaseOutCirc()
EaseInOutCirc()
EaseOutInCirc()

EaseInAtan()
EaseOutAtan()
EaseInOutAtan()
EaseNone()

EaseInBack()
EaseOutBack()
EaseInOutBack()
EaseOutInBack()

EaseInBounce()
EaseOutBounce()
EaseInOutBounce()
EaseOutInBounce()

EaseInElastic(2, 1)
EaseOutElastic(1, 4)
EaseInOutElastic(2, 1)
EaseOutInElastic(1, 4)
*/