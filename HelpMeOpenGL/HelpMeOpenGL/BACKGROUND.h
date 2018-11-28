#pragma once
//선언부
class BACKGROUND {
private :
	int TimeLine = 0;


protected:



public:
	//생성자 및 초기화 목록 리스트
	BACKGROUND();
	~BACKGROUND();

	void draw();
	void messege(unsigned char key);
	void update();
	void init();
	void reset();


};