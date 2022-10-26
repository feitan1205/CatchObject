#include "DxLib.h"
#include "game.h"
#include "SceneTest.h"


namespace
{
	constexpr int kObjectNum = 4;
}

SceneTest::SceneTest() :
	m_circle(kObjectNum)
{
}

void SceneTest::init()
{
	int index = 0;
	int color = 255;
	for (auto& obj : m_circle)
	{
		Vec2 pos{256.0f - index * 32.0f, 256.0f - index * 32.0f };

		obj.init();
		obj.setSceneTest(this);
		obj.setPos(pos);
		obj.setColor(GetColor(color,color,color));
		index++;
		color -= 16;
		if (color < 32)	color = 32;
	}
}

void SceneTest::end()
{
}

SceneBase* SceneTest::update()
{

	/*for (int i = (m_circle.size()) - 1;i >= 0;i--)
	{
		if(i < (m_circle.size()) - 1){
			if (m_circle[i + 1].getisCatch())break;
		}
		m_circle[i].update();
	}*/

	for (int i = 0; i < m_circle.size(); i++) {
		bool isCatchother = false;
		for (int j = 0; j < m_circle.size(); j++) {
			if (i == j)	continue;

			if (m_circle[j].getisCatch()) {
				isCatchother = true;
			}
		}

		if (!isCatchother) {
			m_circle[i].update();
		}
	}


	return this;
}

void SceneTest::draw()
{
	for (auto& obj : m_circle)
	{
		obj.draw();
	}
}

