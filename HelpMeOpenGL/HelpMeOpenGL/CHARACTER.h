#pragma once
//==== ���� ====



class CHARACTER {
private:



protected:



public:
	//������ �� �ʱ�ȭ ��� ����Ʈ
	CHARACTER();
	~CHARACTER();

	void draw();
	void messege(unsigned char key);
	void update();
	void init();
	void reset();

	void draw_leg();
	void draw_body();



};