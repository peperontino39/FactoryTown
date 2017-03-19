#pragma once
#include "../CinderFwd.h" 

//�O���b�g���̕`��
//�傫���ƊԊu������
void drawGrid(const float&, const float&);

//�K�w�Ȃ��̃t�@�C����
std::string FileName(const std::string& _path);

//�g���q�Ȃ��t�@�C����
std::string NonExtensionFileName(const std::string& _path);

//json->Vec3f
ci::Vec3f JtoVec3f(ci::JsonTree& _json);

//camera�̕�����������]�s��
ci::Matrix44f getLookMatrix(const ci::Vec3f& vec);

//camera�̕�����������]�s��Y�����̂�
ci::Matrix44f getLookMatrixY(const ci::Vec3f& vec);

//�؂���ʒu��ݒ�ł���plane
//������N�_�ɉE���Ɂ{
//�؂���ʒu�ƃT�C�Y�i�O�`�P�j
void drawQuad(const ci::Vec2f&, const ci::Vec2f&);

//
template<typename First, typename... Second>
void Log(const First&, const Second&...);
void Log();
template<typename First, typename ...Second>
inline void Log(const First & _first, const Second & ... second)
{
	cinder::app::console() << _first;
}
