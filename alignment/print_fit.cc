#include "TFile.h"
#include "TGraph.h"

#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
	// get input
	TFile *f_in = new TFile("../DS1/alignment_fit.root");

	// select units
	vector<string> units = {
		"L_2_F",
		"L_2_N",
		"L_1_F",
		"R_1_F",
		"R_2_N",
		"R_2_F"
	};
	
	vector<string> quantities = { "a", "b", "c" };

	// print results
	for (const auto &unit : units)
	{
		//printf(">> %s\n", unit.c_str());
		printf("\n");

		for (const auto &q : quantities)
		{
			TGraph *g1 = (TGraph *) f_in->Get((unit + "/" + q + "_fit").c_str());
			double t, v;
			g1->GetPoint(0, t, v);

			printf("%s_%s=\"%.1f\"\n", unit.c_str(), q.c_str(), v);
		}
	}

	delete f_in;	
}
