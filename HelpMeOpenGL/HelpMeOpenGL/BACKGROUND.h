#pragma once
//�����
class BACKGROUND {
private :
	int TimeLine = 0;


protected:



public:
	//������ �� �ʱ�ȭ ��� ����Ʈ
	BACKGROUND();
	~BACKGROUND();

	void draw();
	void messege(unsigned char key);
	void update();
	void init();
	void reset();


};