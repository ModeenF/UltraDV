// test class to determine mangled new operator symbol

class test {
public:
	~test();
	test();
	test(int, float);
	void testprint();

private:
	int a;
	float b;
	bool c;
};

