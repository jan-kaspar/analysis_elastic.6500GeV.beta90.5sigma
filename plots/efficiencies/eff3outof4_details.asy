import root;
import pad_layout;

string datasets[] = { "DS2", "DS3", "DS4", "DS4-b648", "DS4-b2990", "DS4-b26" };

string diagonals[] = { "45b_56t", "45t_56b" };

string RPs[] = { "L_F", "L_N", "R_N", "R_F" };
string RP_labels[] = { "left far", "left near", "right near", "right far" };

string topDir = "../../";


xSizeDef = 6cm;
ySizeDef = 5cm;
yTicksDef = RightTicks(5., 1.);

int gx=0, gy=0;

//----------------------------------------------------------------------------------------------------

for (int dsi : datasets.keys)
{
	for (int dgi : diagonals.keys)
	{
		string f = topDir + datasets[dsi] + "/eff3outof4_details.root";
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
			NewPad("", "\ung{\%}", xTicks=LeftTicks(format="$$", 20., 10.), gx, gy);
			draw(scale(sgn, 100), rGetObj(f, d+"/anything/th_y : rel"), opt, black);
			draw(scale(sgn, 100), rGetObj(f, d+"/track/th_y : rel"), opt, cyan, "track");
			draw(scale(sgn, 100), rGetObj(f, d+"/track_compatible/th_y : rel"), opt, magenta, "compatible track");

			limits((10, 90), (110, 100), Crop);
			fLegend = BuildLegend();
		}

		NewPad(false, -1, gy);
		attach(fLegend);
		
		++gy; gx = 0;
		for (int rpi : RPs.keys) {
			string d = diagonals[dgi] + "/" + RPs[rpi];
			
			++gx;
			NewPad("$\th_y^*\ung{\mu rad}$", "\ung{\%}", gx, gy);
			draw(scale(sgn, 100), rGetObj(f, d+"/pl_insuff/th_y : rel", error=false), opt, red, "insufficient active planes");
			draw(scale(sgn, 100), rGetObj(f, d+"/pl_suff_no_track/th_y : rel"), opt, blue, "sufficient active planes but no track");
			draw(scale(sgn, 100), rGetObj(f, d+"/pat_more/th_y : rel"), opt, heavygreen, "more than one pattern recognized");

			limits((10, 0), (110, 10), Crop);
			fLegend = BuildLegend();
		}

		NewPad(false, -1, gy);
		attach(fLegend);
	}
}

GShipout(vSkip=0pt);
