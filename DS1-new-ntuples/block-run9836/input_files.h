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
	input_files.push_back(prefix + "run_9836.0_ntuple.root");
	input_files.push_back(prefix + "run_9836.10_ntuple.root");
	input_files.push_back(prefix + "run_9836.11_ntuple.root");
	input_files.push_back(prefix + "run_9836.12_ntuple.root");
	input_files.push_back(prefix + "run_9836.13_ntuple.root");
	input_files.push_back(prefix + "run_9836.14_ntuple.root");
	input_files.push_back(prefix + "run_9836.15_ntuple.root");
	input_files.push_back(prefix + "run_9836.16_ntuple.root");
	input_files.push_back(prefix + "run_9836.17_ntuple.root");
	input_files.push_back(prefix + "run_9836.18_ntuple.root");
	input_files.push_back(prefix + "run_9836.19_ntuple.root");
	input_files.push_back(prefix + "run_9836.1_ntuple.root");
	input_files.push_back(prefix + "run_9836.20_ntuple.root");
	input_files.push_back(prefix + "run_9836.21_ntuple.root");
	input_files.push_back(prefix + "run_9836.22_ntuple.root");
	input_files.push_back(prefix + "run_9836.23_ntuple.root");
	input_files.push_back(prefix + "run_9836.24_ntuple.root");
	input_files.push_back(prefix + "run_9836.25_ntuple.root");
	input_files.push_back(prefix + "run_9836.26_ntuple.root");
	input_files.push_back(prefix + "run_9836.27_ntuple.root");
	input_files.push_back(prefix + "run_9836.28_ntuple.root");
	input_files.push_back(prefix + "run_9836.29_ntuple.root");
	input_files.push_back(prefix + "run_9836.2_ntuple.root");
	input_files.push_back(prefix + "run_9836.30_ntuple.root");
	input_files.push_back(prefix + "run_9836.31_ntuple.root");
	input_files.push_back(prefix + "run_9836.32_ntuple.root");
	input_files.push_back(prefix + "run_9836.33_ntuple.root");
	input_files.push_back(prefix + "run_9836.34_ntuple.root");
	input_files.push_back(prefix + "run_9836.35_ntuple.root");
	input_files.push_back(prefix + "run_9836.36_ntuple.root");
	input_files.push_back(prefix + "run_9836.37_ntuple.root");
	input_files.push_back(prefix + "run_9836.38_ntuple.root");
	input_files.push_back(prefix + "run_9836.39_ntuple.root");
	input_files.push_back(prefix + "run_9836.3_ntuple.root");
	input_files.push_back(prefix + "run_9836.4_ntuple.root");
	input_files.push_back(prefix + "run_9836.5_ntuple.root");
	input_files.push_back(prefix + "run_9836.6_ntuple.root");
	input_files.push_back(prefix + "run_9836.7_ntuple.root");
	input_files.push_back(prefix + "run_9836.8_ntuple.root");
	input_files.push_back(prefix + "run_9836.9_ntuple.root");
}
