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

	// 
	vector<string> quantities = { "a", "b", "c" };

	struct StationInfo
	{
		double z1;
		string label1;
		double z2;
		string label2;
		double z_i;
		string label_i;
	};

	map<unsigned int, StationInfo> geom;
	geom[0] = { -213.0, "L_1_F", -220.0, "L_2_F", -214.628, "L_2_N" };
	geom[1] = { +213.0, "R_1_F", +220.0, "R_2_F", +214.628, "R_2_N" };

	for (const auto &p : geom)
	{
		printf(">> station %u\n", p.first);
		
		const StationInfo &stInfo = p.second;

		for (const auto &q : quantities)
		{
			printf("    %s\n", q.c_str());

			TGraph *g1 = (TGraph *) f_in->Get((stInfo.label1 + "/" + q + "_fit").c_str());
			double v1, dummy;
			g1->GetPoint(0, dummy, v1);

			TGraph *g2 = (TGraph *) f_in->Get((stInfo.label2 + "/" + q + "_fit").c_str());
			double v2;
			g2->GetPoint(0, dummy, v2);

			TGraph *g = (TGraph *) f_in->Get((stInfo.label_i + "/" + q + "_fit").c_str());
			double v_det;
			g->GetPoint(0, dummy, v_det);

			const double &z1 = stInfo.z1;
			const double &z2 = stInfo.z2;
			const double &z_i = stInfo.z_i;

			printf("        210_F: z = %.3f m, %.1f\n", z1, v1);
			printf("        220_F: z = %.3f m, %.1f\n", z2, v2);

			double slope = (v2 - v1) / (z2 - z1);
			double inter = v1 - slope * z1;

			double v_i = slope * z_i + inter;

			printf("        220_N: z = %.3f m, determined = %.1f, interpolated = %.1f\n", z_i, v_det, v_i);
		}
	}

	delete f_in;	
}
