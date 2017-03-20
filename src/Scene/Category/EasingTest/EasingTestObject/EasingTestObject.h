#pragma once
#include "../../../../GameObject/GameObject.h"


#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/Easing.h"
#include "cinder/Text.h"

const float TWEEN_SPEED = 0.5f;

struct EaseBox {
public:
	EaseBox(std::function<float(float)> fn, std::string name)
		: mFn(fn)
	{
		// create label
		ci::TextLayout text; text.clear(ci::Color::white()); text.setColor(ci::Color(0.5f, 0.5f, 0.5f));
		try { text.setFont(ci::Font("Futura-CondensedMedium", 18)); }
		catch (...) { text.setFont(ci::Font("Arial", 18)); }
		text.addLine(name);
		mLabelTex = ci::gl::Texture(text.render(true));
	}

	void draw(float t) const
	{
		// draw box and frame
		ci::gl::color(ci::Color(1.0f, 1.0f, 1.0f));
		ci::gl::drawSolidRect(mDrawRect);
		ci::gl::color(ci::Color(0.4f, 0.4f, 0.4f));
		ci::gl::drawStrokedRect(mDrawRect);
		ci::gl::color(ci::Color::white());
		ci::gl::draw(mLabelTex, mDrawRect.getCenter() - mLabelTex.getSize() / 2);

		// draw graph
		ci::gl::color(ci::ColorA(0.25f, 0.5f, 1.0f, 0.5f));
		glBegin(GL_LINE_STRIP);
		for (float x = 0; x < mDrawRect.getWidth(); x += 0.25f) {
			float y = 1.0f - mFn(x / mDrawRect.getWidth());
			ci::gl::vertex(ci::Vec2f(x, y * mDrawRect.getHeight()) + mDrawRect.getUpperLeft());
		}
		glEnd();

		// draw animating circle
		ci::gl::color(ci::Color(1, 0.5f, 0.25f));
		ci::gl::drawSolidCircle(mDrawRect.getUpperLeft() + mFn(t) * mDrawRect.getSize(), 5.0f);
	}

	std::function<float(float)>	mFn;
	ci::Rectf							mDrawRect;
	ci::gl::Texture						mLabelTex;
};

class EasingTestObject : public GameObject
{
public:
	void setup()override;

	void nonLightDraw()override;
	void resize()override;
	void sizeRectangles();

	std::vector<EaseBox>		mEaseBoxes;
};