#include <string>
#include <vector>

//----------------------------------------------------------------------------------------------------

std::vector<std::string> input_files;

std::string input_ntuple_name;

void InitInputFiles()
{
	input_ntuple_name = "TotemNtuple";

	input_files.clear();

	std::string prefix = "root://eostotem.cern.ch//eos/totem/data/offline/2015/90m_5sigma/version2/";
	input_files.push_back(prefix + "run_9845.0_ntuple.root");
	input_files.push_back(prefix + "run_9845.10_ntuple.root");
	input_files.push_back(prefix + "run_9845.11_ntuple.root");
	input_files.push_back(prefix + "run_9845.12_ntuple.root");
	input_files.push_back(prefix + "run_9845.13_ntuple.root");
	input_files.push_back(prefix + "run_9845.14_ntuple.root");
	input_files.push_back(prefix + "run_9845.15_ntuple.root");
	input_files.push_back(prefix + "run_9845.16_ntuple.root");
	input_files.push_back(prefix + "run_9845.17_ntuple.root");
	input_files.push_back(prefix + "run_9845.18_ntuple.root");
	input_files.push_back(prefix + "run_9845.19_ntuple.root");
	input_files.push_back(prefix + "run_9845.1_ntuple.root");
	input_files.push_back(prefix + "run_9845.20_ntuple.root");
	input_files.push_back(prefix + "run_9845.21_ntuple.root");
	input_files.push_back(prefix + "run_9845.22_ntuple.root");
	input_files.push_back(prefix + "run_9845.23_ntuple.root");
	input_files.push_back(prefix + "run_9845.24_ntuple.root");
	input_files.push_back(prefix + "run_9845.25_ntuple.root");
	input_files.push_back(prefix + "run_9845.26_ntuple.root");
	input_files.push_back(prefix + "run_9845.27_ntuple.root");
	input_files.push_back(prefix + "run_9845.28_ntuple.root");
	input_files.push_back(prefix + "run_9845.29_ntuple.root");
	input_files.push_back(prefix + "run_9845.2_ntuple.root");
	input_files.push_back(prefix + "run_9845.30_ntuple.root");
	input_files.push_back(prefix + "run_9845.31_ntuple.root");
	input_files.push_back(prefix + "run_9845.32_ntuple.root");
	input_files.push_back(prefix + "run_9845.33_ntuple.root");
	input_files.push_back(prefix + "run_9845.34_ntuple.root");
	input_files.push_back(prefix + "run_9845.35_ntuple.root");
	input_files.push_back(prefix + "run_9845.36_ntuple.root");
	input_files.push_back(prefix + "run_9845.37_ntuple.root");
	input_files.push_back(prefix + "run_9845.38_ntuple.root");
	input_files.push_back(prefix + "run_9845.39_ntuple.root");
	input_files.push_back(prefix + "run_9845.3_ntuple.root");
	input_files.push_back(prefix + "run_9845.40_ntuple.root");
	input_files.push_back(prefix + "run_9845.41_ntuple.root");
	input_files.push_back(prefix + "run_9845.42_ntuple.root");
	input_files.push_back(prefix + "run_9845.43_ntuple.root");
	input_files.push_back(prefix + "run_9845.44_ntuple.root");
	input_files.push_back(prefix + "run_9845.45_ntuple.root");
	input_files.push_back(prefix + "run_9845.46_ntuple.root");
	input_files.push_back(prefix + "run_9845.47_ntuple.root");
	input_files.push_back(prefix + "run_9845.48_ntuple.root");
	input_files.push_back(prefix + "run_9845.49_ntuple.root");
	input_files.push_back(prefix + "run_9845.4_ntuple.root");
	input_files.push_back(prefix + "run_9845.50_ntuple.root");
	input_files.push_back(prefix + "run_9845.51_ntuple.root");
	input_files.push_back(prefix + "run_9845.52_ntuple.root");
	input_files.push_back(prefix + "run_9845.53_ntuple.root");
	input_files.push_back(prefix + "run_9845.54_ntuple.root");
	input_files.push_back(prefix + "run_9845.55_ntuple.root");
	input_files.push_back(prefix + "run_9845.56_ntuple.root");
	input_files.push_back(prefix + "run_9845.57_ntuple.root");
	input_files.push_back(prefix + "run_9845.58_ntuple.root");
	input_files.push_back(prefix + "run_9845.59_ntuple.root");
	input_files.push_back(prefix + "run_9845.5_ntuple.root");
	input_files.push_back(prefix + "run_9845.60_ntuple.root");
	input_files.push_back(prefix + "run_9845.61_ntuple.root");
	input_files.push_back(prefix + "run_9845.62_ntuple.root");
	input_files.push_back(prefix + "run_9845.63_ntuple.root");
	input_files.push_back(prefix + "run_9845.64_ntuple.root");
	input_files.push_back(prefix + "run_9845.65_ntuple.root");
	input_files.push_back(prefix + "run_9845.66_ntuple.root");
	input_files.push_back(prefix + "run_9845.67_ntuple.root");
	input_files.push_back(prefix + "run_9845.68_ntuple.root");
	input_files.push_back(prefix + "run_9845.69_ntuple.root");
	input_files.push_back(prefix + "run_9845.6_ntuple.root");
	input_files.push_back(prefix + "run_9845.7_ntuple.root");
	input_files.push_back(prefix + "run_9845.8_ntuple.root");
	input_files.push_back(prefix + "run_9845.9_ntuple.root");
}
