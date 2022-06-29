#pragma once
#include <execution/sched/system_sched/syssched.h>
#include <execution/traits/sched/sched_traits.h>

typedef struct __spikedog_tcp_sched
{
	synapse_execution_sched_traits
		ptr_sched;
} __spikedog_tcp_sched;