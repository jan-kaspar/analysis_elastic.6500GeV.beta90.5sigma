import root;
import pad_layout;
include "../run_info.asy";

string topDir = "../../";

TH2_palette = Gradient(blue, heavygreen, yellow, red);

int rebin = 20;

string datasets[] = {
	"DS1",
	"DS1-new-ntuples",
};

string dgns[] = { "45b_56t", "45t_56b" };
string dgn_labs[] = { "45 bot -- 56 top", "45 top -- 56 bot" };

xSizeDef = 20cm;
xTicksDef = LeftTicks(Step=1, step=0.5);

//----------------------------------------------------------------------------------------------------

for (int dgni : dgns.keys)
{
	NewRow();

	//NewPad(false);
	//label("{\SetFontSizesXX " + datasets[dsi] + "}");
	
	NewPad("time$\ung{s}$", "rate$\ung{Hz}$");
	DrawRunBands(0, +20);

	for (int dsi : datasets.keys)
	{
		pen p = StdPen(dsi + 1);
		if (dsi > 0)
			p += dashed;

		RootObject obj = RootGetObject(topDir+datasets[dsi]+"/distributions_"+dgns[dgni]+".root", "metadata/h_timestamp_dgn");
		obj.vExec("Rebin", rebin);
		draw(scale(1, 1./rebin)*swToHours, obj, "vl", p, datasets[dsi]);

		//limits((23, 0), (32.5, +20), Crop);
		//layer();
	}
	
	AttachLegend(dgn_labs[dgni], NW, NE);
}
