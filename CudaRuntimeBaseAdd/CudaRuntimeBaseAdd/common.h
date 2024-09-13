#pragma once
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <stdlib.h>

void cudaConfig();
void cudaConfigTest();
bool check(float* out, float* res, int n);

int testAdd();
int reduce_v0();
int reduce_v1_no_divergence_branch();
int reduce_v2_no_bank_conflict();
int reduce_v3_add_during_load();
int reduce_v4_unroll_last_warp();
int reduce_v5_completely_unroll();
int reduce_v6_multi_add();
int reduce_v7_shuffle();