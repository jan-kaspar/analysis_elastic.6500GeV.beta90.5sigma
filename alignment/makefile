all: test_linearity print_fit

test_linearity: test_linearity.cc
	g++ `root-config --libs` -lMinuit `root-config --cflags` --std=c++11 test_linearity.cc -o test_linearity

print_fit: print_fit.cc
	g++ `root-config --libs` -lMinuit `root-config --cflags` --std=c++11 print_fit.cc -o print_fit
