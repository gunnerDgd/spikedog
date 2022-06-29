#include <spikedog/tcp/details/sched/tcp_sched.h>
#include <spikedog/tcp/details/mman/tcp_mpool.h>

#include <execution/sched/system_sched/syssched.h>


static __spikedog_tcp_sched
			__spikedog_tcp_sched_object;


void
__spikedog_tcp_sched_initialize
	()
{
	__spikedog_tcp_sched_object.ptr_sched.hnd_sched
		= synapse_execution_sched_system_initialize
			(&__spikedog_tcp_mpool_entity()->ptr_mpool_traits);

	__spikedog_tcp_sched_object.ptr_sched.dispatch
		= &synapse_execution_sched_system_dispatch;
	__spikedog_tcp_sched_object.ptr_sched.dispatch_from_proc
		= &synapse_execution_sched_system_dispatch_from_proc;

	__spikedog_tcp_sched_object.ptr_sched.execute_once
		= &synapse_execution_sched_system_execute_once;

	__spikedog_tcp_sched_object.ptr_sched.execute_multiple
		= &synapse_execution_sched_system_execute_multiple;
}

void
__spikedog_tcp_sched_cleanup
	()
{
	synapse_execution_sched_system_cleanup
		(__spikedog_tcp_sched_object.ptr_sched.hnd_sched);
}

__spikedog_tcp_sched*
__spikedog_tcp_sched_entity
	()
{
	return
		&__spikedog_tcp_sched_object;
}