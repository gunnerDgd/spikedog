#include <spikedog/tcp/details/mman/tcp_mpool.h>
#include <spikedog/tcp/details/mman/tcp_mman.h>

static __spikedog_tcp_mpool
			__spikedog_tcp_mpool_object;

void
__spikedog_tcp_mpool_initialize
	()
{
	__spikedog_tcp_mpool_object.ptr_mpool_traits.hnd_traits
		= synapse_memory_pooling_dynamic_initialize
			(&__spikedog_tcp_mman_entity()->ptr_mman_traits, 4096, 4096);
	
	__spikedog_tcp_mpool_object.ptr_mpool_traits.allocate
		= &synapse_memory_pooling_dynamic_allocate;
	__spikedog_tcp_mpool_object.ptr_mpool_traits.deallocate
		= &synapse_memory_pooling_dynamic_deallocate;

	__spikedog_tcp_mpool_object.ptr_mpool_traits.expand_size
		= &synapse_memory_pooling_dynamic_expand;
	__spikedog_tcp_mpool_object.ptr_mpool_traits.shrink_size
		= &synapse_memory_pooling_dynamic_shrink;

	__spikedog_tcp_mpool_object.ptr_mpool_traits.retrieve_pointer
		= &synapse_memory_pooling_dynamic_retrieve_pointer;
}

void
__spikedog_tcp_mpool_cleanup
	()
{
	
}

__spikedog_tcp_mpool*
__spikedog_tcp_mpool_entity
	();

__spikedog_tcp_mpool_chunk
__spikedog_tcp_mpool_allocate
	(void*);

__spikedog_tcp_mpool_chunk
__spikedog_tcp_mpool_deallocate
	(void*);