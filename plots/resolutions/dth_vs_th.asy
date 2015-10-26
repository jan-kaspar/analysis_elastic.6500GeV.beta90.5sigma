import root;
import pad_layout;
include "../run_info.asy";

string datasets[] = { "DS2", "DS3", "DS4", "DS4-b648", "DS4-b2990", "DS4-b26" };

string diagonals[] = { "45b_56t", "45t_56b" };
string dgn_labels[] = { "45b -- 56t", "45t -- 56b" };
pen dgn_pens[] = { blue, red };

string topDir = "../../";

xSizeDef = 10cm;
ySizeDef = 6cm;

TGraph_errorBar = None;

//----------------------------------------------------------------------------------------------------

for (int dsi : datasets.keys)
{
	NewPad("$\th_x^*\ung{\mu rad}$", "std.~dev.~of~$\De^{R-L} \th_x^*\ung{\mu rad}$", yTicks=RightTicks(0.2, 0.1));
	for (int dgni : diagonals.keys)
	{
		string f = topDir+datasets[dsi]+"/distributions_"+diagonals[dgni]+".root";
		pen p = StdPen(dgni+1);
		draw(scale(1e6, 1e6), rGetObj(f, "selected - angles/th_x_sigmaLR_vs_th_x"), "p", p, mCi+1pt+p, dgn_labels[dgni]);
	}
	limits((-200, 8), (+200, 10), Crop);
	for (real y = 8; y <= 10; y += 0.2)
		xaxis(YEquals(y, false), dotted);
	AttachLegend(datasets[dsi]);

	NewPad("$\th_y^*\ung{\mu rad}$", "std.~dev.~of~$\De^{R-L} \th_y^*\ung{\mu rad}$", yTicks=RightTicks(0.2, 0.1));
	for (int dgni : diagonals.keys)
	{
		string f = topDir+datasets[dsi]+"/distributions_"+diagonals[dgni]+".root";
		pen p = StdPen(dgni+1);
		draw(scale(1e6, 1e6), rGetObj(f, "selected - angles/th_y_sigmaLR_vs_th_y"), "p", p, mCi+1pt+p, dgn_labels[dgni]);
	}
	limits((-100, 2), (+100, 4), Crop);
	for (real y = 2; y <= 4; y += 0.2)
		xaxis(YEquals(y, false), dotted);
	AttachLegend(datasets[dsi]);

	NewRow();
}
