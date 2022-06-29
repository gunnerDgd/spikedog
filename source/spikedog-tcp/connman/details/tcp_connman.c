#include <spikedog/tcp/details/connman/tcp_connman.h>
#include <spikedog/tcp/details/mman/tcp_mman.h>

static __spikedog_tcp_connman
			__spikedog_tcp_connman_entity;

void
__spikedog_tcp_connman_initialize
	()
{
	__spikedog_tcp_connman_entity.hnd_connman
		= synapse_structure_double_linked_initialize
			(&__spikedog_tcp_mman_entity()->ptr_mman_traits);
}

void
__spikedog_tcp_connman_cleanup
	()
{
	synapse_structure_double_linked_cleanup
		(__spikedog_tcp_connman_entity.hnd_connman);
}

__spikedog_connman_connection
__spikedog_tcp_connman_create_connection
	(__spikedog_tcp* pTcp)
{
	return
		synapse_structure_double_linked_insert_back
			(__spikedog_tcp_connman_entity.hnd_connman , &pTcp, sizeof(__spikedog_tcp*));
}

void
__spikedog_tcp_connman_delete_connection
	(__spikedog_connman_connection pTcp)
{
	synapse_structure_double_linked_erase_node
		(__spikedog_tcp_connman_entity.hnd_connman, pTcp);
}