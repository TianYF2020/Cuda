#include "common.h"

int main()
{
	int index = 7;
	switch (index)
	{
	case 0:
		reduce_v0();
		break;
	case 1:
		reduce_v1_no_divergence_branch();
		break;
	case 2:
		reduce_v2_no_bank_conflict();
		break;
	case 3:
		reduce_v3_add_during_load();
		break;
	case 4:
		reduce_v4_unroll_last_warp();
		break;
	case 5:
		reduce_v5_completely_unroll();
		break;
	case 6:
		reduce_v6_multi_add();
		break;
	case 7:
		reduce_v7_shuffle();
		break;
	default:
		break;
	}
}