all: test_linearity

test_linearity: test_linearity.cc
	g++ `root-config --libs` -lMinuit `root-config --cflags` --std=c++11 test_linearity.cc -o test_linearity
