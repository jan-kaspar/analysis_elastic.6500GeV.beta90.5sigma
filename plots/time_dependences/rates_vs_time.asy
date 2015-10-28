import root;
import pad_layout;
include "../run_info.asy";

string topDir = "../../";

TH2_palette = Gradient(blue, heavygreen, yellow, red);

int rebin = 50;

string datasets[] = { "DS2a", "DS2b"};

string dgns[] = { "45b_56t", "45t_56b" };
string dgn_labs[] = { "far dgn", "close dgn" };

xSizeDef = 12cm;
xTicksDef = LeftTicks(Step=1, step=0.5);

//----------------------------------------------------------------------------------------------------

for (int dgni : dgns.keys)
{
	NewPad("time$\ung{s}$", "rate$\ung{Hz}$");
	DrawRunBoundaries(0, +20);
	for (int di : datasets.keys)
	{
		rObject obj = rGetObj(topDir+datasets[di]+"/distributions_"+dgns[dgni]+".root", "metadata/h_timestamp_dgn");
		obj.vExec("Rebin", rebin);
		draw(scale(1, 1./rebin)*swToHours, obj, black);
	
		rObject obj = rGetObj(topDir+datasets[di]+"/distributions_"+dgns[dgni]+".root", "metadata/h_timestamp_sel");
		obj.vExec("Rebin", rebin);
		draw(scale(1, 1./rebin)*swToHours, obj, red);
	}

	limits((23, 0), (32.5, +20), Crop);
	layer();
	AttachLegend(dgn_labs[dgni]);
}
