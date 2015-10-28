import root;
import pad_layout;
include "../run_info.asy";

string datasets[] = { "DS1" };

string diagonals[] = { "45b_56t", "45t_56b" };
string dgn_labels[] = { "45b -- 56t", "45t -- 56b" };
pen dgn_pens[] = { blue, red };

string topDir = "../../";

xSizeDef = 10cm;
ySizeDef = 6cm;

xTicksDef = LeftTicks(1., 0.2);

drawGridDef = true;

TGraph_errorBar = None;


//----------------------------------------------------------------------------------------------------

void DrawBeamDivergence(rObject g_vtx_rms, pen p, marker m, string label)
{
	int N = g_vtx_rms.iExec("GetN");
	for (int i = 0; i < N; ++i)
	{
		real xa[] = { 0 };
		real ya[] = { 0 };
		g_vtx_rms.vExec("GetPoint", i, xa, ya);
		real time = xa[0];
		real vtx_rms = ya[0] / 1e3;	// in m

		real bd = sqrt(2) * vtx_rms / 90;

		if (bd != 0)
			draw(swToHours*scale(1, 1e6)*(time, bd), p, m);
	}
}

//----------------------------------------------------------------------------------------------------

void DrawReconstructionResolution(rObject g_vtx_rms, rObject g_diffRL_th_x, pen p, marker m, string label)
{
	int N = g_vtx_rms.iExec("GetN");
	for (int i = 0; i < N; ++i)
	{
		real xa[] = { 0 };
		real ya[] = { 0 };
		g_vtx_rms.vExec("GetPoint", i, xa, ya);
		real time = xa[0];
		real vtx_rms = ya[0] / 1e3;	// in m
		
		g_diffRL_th_x.vExec("GetPoint", i, xa, ya);
		real diffRL_th_x_rms = ya[0];

		real bd = sqrt(2) * vtx_rms / 90;
		real rr = sqrt(diffRL_th_x_rms*diffRL_th_x_rms/2 - bd*bd);

		//write(time);

		if (bd != 0)
			draw(swToHours*scale(1, 1e6)*(time, rr), p, m);
	}
}

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

NewPad("time $\ung{h}$", "std.~dev.~of $\De^{R-L}\th_x^*\ung{\mu rad}$");
DrawRunBands(8, +10);
for (int dsi : datasets.keys)
{
	for (int dgni : diagonals.keys)
	{
		draw(swToHours*scale(1, 1e6),
			rGetObj(topDir+datasets[dsi]+"/distributions_"+diagonals[dgni]+".root", "time dependences/gRMS_diffLR_th_x_vs_time"), "p,eb,d0",
			dgn_pens[dgni], mCi+1.5pt+dgn_pens[dgni], dgn_labels[dgni]);

		/*
		rObject fit = rGetObj(topDir+"resolutions/fit_"+datasets[dsi]+".root", diagonals[dgni]+"/x/g_fit");
		draw(shift(0, +0.2)*swToHours*scale(1, 1e6), fit, "l", black+dashed);
		draw(shift(0,  0.0)*swToHours*scale(1, 1e6), fit, "l", black+1.5pt);
		draw(shift(0, -0.2)*swToHours*scale(1, 1e6), fit, "l", black+dashed);
		*/
	}
}
limits((time_min, 8), (time_max, 10), Crop);

//--------------------

NewPad("time $\ung{h}$", "\vbox{\hbox{sensor contribution to resolution $\ung{\mu m}$}\hbox{$\sqrt{\si[\De^{R-L}\th_x^*]^2/2 - \si_{\rm beam\ div.}^2}$}}");
currentpad.yTicks = RightTicks(0.5, 0.1);
DrawRunBands(5, 7);
for (int dsi : datasets.keys)
{
	for (int dgni : diagonals.keys)
	{
		rObject obj_vtx_x = rGetObj(topDir+datasets[dsi]+"/distributions_"+diagonals[dgni]+".root", "time dependences/gRMS_vtx_x_vs_time");
		rObject obj_diffRL_vtx_x = rGetObj(topDir+datasets[dsi]+"/distributions_"+diagonals[dgni]+".root", "time dependences/gRMS_diffLR_th_x_vs_time");

		DrawReconstructionResolution(obj_vtx_x, obj_diffRL_vtx_x, dgn_pens[dgni], mCi+1.5pt+dgn_pens[dgni], dgn_labels[dgni]);
	}
}

limits((time_min, 5), (time_max, 7), Crop);

//----------------------------------------------------------------------------------------------------
NewRow();

NewPad("time $\ung{h}$", "std.~dev.~of $\De^{R-L}\th_y^*\ung{\mu rad}$");
DrawRunBands(2.2, 3.0);
for (int dsi : datasets.keys)
{
	currentpicture.legend.delete();

	for (int dgni : diagonals.keys)
	{
		draw(swToHours*scale(1, 1e6),
			rGetObj(topDir+datasets[dsi]+"/distributions_"+diagonals[dgni]+".root", "time dependences/gRMS_diffLR_th_y_vs_time"), "p,eb,d0",
			dgn_pens[dgni], mCi+1.5pt+dgn_pens[dgni], dgn_labels[dgni]);

		/*
		rObject fit = rGetObj(topDir+"resolutions/fit_"+datasets[dsi]+".root", diagonals[dgni]+"/y/g_fit");
		draw(shift(0, +0.05)*swToHours*scale(1, 1e6), fit, "l", black+dashed);
		draw(shift(0,  0.00)*swToHours*scale(1, 1e6), fit, "l", black+1.5pt);
		draw(shift(0, -0.05)*swToHours*scale(1, 1e6), fit, "l", black+dashed);
		*/
	}
}
limits((time_min, 2.2), (time_max, 3), Crop);

frame f_leg = BuildLegend();

NewPad(false);
attach(f_leg);

//----------------------------------------------------------------------------------------------------
NewRow();

NewPad("time $\ung{h}$", "std.~dev.~of $x^*\ung{\mu m}$");
DrawRunBands(100, 150);
for (int dsi : datasets.keys)
{
	for (int dgni : diagonals.keys)
		draw(swToHours*scale(1, 1e3),
			rGetObj(topDir+datasets[dsi]+"/distributions_"+diagonals[dgni]+".root", "time dependences/gRMS_vtx_x_vs_time"), "p,eb,d0",
			dgn_pens[dgni], mCi+1.5pt+dgn_pens[dgni], dgn_labels[dgni]);
}
limits((time_min, 100), (time_max, 150), Crop);

//--------------------

NewPad("time $\ung{h}$", "\vbox{\hbox{beam divergence in x $\ung{\mu m}$}\hbox{$\displaystyle\sqrt 2 \,\si[x^*]\over \be^*$}}");
currentpad.yTicks = RightTicks(0.1, 0.02);
DrawRunBands(1.0, 3.0);
for (int dsi : datasets.keys)
{
	for (int dgni : diagonals.keys)
	{
		rObject obj_vtx_x = rGetObj(topDir+datasets[dsi]+"/distributions_"+diagonals[dgni]+".root", "time dependences/gRMS_vtx_x_vs_time");
		rObject obj_diffRL_vtx_x = rGetObj(topDir+datasets[dsi]+"/distributions_"+diagonals[dgni]+".root", "time dependences/gRMS_diffLR_th_x_vs_time");

		DrawBeamDivergence(obj_vtx_x, dgn_pens[dgni], mCi+1.5pt+dgn_pens[dgni], dgn_labels[dgni]);
	}
}

limits((time_min, 1.7), (time_max, 2.2), Crop);

GShipout(vSkip=0mm);
