#include "input_files.h"

#include "common_definitions.h"
#include "common_algorithms.h"
#include "parameters.h"
#include "common.h"

#include "TFile.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TChain.h"
#include "TH1D.h"
#include "TF1.h"

#include <vector>
#include <map>
#include <string>
#include <cmath>

#include "TotemAnalysis/TotemNtuplizer/interface/TriggerDataFormats.h"
#include "TotemAnalysis/TotemNtuplizer/interface/RawDataFormats.h"
#include "TotemAnalysis/TotemNtuplizer/interface/RPRootTrackInfo.h"

using namespace std;

//----------------------------------------------------------------------------------------------------

struct RPStruct
{
	RPRootDumpDigiInfo *digi;
	RPRootDumpPatternInfo *pat;
	RPRootDumpTrackInfo *tr;
	vector<RPRootDumpTrackInfo> *mtr;

	void AssignBranches(TChain *ch, unsigned int id)
	{
		char buf[100];

		digi = new RPRootDumpDigiInfo;
		sprintf(buf, "digi_rp_%u.*", id); ch->SetBranchStatus(buf, 1);
		sprintf(buf, "digi_rp_%u.", id); ch->SetBranchAddress(buf, &digi);

		pat = new RPRootDumpPatternInfo();
		sprintf(buf, "nonpar_patterns_rp_%u.*", id); ch->SetBranchStatus(buf, 1);
		sprintf(buf, "nonpar_patterns_rp_%u.", id); ch->SetBranchAddress(buf, &pat);

		tr = new RPRootDumpTrackInfo();
		sprintf(buf, "track_rp_%u.*", id); ch->SetBranchStatus(buf, 1);
		sprintf(buf, "track_rp_%u.", id); ch->SetBranchAddress(buf, &tr);

		mtr = new vector<RPRootDumpTrackInfo>();
		sprintf(buf, "multi_track_rp_%u.*", id); ch->SetBranchStatus(buf, 1);
		sprintf(buf, "multi_track_rp_%u", id); ch->SetBranchAddress(buf, &mtr);

	}
};

//----------------------------------------------------------------------------------------------------

struct DiagStruct
{
	RPStruct L_F, L_N, R_N, R_F;

	void AssignBranches(TChain *ch, unsigned int lf, unsigned int ln, unsigned int rn, unsigned int rf)
	{
		L_F.AssignBranches(ch, lf);
		L_N.AssignBranches(ch, ln);
		R_N.AssignBranches(ch, rn);
		R_F.AssignBranches(ch, rf);
	}
};

//----------------------------------------------------------------------------------------------------

// map: element set, condition, period -> count 
typedef map<string, map<string, map<unsigned int, unsigned long> > > CounterMap;

//----------------------------------------------------------------------------------------------------

int maxHitsPerPlaneToSearch;
int minPlanesPerProjectionToSearch;

bool RPTooFullU(const RPStruct &rp)
{
	int N_too_full = 0;
	for (unsigned int i = 1; i < 10; i += 2)
		if (rp.digi->numberOfClusters[i] > maxHitsPerPlaneToSearch)
			N_too_full++;

	return (N_too_full > minPlanesPerProjectionToSearch);
}

//----------------------------------------------------------------------------------------------------

bool RPTooFullV(const RPStruct &rp)
{
	int N_too_full = 0;
	for (unsigned int i = 0; i < 10; i += 2)
		if (rp.digi->numberOfClusters[i] > maxHitsPerPlaneToSearch)
			N_too_full++;

	return (N_too_full > minPlanesPerProjectionToSearch);
}

//----------------------------------------------------------------------------------------------------

