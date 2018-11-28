#pragma once
//==== 설명 ====



class CHARACTER {
private:



protected:



public:
	//생성자 및 초기화 목록 리스트
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