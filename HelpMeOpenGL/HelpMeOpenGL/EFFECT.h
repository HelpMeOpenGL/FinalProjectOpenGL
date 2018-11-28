#pragma once
class EFFECT
{
private:
	int TimeLine = 0;

protected:


public:
	EFFECT();
	~EFFECT();
	void draw();
	void messege(unsigned char key);
	void update();
	void init();
	void reset();
};

