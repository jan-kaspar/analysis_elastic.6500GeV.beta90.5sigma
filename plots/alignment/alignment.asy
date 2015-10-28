import root;
import pad_layout;
include "../run_info.asy";

string topDir = "../../";

string datasets[] = { "DS1" };

string units[] = { "L_2_F", "L_2_N", "L_1_F", "R_1_F", "R_2_N", "R_2_F" };
string unit_labels[] = { "left, 220, far", "left, 220, near", "left, 210, far", "right, 210, far", "right, 220, near", "right, 220, far" };

//string units[] = { "L_F", "L_N" };
//string unit_labels[] = { "Left Far", "Left Near" };

xSizeDef = 12cm;
xTicksDef = LeftTicks(Step=1, step=0.5);
drawGridDef = true;


TGraph_errorBar = None;

//----------------------------------------------------------------------------------------------------
NewRow();

for (int ui : units.keys)
{
	NewPad("time $\ung{h}$", "tilt $\ung{mrad}$", axesAbove=false);
	currentpad.yTicks = RightTicks(1., 0.2);
	DrawRunBands(-4, +4);

	for (int di : datasets.keys)
	{
		draw(swToHours, rGetObj(topDir+datasets[di]+"/alignment.root", "global/"+units[ui]+"/a_p"), "p,l,eb", cyan, mCi+1pt+cyan);
		draw(swToHours, rGetObj(topDir+datasets[di]+"/alignment.root", "global/"+units[ui]+"/a_g"), "p,l,eb", green, mCi+1pt+green);
		
		draw(swToHours, rGetObj(topDir+datasets[di]+"/alignment.root", "global/"+units[ui]+"/a"), "p,l,eb", blue, mCi+1pt+blue);
	}
	
	//draw(swToHours, rGetObj("../overall_alignment/alignment_fit.root", ""+units[ui]+"/a_fit"), "l", red+1.5pt);

	limits((time_min, -4), (time_max, +4), Crop);
	AttachLegend(unit_labels[ui], SE, SE);
}

//----------------------------------------------------------------------------------------------------
NewRow();

for (int ui : units.keys)
{
	NewPad("time $\ung{h}$", "horizontal position $\ung{\mu m}$", axesAbove=false);
	currentpad.yTicks = RightTicks(20., 10.);
	DrawRunBands(-100, +100);

	/*
	TGraph_reducePoints = 30;
	draw(unixToHours * shift(0, sh_x[ui]), rGetObj("bpm.root", "LHC.BOFSU:POSITIONS_H::"+bpms[ui]), black);
	TGraph_reducePoints = 1; 
	*/

	for (int di : datasets.keys)
	{
		draw(swToHours, rGetObj(topDir+datasets[di]+"/alignment.root", "global/"+units[ui]+"/b_p"), "p,l,eb", cyan, mCi+1pt+cyan);
		draw(swToHours, rGetObj(topDir+datasets[di]+"/alignment.root", "global/"+units[ui]+"/b_g"), "p,l,eb", green, mCi+1pt+green);

		draw(swToHours, rGetObj(topDir+datasets[di]+"/alignment.root", "global/"+units[ui]+"/b"), "p,l,eb", blue+1pt, mCi+1pt+blue);
	}
	
	//draw(shift(0, +50)*swToHours, rGetObj("../overall_alignment/alignment_fit.root", ""+units[ui]+"/b_fit"), "l", red+dashed);
	//draw(shift(0,   0)*swToHours, rGetObj("../overall_alignment/alignment_fit.root", ""+units[ui]+"/b_fit"), "l", red+1.5pt);
	//draw(shift(0, -50)*swToHours, rGetObj("../overall_alignment/alignment_fit.root", ""+units[ui]+"/b_fit"), "l", red+dashed);

	limits((time_min, -100), (time_max, +100), Crop);
	AttachLegend(unit_labels[ui], SE, SE);
}

//----------------------------------------------------------------------------------------------------
NewRow();

for (int ui : units.keys)
{
	NewPad("time $\ung{h}$", "vertical position $\ung{\mu m}$", axesAbove=false);
	currentpad.yTicks = RightTicks(100., 20.);
	DrawRunBands(-500, +500);

	/*
	TGraph_reducePoints = 30;
	draw(unixToHours*shift(0, sh_y[ui]), rGetObj("bpm.root", "LHC.BOFSU:POSITIONS_V::"+bpms[ui]), black);
	TGraph_reducePoints = 1;
	*/

	for (int di : datasets.keys)
	{
		pen p = StdPen(di+1);
		draw(swToHours, rGetObj(topDir+datasets[di]+"/alignment.root", "global/"+units[ui]+"/c_min_diff"), "p,l,eb", cyan, mCi+1pt+cyan);
		//draw(swToHours, rGetObj(topDir+datasets[di]+"/alignment.root", "global/"+units[ui]+"/c_prob"), "p,l,eb", green, mCi+1pt+green);
		draw(swToHours, rGetObj(topDir+datasets[di]+"/alignment.root", "global/"+units[ui]+"/c_mean_diff_sq"), "p,l,eb", magenta, mCi+1pt+magenta);
		draw(swToHours, rGetObj(topDir+datasets[di]+"/alignment.root", "global/"+units[ui]+"/c_hist_chi_sq"), "p,l,eb", green, mCi+1pt+green);
		
		draw(swToHours, rGetObj(topDir+datasets[di]+"/alignment.root", "global/"+units[ui]+"/c"), "p,l,eb", blue+1pt, mCi+1pt+blue);
	}
	
	/*
	draw(swToHours*shift(0, +100), rGetObj("../overall_alignment/alignment_fit.root", ""+units[ui]+"/c_fit"), "l", red+dashed);
	draw(swToHours*shift(0,    0), rGetObj("../overall_alignment/alignment_fit.root", ""+units[ui]+"/c_fit"), "l", red+1.5pt);
	draw(swToHours*shift(0, -100), rGetObj("../overall_alignment/alignment_fit.root", ""+units[ui]+"/c_fit"), "l", red+dashed);
	*/

	limits((time_min, -500), (time_max, +500), Crop);
	AttachLegend(unit_labels[ui], SE, SE);
}

//----------------------------------------------------------------------------------------------------

GShipout();
