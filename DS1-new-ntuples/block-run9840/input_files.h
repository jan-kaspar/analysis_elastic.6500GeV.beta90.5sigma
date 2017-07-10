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
	input_files.push_back(prefix + "run_9840.0_ntuple.root");
	input_files.push_back(prefix + "run_9840.100_ntuple.root");
	input_files.push_back(prefix + "run_9840.101_ntuple.root");
	input_files.push_back(prefix + "run_9840.102_ntuple.root");
	input_files.push_back(prefix + "run_9840.103_ntuple.root");
	input_files.push_back(prefix + "run_9840.104_ntuple.root");
	input_files.push_back(prefix + "run_9840.105_ntuple.root");
	input_files.push_back(prefix + "run_9840.106_ntuple.root");
	input_files.push_back(prefix + "run_9840.107_ntuple.root");
	input_files.push_back(prefix + "run_9840.108_ntuple.root");
	input_files.push_back(prefix + "run_9840.109_ntuple.root");
	input_files.push_back(prefix + "run_9840.10_ntuple.root");
	input_files.push_back(prefix + "run_9840.11_ntuple.root");
	input_files.push_back(prefix + "run_9840.12_ntuple.root");
	input_files.push_back(prefix + "run_9840.13_ntuple.root");
	input_files.push_back(prefix + "run_9840.14_ntuple.root");
	input_files.push_back(prefix + "run_9840.15_ntuple.root");
	input_files.push_back(prefix + "run_9840.16_ntuple.root");
	input_files.push_back(prefix + "run_9840.17_ntuple.root");
	input_files.push_back(prefix + "run_9840.18_ntuple.root");
	input_files.push_back(prefix + "run_9840.19_ntuple.root");
	input_files.push_back(prefix + "run_9840.1_ntuple.root");
	input_files.push_back(prefix + "run_9840.20_ntuple.root");
	input_files.push_back(prefix + "run_9840.21_ntuple.root");
	input_files.push_back(prefix + "run_9840.22_ntuple.root");
	input_files.push_back(prefix + "run_9840.23_ntuple.root");
	input_files.push_back(prefix + "run_9840.24_ntuple.root");
	input_files.push_back(prefix + "run_9840.25_ntuple.root");
	input_files.push_back(prefix + "run_9840.26_ntuple.root");
	input_files.push_back(prefix + "run_9840.27_ntuple.root");
	input_files.push_back(prefix + "run_9840.28_ntuple.root");
	input_files.push_back(prefix + "run_9840.29_ntuple.root");
	input_files.push_back(prefix + "run_9840.2_ntuple.root");
	input_files.push_back(prefix + "run_9840.30_ntuple.root");
	input_files.push_back(prefix + "run_9840.31_ntuple.root");
	input_files.push_back(prefix + "run_9840.32_ntuple.root");
	input_files.push_back(prefix + "run_9840.33_ntuple.root");
	input_files.push_back(prefix + "run_9840.34_ntuple.root");
	input_files.push_back(prefix + "run_9840.35_ntuple.root");
	input_files.push_back(prefix + "run_9840.36_ntuple.root");
	input_files.push_back(prefix + "run_9840.37_ntuple.root");
	input_files.push_back(prefix + "run_9840.38_ntuple.root");
	input_files.push_back(prefix + "run_9840.39_ntuple.root");
	input_files.push_back(prefix + "run_9840.3_ntuple.root");
	input_files.push_back(prefix + "run_9840.40_ntuple.root");
	input_files.push_back(prefix + "run_9840.41_ntuple.root");
	input_files.push_back(prefix + "run_9840.42_ntuple.root");
	input_files.push_back(prefix + "run_9840.43_ntuple.root");
	input_files.push_back(prefix + "run_9840.44_ntuple.root");
	input_files.push_back(prefix + "run_9840.45_ntuple.root");
	input_files.push_back(prefix + "run_9840.46_ntuple.root");
	input_files.push_back(prefix + "run_9840.47_ntuple.root");
	input_files.push_back(prefix + "run_9840.48_ntuple.root");
	input_files.push_back(prefix + "run_9840.49_ntuple.root");
	input_files.push_back(prefix + "run_9840.4_ntuple.root");
	input_files.push_back(prefix + "run_9840.50_ntuple.root");
	input_files.push_back(prefix + "run_9840.51_ntuple.root");
	input_files.push_back(prefix + "run_9840.52_ntuple.root");
	input_files.push_back(prefix + "run_9840.53_ntuple.root");
	input_files.push_back(prefix + "run_9840.54_ntuple.root");
	input_files.push_back(prefix + "run_9840.55_ntuple.root");
	input_files.push_back(prefix + "run_9840.56_ntuple.root");
	input_files.push_back(prefix + "run_9840.57_ntuple.root");
	input_files.push_back(prefix + "run_9840.58_ntuple.root");
	input_files.push_back(prefix + "run_9840.59_ntuple.root");
	input_files.push_back(prefix + "run_9840.5_ntuple.root");
	input_files.push_back(prefix + "run_9840.60_ntuple.root");
	input_files.push_back(prefix + "run_9840.61_ntuple.root");
	input_files.push_back(prefix + "run_9840.62_ntuple.root");
	input_files.push_back(prefix + "run_9840.63_ntuple.root");
	input_files.push_back(prefix + "run_9840.64_ntuple.root");
	input_files.push_back(prefix + "run_9840.65_ntuple.root");
	input_files.push_back(prefix + "run_9840.66_ntuple.root");
	input_files.push_back(prefix + "run_9840.67_ntuple.root");
	input_files.push_back(prefix + "run_9840.68_ntuple.root");
	input_files.push_back(prefix + "run_9840.69_ntuple.root");
	input_files.push_back(prefix + "run_9840.6_ntuple.root");
	input_files.push_back(prefix + "run_9840.70_ntuple.root");
	input_files.push_back(prefix + "run_9840.71_ntuple.root");
	input_files.push_back(prefix + "run_9840.72_ntuple.root");
	input_files.push_back(prefix + "run_9840.73_ntuple.root");
	input_files.push_back(prefix + "run_9840.74_ntuple.root");
	input_files.push_back(prefix + "run_9840.75_ntuple.root");
	input_files.push_back(prefix + "run_9840.76_ntuple.root");
	input_files.push_back(prefix + "run_9840.77_ntuple.root");
	input_files.push_back(prefix + "run_9840.78_ntuple.root");
	input_files.push_back(prefix + "run_9840.79_ntuple.root");
	input_files.push_back(prefix + "run_9840.7_ntuple.root");
	input_files.push_back(prefix + "run_9840.80_ntuple.root");
	input_files.push_back(prefix + "run_9840.81_ntuple.root");
	input_files.push_back(prefix + "run_9840.82_ntuple.root");
	input_files.push_back(prefix + "run_9840.83_ntuple.root");
	input_files.push_back(prefix + "run_9840.84_ntuple.root");
	input_files.push_back(prefix + "run_9840.85_ntuple.root");
	input_files.push_back(prefix + "run_9840.86_ntuple.root");
	input_files.push_back(prefix + "run_9840.87_ntuple.root");
	input_files.push_back(prefix + "run_9840.88_ntuple.root");
	input_files.push_back(prefix + "run_9840.89_ntuple.root");
	input_files.push_back(prefix + "run_9840.8_ntuple.root");
	input_files.push_back(prefix + "run_9840.90_ntuple.root");
	input_files.push_back(prefix + "run_9840.91_ntuple.root");
	input_files.push_back(prefix + "run_9840.92_ntuple.root");
	input_files.push_back(prefix + "run_9840.93_ntuple.root");
	input_files.push_back(prefix + "run_9840.94_ntuple.root");
	input_files.push_back(prefix + "run_9840.95_ntuple.root");
	input_files.push_back(prefix + "run_9840.96_ntuple.root");
	input_files.push_back(prefix + "run_9840.97_ntuple.root");
	input_files.push_back(prefix + "run_9840.98_ntuple.root");
	input_files.push_back(prefix + "run_9840.99_ntuple.root");
	input_files.push_back(prefix + "run_9840.9_ntuple.root");
}
