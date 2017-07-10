#include "../parameters.h"

#define USE_INIT_ADDITIONAL 1

void Init_additional()
{
	// reset list of subdirectories with distilled ntuples
	distilledNtuples.clear();
	distilledNtuples.push_back(".");
}
