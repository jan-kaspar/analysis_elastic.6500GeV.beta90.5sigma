import root;
import pad_layout;

string datasets[] = { "DS2", "DS3", "DS4" };
string datasets[] = { "DS2", "DS4" };

string diagonals[] = { "45b_56t", "45t_56b" };

string RPs[] = { "L_F", "L_N", "R_N", "R_F" };
string RP_labels[] = { "left far", "left near", "right near", "right far" };

string topDir = "../../";

real old_const_eff_45b[] = { 0, 0, 0, 0 };
real old_const_eff_45t[] = { 0, 0, 0, 0 };

xSizeDef = 6cm;
ySizeDef = 5cm;
yTicksDef = RightTicks(5., 1.);

int gx=0, gy=0;

//----------------------------------------------------------------------------------------------------

for (int dsi : datasets.keys)
{
	if (datasets[dsi] == "DS2")
	{
		old_const_eff_45b = new real[] { 96.4, 98.7, 98.0, 96.4 };
		old_const_eff_45t = new real[] { 96.5, 98.5, 98.5, 96.3 };
	}

	if (datasets[dsi] == "DS4")
	{
		old_const_eff_45b = new real[] { 97.0, 98.8, 98.7, 97.5 };
		old_const_eff_45t = new real[] { 97.2, 98.7, 98.9, 97.5 };
	}

	for (int dgi : diagonals.keys)
	{
		string f = topDir + datasets[dsi] + "/eff3outof4_details_fit.root";
		real sgn = (diagonals[dgi] == "45b_56t") ? +1 : -1;
		string opt = "vl,eb";
		
		++gy; gx = 0;
		for (int rpi : RPs.keys)
		{
			++gx;
			NewPad(false, gx, gy);
			label(RP_labels[rpi]);
		}
		
		NewPad(false, -1, gy);
		label(replace("\vbox{\SetFontSizesXX\hbox{dataset: "+datasets[dsi]+"}\hbox{diagonal: "+diagonals[dgi]+"}}", "_", "\_"));

		frame fLegend;

		++gy; gx = 0;
		for (int rpi : RPs.keys)
		{
			string d = diagonals[dgi] + "/" + RPs[rpi];

			++gx;
			NewPad("$\th_y^*\ung{\mu rad}$", "\ung{\%}", gx, gy);
			currentpad.yTicks = RightTicks(1., 0.5);
			draw(scale(sgn, 100), rGetObj(f, d+"/th_y : rel"), opt, blue, "efficiency histogram");

			rObject fit = rGetObj(f, d+"/th_y : rel|ff");
			TF1_lowLimit = -inf; TF1_highLimit = +inf;
			draw(scale(sgn, 100), fit, red+2pt, "linear fit");
			TF1_lowLimit = -100; TF1_highLimit = 100;
			draw(scale(sgn, 100), fit, red+dashed);

			real old_const_eff = 0;
			if (diagonals[dgi] == "45b_56t")
				old_const_eff = old_const_eff_45b[rpi];
			else 
				old_const_eff = old_const_eff_45t[rpi];

			draw((0, old_const_eff)--(100, old_const_eff), heavygreen+2pt, "old constant fit");

			real y = 97;
			if (rpi == 0 || rpi == 3)
				y = 99;

			string slope_label = format("slope = ($%#.1f$", fit.rExec("GetParameter", 1)*1e6)
				+ format("$\pm %#.1f) \un{rad^{-1}}$", fit.rExec("GetParError", 1)*1e6);

			label(slope_label, (60, y), red);

			limits((10, 95), (110, 100), Crop);
			fLegend = BuildLegend();
		}

		if (dgi == 0)
		{
			++gx;
			NewPad(false, gx, gy);
			add(fLegend);
		}
	}
}

GShipout(vSkip=0pt);
