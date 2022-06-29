#include <spikedog/tcp/details/mman/tcp_mman.h>

static __spikedog_tcp_mman
			__spikedog_tcp_mman_object;

void
__spikedog_tcp_mman_initialize
	()
{
	__spikedog_tcp_mman_object.ptr_mman_traits.allocate
		= &synapse_memory_mman_stdheap_allocate;
	__spikedog_tcp_mman_object.ptr_mman_traits.deallocate
		= &synapse_memory_mman_stdheap_deallocate;
	__spikedog_tcp_mman_object.ptr_mman_traits.alloc_unit
		= &synapse_memory_mman_stdheap_alloc_unit;
	__spikedog_tcp_mman_object.ptr_mman_traits.hnd_mman
		= synapse_memory_mman_stdheap_initialize(1);
}

void
__spikedog_tcp_mman_cleanup
	()
{
	synapse_memory_mman_stdheap_cleanup
		(__spikedog_tcp_mman_object.ptr_mman_traits.hnd_mman);
}

__spikedog_tcp_mman*
__spikedog_tcp_mman_entity
	()
{
	return
		&__spikedog_tcp_mman_object;
}

void*
__spikedog_tcp_mman_allocate
	(void* pHint, size_t pSize)
{
	return
		__spikedog_tcp_mman_object.ptr_mman_traits.allocate
			(__spikedog_tcp_mman_object.ptr_mman_traits.hnd_mman, pHint, pSize);
}

void*
__spikedog_tcp_mman_deallocate
	(void* pDealloc, size_t pSize)
{
	__spikedog_tcp_mman_object.ptr_mman_traits.deallocate
		(__spikedog_tcp_mman_object.ptr_mman_traits.hnd_mman, pDealloc, pSize);
}