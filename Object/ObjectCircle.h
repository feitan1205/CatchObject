#pragma once

#include "ObjectBase.h"

class SceneTest;

class ObjectCircle : public ObjectBase
{
public:
	ObjectCircle();
	virtual ~ObjectCircle();

	virtual void init() override;
	virtual void end() override;

	virtual void update() override;
	virtual void draw() override;

	void setSceneTest(SceneTest* pSceneTest) { m_pSceneTest = pSceneTest; }

	// �\���ʒu�̐ݒ�
	void setPos(Vec2 pos) { m_pos = pos; }
	// �\���F�̐ݒ�
	void setColor(int color) { m_color = color; }

	//���߂邩�ǂ���
	bool isCatchEnable(Vec2 pos);

	bool getisCatch() { return m_isCatch; }

private:
	SceneTest* m_pSceneTest;
	// �\�����
	int		m_color;

	bool m_isCatch;			//���񂾂��ǂ����t���O
	Vec2 m_catchOffset;		//���񂾈ꂩ�璆�S�ւ̃x�N�g��
};