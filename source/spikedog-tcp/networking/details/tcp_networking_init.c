#include <spikedog/tcp/details/networking/tcp_networking_init.h>
#include <spikedog/tcp/details/networking/tcp_networking_handler.h>

#include <spikedog/tcp/details/sched/tcp_sched.h>

#include <spikedog/tcp/details/mman/tcp_mman.h>
#include <spikedog/tcp/details/mman/tcp_mpool_type.h>

__spikedog_tcp_mpool
	__spikedog_tcp_socket_mpool;

void
__spikedog_tcp_initialize_system
	()
{
	__spikedog_tcp_socket_mpool.ptr_mpool_traits.hnd_traits
		= synapse_memory_pooling_dynamic_initialize
			(&__spikedog_tcp_mman_entity()->ptr_mman_traits, sizeof(__spikedog_tcp), 4096);

	__spikedog_tcp_socket_mpool.ptr_mpool_traits.hnd_traits
		= synapse_memory_pooling_dynamic_initialize
			(&__spikedog_tcp_mman_entity()->ptr_mman_traits, 4096, 4096);
	
	__spikedog_tcp_socket_mpool.ptr_mpool_traits.allocate
		= &synapse_memory_pooling_dynamic_allocate;
	__spikedog_tcp_socket_mpool.ptr_mpool_traits.deallocate
		= &synapse_memory_pooling_dynamic_deallocate;

	__spikedog_tcp_socket_mpool.ptr_mpool_traits.expand_size
		= &synapse_memory_pooling_dynamic_expand;
	__spikedog_tcp_socket_mpool.ptr_mpool_traits.shrink_size
		= &synapse_memory_pooling_dynamic_shrink;

	__spikedog_tcp_socket_mpool.ptr_mpool_traits.retrieve_pointer
		= &synapse_memory_pooling_dynamic_retrieve_pointer;
}

void
__spikedog_tcp_cleanup_system
	()
{
	synapse_memory_pooling_dynamic_cleanup
		(__spikedog_tcp_socket_mpool.ptr_mpool_traits.hnd_traits);
}

__spikedog_tcp*
__spikedog_tcp_initialize_v4
	(void* pAdditional)
{
	__spikedog_tcp_mpool_chunk ptr_tcp_mpool
		= __spikedog_tcp_socket_mpool.ptr_mpool_traits.allocate
				(__spikedog_tcp_socket_mpool.ptr_mpool_traits.hnd_traits,
					NULL);

	__spikedog_tcp* ptr_tcp
		= __spikedog_tcp_socket_mpool.ptr_mpool_traits.retrieve_pointer
				(ptr_tcp_mpool);

	ptr_tcp->hnd_net = synapse_networking_tcp_initialize_v4
						(&__spikedog_tcp_sched_entity()->ptr_sched, 
							&__spikedog_tcp_handler_connected,
							&__spikedog_tcp_handler_disconnected);

	ptr_tcp->hnd_net_mman_node
		= ptr_tcp_mpool;
}