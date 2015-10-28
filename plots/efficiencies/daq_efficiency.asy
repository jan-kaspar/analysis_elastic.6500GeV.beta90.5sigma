import root;
import pad_layout;

// The datasets "DS4-b648", "DS4-b2990", "DS4-b26" would be misleading: the DAQ efficiency cannot be
// determined per bunch
string datasets[] = { "DS2", "DS3", "DS4" };

string diagonals[] = { "45b_56t", "45t_56b" };
string dgn_labels[] = { "45b -- 56t", "45t -- 56b" };

string topDir = "../../";


xSizeDef = 8cm;
ySizeDef = 6cm;

//----------------------------------------------------------------------------------------------------

for (int dsi : datasets.keys)
{
	NewPad(false);
	label(replace("\vbox{\SetFontSizesXX\hbox{dataset: "+datasets[dsi]+"}}", "_", "\_"));

	for (int dgi : diagonals.keys)
	{
		string f = topDir + datasets[dsi] + "/luminosity_"+diagonals[dgi]+".root";

		NewPad("recorded / triggered events");
		rObject obj = rGetObj(f, "h_daqEff");
		draw(obj, "vl,eb", StdPen(dgi+1), dgn_labels[dgi]);
		real m = obj.rExec("GetMean");
		real m_u = obj.rExec("GetRMS") / sqrt(obj.rExec("GetEntries"));
		yaxis(XEquals(m, false), dashed);
		AddToLegend(format("mean = $%#.3f$", m) + format("$\pm %#.3f$", m_u));
		AttachLegend(NW, NW);
	}

	NewRow();
}

GShipout(vSkip=0mm);
