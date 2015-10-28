import root;
import pad_layout;

string datasets[] = { "DS2", "DS3", "DS4", "DS4-b648", "DS4-b2990", "DS4-b26" };

string diagonals[] = { "45b_56t", "45t_56b" };

string RPs[] = { "L_F", "L_N", "R_N", "R_F" };
string RP_labels[] = { "left far", "left near", "right near", "right far" };

string topDir = "../../";


xSizeDef = 6cm;
ySizeDef = 5cm;
//yTicksDef = RightTicks(5., 1.);
//xTicks=LeftTicks(format="$$", 20., 10.)

int gx=0, gy=0;

TH2_palette = Gradient(blue, cyan, heavygreen, yellow, magenta, red);
TH2_palette.push(black);

//----------------------------------------------------------------------------------------------------

for (int dsi : datasets.keys)
{
	write("* " + datasets[dsi]);

	for (int dgi : diagonals.keys)
	{
		string f = topDir + datasets[dsi] + "/eff3outof4_details.root";
		real sgn = (diagonals[dgi] == "45b_56t") ? +1 : -1;
		string opt = "vl,eb";
		
		real y_min = 20;
		real y_max = 120;

		TH2_y_min = min(sgn*y_min, sgn*y_max);
		TH2_y_max = max(sgn*y_min, sgn*y_max);
		
		++gy; gx = 0;
		for (int rpi : RPs.keys)
		{
			++gx;
			NewPad(false, gx, gy);
			label(RP_labels[rpi]);
		}
		
		NewPad(false, -1, gy);
		label(replace("\vbox{\SetFontSizesXX\hbox{dataset: "+datasets[dsi]+"}\hbox{diagonal: "+diagonals[dgi]+"}}", "_", "\_"));

		++gy; gx = 0;
		NewPad(false, -1, gy);	
		label("{\SetFontSizesXII efficiency}");

		TH2_z_min = 0.95;
		TH2_z_max = 1;
		for (int rpi : RPs.keys)
		{
			string d = diagonals[dgi] + "/" + RPs[rpi];

			++gx;
			NewPad("$\th_x^*\ung{\mu rad}$", "$\th_y^*\ung{\mu rad}$", gx, gy, axesAbove=true);
			draw(scale(1., sgn), rGetObj(f, d+"/track/th_x, th_y : rel"), "def");

			limits((-300, 20), (300, 120), Crop);

			//yaxis(XEquals(-50, false), dashed, above=true);
			//yaxis(XEquals(+80, false), dashed, above=true);
		}
		
		++gy; gx = 0;
		NewPad(false, -1, gy);	
		label("{\SetFontSizesXII more than 1 track}");

		TH2_z_min = 0;
		TH2_z_max = 0.05;
		for (int rpi : RPs.keys) {
			string d = diagonals[dgi] + "/" + RPs[rpi];

			++gx;
			NewPad("$\th_x^*\ung{\mu rad}$", "$\th_y^*\ung{\mu rad}$", gx, gy);
			draw(scale(1., sgn), rGetObj(f, d+"/pl_suff_no_track/th_x, th_y : rel"), "def");

			limits((-300, 20), (300, 120), Crop);

			//yaxis(XEquals(-50, false), dashed, above=true);
			//yaxis(XEquals(+80, false), dashed, above=true);
		}
	}
}

GShipout(vSkip=0pt);
