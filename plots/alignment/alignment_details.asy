import root;
import pad_layout;
include "../run_info.asy";

string topDir = "../../";

string dataset = "DS1";

string units[] = { "L_2_F", "L_2_N", "L_1_F", "R_1_F", "R_2_N", "R_2_F" };
string unit_labels[] = { "left, 220, far", "left, 220, near", "left, 210, far", "right, 210, far", "right, 220, near", "right, 220, far" };

//string units[] = { "L_2_F", "L_2_N" };
//string unit_labels[] = { "Left Far", "Left Near" };

xSizeDef = 10cm;
drawGridDef = true;

TGraph_errorBar = None;

//string period = "period 2";
string period = "period 5";

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
	NewPad("$y\ung{mm}$", "$\hbox{mean } x\ung{mm}$");

	draw(RootGetObject(topDir+dataset+"/alignment.root", period + "/unit "+units[ui]+"/horizontal/horizontal profile/p"), "d0,eb", blue);
	draw(RootGetObject(topDir+dataset+"/alignment.root", period + "/unit "+units[ui]+"/horizontal/horizontal profile/p|ff"), "l", red+1pt);
	
	limits((-30, -0.2), (+30, +0.2), Crop);
	AttachLegend(unit_labels[ui], NE, NE);
}

//----------------------------------------------------------------------------------------------------
NewRow();

for (int ui : units.keys)
{
	NewPad("$y\ung{mm}$", "");
	scale(Linear, Log);

	draw(RootGetObject(topDir+dataset+"/alignment.root", period + "/unit "+units[ui]+"/vertical/y_hist|y_hist"), "d0,vl", blue);
	draw(RootGetObject(topDir+dataset+"/alignment.root", period + "/unit "+units[ui]+"/vertical/y_hist|y_hist_range"), "d0,vl", red);

	limits((-30, 1), (+30, 2e3), Crop);
	AttachLegend(unit_labels[ui], NE, NE);
}


//----------------------------------------------------------------------------------------------------
NewRow();

for (int ui : units.keys)
{
	NewPad("$\de y\ung{mm}$", "");

	draw(RootGetObject(topDir+dataset+"/alignment.root", period + "/unit "+units[ui]+"/vertical/g_max_diff"), "l,p", heavygreen, mCi+1pt+heavygreen);

	limits((-1, 0), (+1, 0.4), Crop);
	AttachLegend(unit_labels[ui], NE, NE);
}
