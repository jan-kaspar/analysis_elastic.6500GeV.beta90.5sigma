#include <string>
#include <vector>

//----------------------------------------------------------------------------------------------------

std::vector<std::string> input_files;

std::string input_ntuple_name;

void InitInputFiles()
{
	input_ntuple_name = "TotemNtuple";

	input_files.clear();

	// 2015_10_13_fill4489

	std::string prefix = "root://eostotem.cern.ch//eos/totem/data/offline/2015/90m_5sigma/version1/";

	input_files.push_back(prefix + "run_9836.0_ntuple.root");
	input_files.push_back(prefix + "run_9836.10_ntuple.root");
	input_files.push_back(prefix + "run_9836.12_ntuple.root");
	input_files.push_back(prefix + "run_9836.13_ntuple.root");
	input_files.push_back(prefix + "run_9836.14_ntuple.root");
	input_files.push_back(prefix + "run_9836.15_ntuple.root");
	input_files.push_back(prefix + "run_9836.16_ntuple.root");
	input_files.push_back(prefix + "run_9836.17_ntuple.root");
	input_files.push_back(prefix + "run_9836.18_ntuple.root");
	input_files.push_back(prefix + "run_9836.19_ntuple.root");
	input_files.push_back(prefix + "run_9836.1_ntuple.root");
	input_files.push_back(prefix + "run_9836.2_ntuple.root");
	input_files.push_back(prefix + "run_9836.3_ntuple.root");
	input_files.push_back(prefix + "run_9836.4_ntuple.root");
	input_files.push_back(prefix + "run_9836.5_ntuple.root");
	input_files.push_back(prefix + "run_9836.6_ntuple.root");
	input_files.push_back(prefix + "run_9836.7_ntuple.root");
	input_files.push_back(prefix + "run_9836.9_ntuple.root");
	input_files.push_back(prefix + "run_9838.0_ntuple.root");
	input_files.push_back(prefix + "run_9838.10_ntuple.root");
	input_files.push_back(prefix + "run_9838.11_ntuple.root");
	input_files.push_back(prefix + "run_9838.12_ntuple.root");
	input_files.push_back(prefix + "run_9838.14_ntuple.root");
	input_files.push_back(prefix + "run_9838.1_ntuple.root");
	input_files.push_back(prefix + "run_9838.2_ntuple.root");
	input_files.push_back(prefix + "run_9838.3_ntuple.root");
	input_files.push_back(prefix + "run_9838.4_ntuple.root");
	input_files.push_back(prefix + "run_9838.5_ntuple.root");
	input_files.push_back(prefix + "run_9838.6_ntuple.root");
	input_files.push_back(prefix + "run_9838.7_ntuple.root");
	input_files.push_back(prefix + "run_9838.8_ntuple.root");
	input_files.push_back(prefix + "run_9838.9_ntuple.root");
	input_files.push_back(prefix + "run_9840.0_ntuple.root");
	input_files.push_back(prefix + "run_9840.11_ntuple.root");
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
	input_files.push_back(prefix + "run_9840.27_ntuple.root");
	input_files.push_back(prefix + "run_9840.28_ntuple.root");
	input_files.push_back(prefix + "run_9840.29_ntuple.root");
	input_files.push_back(prefix + "run_9840.2_ntuple.root");
	input_files.push_back(prefix + "run_9840.30_ntuple.root");
	input_files.push_back(prefix + "run_9840.31_ntuple.root");
	input_files.push_back(prefix + "run_9840.32_ntuple.root");
	input_files.push_back(prefix + "run_9840.33_ntuple.root");
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
	input_files.push_back(prefix + "run_9840.48_ntuple.root");
	input_files.push_back(prefix + "run_9840.49_ntuple.root");
	input_files.push_back(prefix + "run_9840.4_ntuple.root");
	input_files.push_back(prefix + "run_9840.50_ntuple.root");
	input_files.push_back(prefix + "run_9840.51_ntuple.root");
	input_files.push_back(prefix + "run_9840.52_ntuple.root");
	input_files.push_back(prefix + "run_9840.53_ntuple.root");
	input_files.push_back(prefix + "run_9840.54_ntuple.root");
	input_files.push_back(prefix + "run_9840.5_ntuple.root");
	input_files.push_back(prefix + "run_9840.6_ntuple.root");
	input_files.push_back(prefix + "run_9840.7_ntuple.root");
	input_files.push_back(prefix + "run_9840.8_ntuple.root");
	input_files.push_back(prefix + "run_9840.9_ntuple.root");
	input_files.push_back(prefix + "run_9841.0_ntuple.root");
	input_files.push_back(prefix + "run_9841.1_ntuple.root");
	input_files.push_back(prefix + "run_9841.2_ntuple.root");
	input_files.push_back(prefix + "run_9841.3_ntuple.root");
	input_files.push_back(prefix + "run_9841.4_ntuple.root");
	input_files.push_back(prefix + "run_9841.5_ntuple.root");
	input_files.push_back(prefix + "run_9841.6_ntuple.root");
	input_files.push_back(prefix + "run_9841.7_ntuple.root");
	input_files.push_back(prefix + "run_9841.8_ntuple.root");
	input_files.push_back(prefix + "run_9841.9_ntuple.root");
	input_files.push_back(prefix + "run_9843.1_ntuple.root");
	input_files.push_back(prefix + "run_9843.2_ntuple.root");
	input_files.push_back(prefix + "run_9843.3_ntuple.root");
	input_files.push_back(prefix + "run_9843.4_ntuple.root");
	input_files.push_back(prefix + "run_9843.5_ntuple.root");
	input_files.push_back(prefix + "run_9843.8_ntuple.root");
	input_files.push_back(prefix + "run_9843.9_ntuple.root");
	input_files.push_back(prefix + "run_9844.0_ntuple.root");
	input_files.push_back(prefix + "run_9844.1_ntuple.root");
	input_files.push_back(prefix + "run_9844.2_ntuple.root");
	input_files.push_back(prefix + "run_9844.3_ntuple.root");
	input_files.push_back(prefix + "run_9844.4_ntuple.root");
	input_files.push_back(prefix + "run_9845.0_ntuple.root");
	input_files.push_back(prefix + "run_9845.10_ntuple.root");
	input_files.push_back(prefix + "run_9845.11_ntuple.root");
	input_files.push_back(prefix + "run_9845.12_ntuple.root");
	input_files.push_back(prefix + "run_9845.13_ntuple.root");
	input_files.push_back(prefix + "run_9845.14_ntuple.root");
	input_files.push_back(prefix + "run_9845.15_ntuple.root");
	input_files.push_back(prefix + "run_9845.16_ntuple.root");
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
	input_files.push_back(prefix + "run_9845.2_ntuple.root");
	input_files.push_back(prefix + "run_9845.30_ntuple.root");
	input_files.push_back(prefix + "run_9845.31_ntuple.root");
	input_files.push_back(prefix + "run_9845.32_ntuple.root");
	input_files.push_back(prefix + "run_9845.33_ntuple.root");
	input_files.push_back(prefix + "run_9845.34_ntuple.root");
	input_files.push_back(prefix + "run_9845.3_ntuple.root");
	input_files.push_back(prefix + "run_9845.5_ntuple.root");
	input_files.push_back(prefix + "run_9845.6_ntuple.root");
	input_files.push_back(prefix + "run_9845.7_ntuple.root");
	input_files.push_back(prefix + "run_9845.8_ntuple.root");
	input_files.push_back(prefix + "run_9845.9_ntuple.root");
}