void AnalyzeDiagonal(const DiagStruct &dgn, CounterMap &c, unsigned int period)
{
	bool L_N_pl_suff = (dgn.L_N.digi->uPlanesOn >= 3 && dgn.L_N.digi->vPlanesOn >= 3);
	bool L_N_pl_too_full_u = RPTooFullU(dgn.L_N), L_N_pl_too_full_v = RPTooFullV(dgn.L_N);
	bool L_N_pat_suff = (dgn.L_N.pat->u.size() > 0 || dgn.L_N.pat->v.size() > 0) || (L_N_pl_too_full_u || L_N_pl_too_full_v);
	bool L_N_pat_more = (dgn.L_N.pat->u.size() > 1 && dgn.L_N.pat->v.size() > 1) || (L_N_pl_too_full_u || L_N_pl_too_full_v);
	bool L_N_tr_any = (dgn.L_N.tr->valid || dgn.L_N.mtr->size() > 0);
	
	bool L_F_pl_suff = (dgn.L_F.digi->uPlanesOn >= 3 && dgn.L_F.digi->vPlanesOn >= 3);
	bool L_F_pl_too_full_u = RPTooFullU(dgn.L_F), L_F_pl_too_full_v = RPTooFullV(dgn.L_F);
	bool L_F_pat_suff = (dgn.L_F.pat->u.size() > 0 || dgn.L_F.pat->v.size() > 0) || (L_F_pl_too_full_u || L_F_pl_too_full_v);
	bool L_F_pat_more = (dgn.L_F.pat->u.size() > 1 && dgn.L_F.pat->v.size() > 1) || (L_F_pl_too_full_u || L_F_pl_too_full_v);
	bool L_F_tr_any = (dgn.L_F.tr->valid || dgn.L_F.mtr->size() > 0);
	
	bool R_N_pl_suff = (dgn.R_N.digi->uPlanesOn >= 3 && dgn.R_N.digi->vPlanesOn >= 3);
	bool R_N_pl_too_full_u = RPTooFullU(dgn.R_N), R_N_pl_too_full_v = RPTooFullV(dgn.R_N);
	bool R_N_pat_suff = (dgn.R_N.pat->u.size() > 0 || dgn.R_N.pat->v.size() > 0) || (R_N_pl_too_full_u || R_N_pl_too_full_v);
	bool R_N_pat_more = (dgn.R_N.pat->u.size() > 1 && dgn.R_N.pat->v.size() > 1) || (R_N_pl_too_full_u || R_N_pl_too_full_v);
	bool R_N_tr_any = (dgn.R_N.tr->valid || dgn.R_N.mtr->size() > 0);
	
	bool R_F_pl_suff = (dgn.R_F.digi->uPlanesOn >= 3 && dgn.R_F.digi->vPlanesOn >= 3);
	bool R_F_pl_too_full_u = RPTooFullU(dgn.R_F), R_F_pl_too_full_v = RPTooFullV(dgn.R_F);
	bool R_F_pat_suff = (dgn.R_F.pat->u.size() > 0 || dgn.R_F.pat->v.size() > 0) || (R_F_pl_too_full_u || R_F_pl_too_full_v);
	bool R_F_pat_more = (dgn.R_F.pat->u.size() > 1 && dgn.R_F.pat->v.size() > 1) || (R_F_pl_too_full_u || R_F_pl_too_full_v);
	bool R_F_tr_any = (dgn.R_F.tr->valid || dgn.R_F.mtr->size() > 0);

	c["total"]["total"][period]++;

	if (L_N_pl_suff) c["L_N"]["pl_suff"][period]++;
	if (L_N_pat_suff) c["L_N"]["pat_suff"][period]++;
	if (L_N_tr_any) c["L_N"]["tr_any"][period]++;

	if (L_F_pl_suff) c["L_F"]["pl_suff"][period]++;
	if (L_F_pat_suff) c["L_F"]["pat_suff"][period]++;
	if (L_F_tr_any) c["L_F"]["tr_any"][period]++;

	if (R_N_pl_suff) c["R_N"]["pl_suff"][period]++;
	if (R_N_pat_suff) c["R_N"]["pat_suff"][period]++;
	if (R_N_tr_any) c["R_N"]["tr_any"][period]++;

	if (R_F_pl_suff) c["R_F"]["pl_suff"][period]++;
	if (R_F_pat_suff) c["R_F"]["pat_suff"][period]++;
	if (R_F_tr_any) c["R_F"]["tr_any"][period]++;

	if (L_N_pl_suff && L_F_pl_suff) c["L_N, L_F"]["pl_suff && pl_suff"][period]++;
	if (L_N_pl_suff || L_F_pl_suff) c["L_N, L_F"]["pl_suff || pl_suff"][period]++;
	if (L_N_pat_suff && L_F_pat_suff) c["L_N, L_F"]["pat_suff && pat_suff"][period]++;
	if (L_N_pat_suff || L_F_pat_suff) c["L_N, L_F"]["pat_suff || pat_suff"][period]++;
	if (L_N_pat_more && L_F_pat_more) c["L_N, L_F"]["pat_more && pat_more"][period]++;
	if (L_N_tr_any && L_F_tr_any) c["L_N, L_F"]["tr_any && tr_any"][period]++;
	if (L_N_tr_any || L_F_tr_any) c["L_N, L_F"]["tr_any || tr_any"][period]++;

	if (R_N_pl_suff && R_F_pl_suff) c["R_N, R_F"]["pl_suff && pl_suff"][period]++;
	if (R_N_pl_suff || R_F_pl_suff) c["R_N, R_F"]["pl_suff || pl_suff"][period]++;
	if (R_N_pat_suff && R_F_pat_suff) c["R_N, R_F"]["pat_suff && pat_suff"][period]++;
	if (R_N_pat_suff || R_F_pat_suff) c["R_N, R_F"]["pat_suff || pat_suff"][period]++;
	if (R_N_pat_more && R_F_pat_more) c["R_N, R_F"]["pat_more && pat_more"][period]++;
	if (R_N_tr_any && R_F_tr_any) c["R_N, R_F"]["tr_any && tr_any"][period]++;
	if (R_N_tr_any || R_F_tr_any) c["R_N, R_F"]["tr_any || tr_any"][period]++;

	if ((L_N_pl_suff && L_F_pl_suff) && (R_N_pl_suff && R_F_pl_suff)) c["dgn"]["pl_suff && pl_suff, L && R"][period]++;
	if ((L_N_pl_suff && L_F_pl_suff) || (R_N_pl_suff && R_F_pl_suff)) c["dgn"]["pl_suff && pl_suff, L || R"][period]++;
	if ((L_N_pat_suff && L_F_pat_suff) && (R_N_pat_suff && R_F_pat_suff)) c["dgn"]["pat_suff && pat_suff, L && R"][period]++;
	if ((L_N_pat_suff && L_F_pat_suff) || (R_N_pat_suff && R_F_pat_suff)) c["dgn"]["pat_suff && pat_suff, L || R"][period]++;
	if ((L_N_tr_any && L_F_tr_any) && (R_N_tr_any && R_F_tr_any)) c["dgn"]["tr_any && tr_any, L && R"][period]++;
	if ((L_N_tr_any && L_F_tr_any) || (R_N_tr_any && R_F_tr_any)) c["dgn"]["tr_any && tr_any, L || R"][period]++;
}

