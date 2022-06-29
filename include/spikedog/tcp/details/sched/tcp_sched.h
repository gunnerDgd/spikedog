#pragma once
#include <spikedog/tcp/details/sched/tcp_sched_type.h>

void
__spikedog_tcp_sched_initialize
	();

void
__spikedog_tcp_sched_cleanup
	();

__spikedog_tcp_sched*
__spikedog_tcp_sched_entity
	();