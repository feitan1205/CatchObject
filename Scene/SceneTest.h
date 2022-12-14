#pragma once
#include "SceneBase.h"
#include <vector>
#include "ObjectCircle.h"

class SceneTest : public SceneBase
{
public:
	SceneTest();
	virtual ~SceneTest() {}


	virtual void init() override;
	virtual void end() override;

	virtual SceneBase* update() override;
	virtual void draw() override;

private:

	std::vector<ObjectCircle> m_circle;

	//bool m_isCatch;

};