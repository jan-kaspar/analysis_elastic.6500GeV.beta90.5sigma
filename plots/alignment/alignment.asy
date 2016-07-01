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

for (int ui : units.keys)
{
	NewPad(false);
	label("{\SetFontSizesXX " + unit_labels[ui] + "}");
}


//----------------------------------------------------------------------------------------------------
NewRow();

for (int ui : units.keys)
{
	NewPad("time $\ung{h}$", "tilt $\ung{mrad}$", axesAbove=false);
	currentpad.yTicks = RightTicks(1., 0.2);
	DrawRunBands(-2, +2);

	for (int di : datasets.keys)
	{
		draw(swToHours, RootGetObject(topDir+datasets[di]+"/alignment.root", "global/"+units[ui]+"/a_p"), "p,l,eb", cyan, mCi+1pt+cyan);
		draw(swToHours, RootGetObject(topDir+datasets[di]+"/alignment.root", "global/"+units[ui]+"/a_g"), "p,l,eb", green, mCi+1pt+green);
		
		draw(swToHours, RootGetObject(topDir+datasets[di]+"/alignment.root", "global/"+units[ui]+"/a"), "p,l,eb", blue, mCi+1pt+blue);
	
		draw(swToHours, RootGetObject(topDir+datasets[di]+"/alignment_fit.root", ""+units[ui]+"/a_fit"), "l", red+1.5pt);
	}

	limits((time_min, -2), (time_max, +2), Crop);
	AttachLegend(unit_labels[ui], SE, SE);
}

//----------------------------------------------------------------------------------------------------
NewRow();

for (int ui : units.keys)
{
	NewPad("time $\ung{h}$", "horizontal position $\ung{\mu m}$", axesAbove=false);
	currentpad.yTicks = RightTicks(10., 2.);
	DrawRunBands(-40, +40);

	/*
	TGraph_reducePoints = 30;
	draw(unixToHours * shift(0, sh_x[ui]), RootGetObject("bpm.root", "LHC.BOFSU:POSITIONS_H::"+bpms[ui]), black);
	TGraph_reducePoints = 1; 
	*/

	for (int di : datasets.keys)
	{
		draw(swToHours, RootGetObject(topDir+datasets[di]+"/alignment.root", "global/"+units[ui]+"/b_p"), "p,l,eb", cyan, mCi+1pt+cyan);
		draw(swToHours, RootGetObject(topDir+datasets[di]+"/alignment.root", "global/"+units[ui]+"/b_g"), "p,l,eb", green, mCi+1pt+green);

		draw(swToHours, RootGetObject(topDir+datasets[di]+"/alignment.root", "global/"+units[ui]+"/b"), "p,l,eb", blue+1pt, mCi+1pt+blue);
	
		draw(shift(0,   0)*swToHours, RootGetObject(topDir+datasets[di]+"/alignment_fit.root", ""+units[ui]+"/b_fit"), "l", red+1.5pt);
	}
	
	//draw(shift(0, +50)*swToHours, RootGetObject("../overall_alignment/alignment_fit.root", ""+units[ui]+"/b_fit"), "l", red+dashed);
	//draw(shift(0,   0)*swToHours, RootGetObject("../overall_alignment/alignment_fit.root", ""+units[ui]+"/b_fit"), "l", red+1.5pt);
	//draw(shift(0, -50)*swToHours, RootGetObject("../overall_alignment/alignment_fit.root", ""+units[ui]+"/b_fit"), "l", red+dashed);

	limits((time_min, -40), (time_max, +40), Crop);
	AttachLegend(unit_labels[ui], SE, SE);
}

//----------------------------------------------------------------------------------------------------
NewRow();

for (int ui : units.keys)
{
	NewPad("time $\ung{h}$", "vertical position $\ung{\mu m}$", axesAbove=false);
	currentpad.yTicks = RightTicks(100., 20.);
	DrawRunBands(-400, +400);

	/*
	TGraph_reducePoints = 30;
	draw(unixToHours*shift(0, sh_y[ui]), RootGetObject("bpm.root", "LHC.BOFSU:POSITIONS_V::"+bpms[ui]), black);
	TGraph_reducePoints = 1;
	*/

	for (int di : datasets.keys)
	{
		pen p = StdPen(di+1);
		draw(swToHours, RootGetObject(topDir+datasets[di]+"/alignment.root", "global/"+units[ui]+"/c_min_diff"), "p,l,eb", cyan, mCi+1pt+cyan);
		//draw(swToHours, RootGetObject(topDir+datasets[di]+"/alignment.root", "global/"+units[ui]+"/c_prob"), "p,l,eb", green, mCi+1pt+green);
		draw(swToHours, RootGetObject(topDir+datasets[di]+"/alignment.root", "global/"+units[ui]+"/c_mean_diff_sq"), "p,l,eb", magenta, mCi+1pt+magenta);
		draw(swToHours, RootGetObject(topDir+datasets[di]+"/alignment.root", "global/"+units[ui]+"/c_hist_chi_sq"), "p,l,eb", green, mCi+1pt+green);
		
		draw(swToHours, RootGetObject(topDir+datasets[di]+"/alignment.root", "global/"+units[ui]+"/c"), "p,l,eb", blue+1pt, mCi+1pt+blue);
	
		draw(swToHours*shift(0,    0), RootGetObject(topDir+datasets[di]+"/alignment_fit.root", ""+units[ui]+"/c_fit"), "l", red+1.5pt);
	}
	
	/*
	draw(swToHours*shift(0, +100), RootGetObject("../overall_alignment/alignment_fit.root", ""+units[ui]+"/c_fit"), "l", red+dashed);
	draw(swToHours*shift(0,    0), RootGetObject("../overall_alignment/alignment_fit.root", ""+units[ui]+"/c_fit"), "l", red+1.5pt);
	draw(swToHours*shift(0, -100), RootGetObject("../overall_alignment/alignment_fit.root", ""+units[ui]+"/c_fit"), "l", red+dashed);
	*/

	limits((time_min, -400), (time_max, +400), Crop);
	AttachLegend(unit_labels[ui], SE, SE);
}

//----------------------------------------------------------------------------------------------------

GShipout();
