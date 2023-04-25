#ifndef TURINGTAPE_H_
#define TURINGTAPE_H_
class TuringTape {
public:
	TuringTape(int n);
	bool moveRight();
	bool moveLeft();
	int getContent();
	void setContent(int c);
	int getPosition();
	friend std::ostream& operator<<(std::ostream& out,const TuringTape& s);

};

#endif /* TURINGTAPE_H_ */
