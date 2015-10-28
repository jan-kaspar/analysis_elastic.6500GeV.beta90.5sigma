import root;
import pad_layout;
include "../run_info.asy";

string datasets[] = { "DS1" };

string topDir = "../../";

drawGridDef = true;

xTicksDef = LeftTicks(0.5, 0.1);

TGraph_errorBar = None;

//----------------------------------------------------------------------------------------------------

void DrawOne(real y_max)
{
	NewPad("time$\ung{h}$", "destructive pile-up probability", 12cm);
	DrawRunBands(0, y_max);
	layer();
	for (int di : datasets.keys)
	{
		currentpicture.legend.delete();
	
		draw(swToHours, rGetObj(topDir+datasets[di]+"/pileup_fit_combined.root", "45b_56t/dgn.src"), "p", blue, mTU+2pt+blue, "45 bot -- 56 top");
		draw(swToHours, rGetObj(topDir+datasets[di]+"/pileup_fit_combined.root", "45b_56t/dgn"), "l", blue+dashed);
		
		draw(swToHours, rGetObj(topDir+datasets[di]+"/pileup_fit_combined.root", "45t_56b/dgn.src"), "p", red, mTD+2pt+red, "45 top -- 56 bot");
		draw(swToHours, rGetObj(topDir+datasets[di]+"/pileup_fit_combined.root", "45t_56b/dgn"), "l", red+dashed);
	}
	
	AddToLegend("linear fit per run", black+dashed);
	limits((time_min, 0), (time_max, y_max), Crop);
	AttachLegend(NW, NE);
}

//----------------------------------------------------------------------------------------------------

DrawOne(0.10);

GShipout(vSkip=0mm);
