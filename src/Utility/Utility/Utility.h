#pragma once
#include "../CinderFwd.h" 

//グリット線の描画
//大きさと間隔が引数
void drawGrid(const float&, const float&);

//階層なしのファイル名
std::string FileName(const std::string& _path);

//拡張子なしファイル名
std::string NonExtensionFileName(const std::string& _path);

//json->Vec3f
ci::Vec3f JtoVec3f(ci::JsonTree& _json);

//cameraの方向を向く回転行列
ci::Matrix44f getLookMatrix(const ci::Vec3f& vec);

//cameraの方向を向く回転行列Y方向のみ
ci::Matrix44f getLookMatrixY(const ci::Vec3f& vec);

//切り取り位置を設定できるplane
//左上を起点に右下に＋
//切り取り位置とサイズ（０～１）
void drawQuad(const ci::Vec2f&, const ci::Vec2f&);

//
template<class First, class... Second>
void Log(First, Second...);
void Log();
template<class First, class... Second>
inline void Log(First _first,Second... second)
{
	cinder::app::console() << _first << " ";
	Log(second...);
}
