#ifndef HEADER_H
#define HEADER_H

class linear_ur
{
private:
	float y;
	float x;
	float B;
	float A;
public:
	bool r;
	void init();
	void read();
	bool isFloat(const std::string& input);
	void show();
	void function(float x_X);
};

#endif