//----------------------------------------------------------------------------------------------------

struct Period
{
	time_t ts_first, ts_last;
	unsigned int run;
	unsigned int events;

	Period(time_t _tsf=0, time_t _tsl=0, unsigned int _r=0, unsigned int _e=0) :
		ts_first(_tsf), ts_last(_tsl), run(_r), events(_e) {}

	void Fill(time_t t)
	{
		events++;
		ts_first = min(ts_first, t);
		ts_last = max(ts_last, t);
	}

	bool IsCompatible(time_t t, unsigned int r)
	{
		time_t width = 300;

		if (r != run)
			return false;
		if (t < ts_first || t > ts_first + width)
			return false;
		return true;
	}
};

vector<Period> periods;

//----------------------------------------------------------------------------------------------------

unsigned int FillPeriod(unsigned int run, time_t timestamp)
{
	unsigned int pi = periods.size();
	while (pi > 0)
	{
		pi--;
		if (periods[pi].IsCompatible(timestamp, run))
		{
			periods[pi].Fill(timestamp);
			return pi;
		}
	}

	periods.push_back(Period(timestamp, timestamp, run, 1));
	return periods.size() - 1;
}


//----------------------------------------------------------------------------------------------------

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;

	// init diagonal
	Init(argv[1]);
	if (diagonal != dCombined)
		return rcIncompatibleDiagonal;

	// get input
	InitInputFiles();
	TChain *ch = new TChain("TotemNtuple");
	for (unsigned int i = 0; i < input_files.size(); i++)
	{
		ch->Add(input_files[i].c_str());
		printf("+ %s\n", input_files[i].c_str());
	}
	printf(">> chain entries: %llu\n", ch->GetEntries());

	// prepare output
	TFile *outF = new TFile((string("pileup_") + argv[1] + ".root").c_str(), "recreate");

	// select and link input branches
	ch->SetBranchStatus("*", 0);

	EventMetaData *metaData = new EventMetaData();
	ch->SetBranchStatus("event_info.*", 1);
	ch->SetBranchAddress("event_info.", &metaData);

	TriggerData *triggerData = new TriggerData();
	ch->SetBranchStatus("trigger_data.*", 1);
	ch->SetBranchAddress("trigger_data.", &triggerData);

	DiagStruct diag_45b, diag_45t;
	diag_45b.AssignBranches(ch, 25, 21, 120, 124);
	diag_45t.AssignBranches(ch, 24, 20, 121, 125);

	// prepare counters and histograms
	map<string, CounterMap> counters;	// map: diagonal label -> CounterMap

	unsigned int N_bunch=0;
	unsigned int N_bunch_zeroBias=0;

	// loop over events
	long int ev = 0, ev_anal = 0;
	for (; ev < ch->GetEntries(); ev++)
	{
		ch->GetEvent(ev);

		// skip troublesome runs
		unsigned int run = metaData->run_no / 100000;
		unsigned int file = metaData->run_no % 100000;
		if (SkipRun(run, file, false))
			continue;

		// select bunches
		if (SkipBunch(run, triggerData->bunch_num))
			continue;

		N_bunch++;

		// zero-bias selection
		if (! IsZeroBias(triggerData->input_status_bits, metaData->run_no, triggerData->event_num))
			continue;

		N_bunch_zeroBias++;

		unsigned int timestamp = metaData->timestamp - timestamp0;
		unsigned int periodIdx = FillPeriod(run, timestamp);

		// set analysis parameters - must correspond to reconstruction configuration!
		maxHitsPerPlaneToSearch = 5;
		minPlanesPerProjectionToSearch = 2;
		//minPlanesPerProjectionToFit = 3

		// run analysis
		ev_anal++;
		AnalyzeDiagonal(diag_45b, counters["45b_56t"], periodIdx);
		AnalyzeDiagonal(diag_45t, counters["45t_56b"], periodIdx);
	}

	printf(">> last event number: %li\n", ev);
	printf(">> events analyzed: %li\n", ev_anal);
	
	printf("\n");
	printf("N_bunch: %u\n", N_bunch);
	printf("N_bunch_zeroBias: %u\n", N_bunch_zeroBias);

	// save results
	for (map<string, CounterMap>::iterator dgni = counters.begin(); dgni != counters.end(); ++dgni)
	{
		TDirectory *dgnDir = outF->mkdir(dgni->first.c_str());
		
		for (map<string, map<string, map<unsigned int, unsigned long> > >::iterator oi = dgni->second.begin(); oi != dgni->second.end(); ++oi)
		{
			TDirectory *objDir = dgnDir->mkdir(oi->first.c_str());

			for (map<string, map<unsigned int, unsigned long> >::iterator qi = oi->second.begin(); qi != oi->second.end(); ++qi)
			{
				TDirectory *qDir = objDir->mkdir(qi->first.c_str());
				gDirectory = qDir;

				TGraphErrors *g_v = new TGraphErrors(); g_v->SetName("val");
				TGraphErrors *g_r = new TGraphErrors(); g_r->SetName("rel");
				TGraphErrors *g_run = new TGraphErrors(); g_run->SetName("runs");
				
				for (map<unsigned int, unsigned long>::iterator pi = qi->second.begin(); pi != qi->second.end(); ++pi)
				{
					const Period &p = periods[pi->first];
					double t_l = p.ts_first, t_h = p.ts_last;
					double t = (t_h + t_l) / 2.;
					double te = (t_h - t_l) / 2.;

					double tot = dgni->second["total"]["total"][pi->first];

					int idx = g_v->GetN();
					g_v->SetPoint(idx, t, pi->second);
					g_v->SetPointError(idx, te, sqrt(pi->second));
					
					g_r->SetPoint(idx, t, pi->second / tot);
					g_r->SetPointError(idx, te, sqrt(pi->second) / tot);

					g_run->SetPoint(idx, t, p.run);
					g_run->SetPointError(idx, te, 0.);

					/*
					map<unsigned int, TGraphErrors *>::iterator it = g_r_per_run.find(p.run);
					if (it == g_r_per_run.end())
						it = g_r_per_run.insert(pair<unsigned int, TGraphErrors *>(p.run, new TGraphErrors)).first;

					idx = it->second->GetN();
					it->second->SetPoint(idx, t, pi->second / tot);
					it->second->SetPointError(idx, te, sqrt(pi->second) / tot);
					*/
				}

				g_v->Write();
				g_r->Write();
				g_run->Write();
			}
		}
	}

	delete outF;
	return 0;
}
