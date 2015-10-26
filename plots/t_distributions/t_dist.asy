import root;
import pad_layout;

string topDir = "../../";

string datasets[] = { "DS1" };

string diagonals[] = { "45b_56t", "45t_56b" };
string diagLabels[] = { "45 bot -- 56 top", "45 top -- 56 bot" };


for (int dsi : datasets.keys)
{
	NewPad("$|t|\ung{GeV^2}$", "$\d\si/\d t\ung{a.~u.}$", 10cm, 8cm);
	scale(Linear, Log);

	for (int dgni : diagonals.keys)
	{
		pen p = StdPen(dgni + 1);
		draw(rGetObj(topDir+datasets[dsi]+"/distributions_"+diagonals[dgni]+".root", "acceptance correction/eb/h_t_after"),
			"d0,eb", p, diagLabels[dgni]);
	}

	limits((0, 1e1), (0.8, 1e7), Crop);
	AttachLegend(datasets[dsi]);
}
