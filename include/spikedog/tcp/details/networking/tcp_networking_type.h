#pragma once
#include <memory/pooling/dynamic_pooling_traits.h>
#include <networking/protocol/tcp/tcp.h>
#include <structure/list/double_linked.h>

#include <spikedog/tcp/networking/tcp_type.h>

typedef struct __spikedog_tcp
{
	synapse_networking_tcp
		hnd_net;
	synapse_memory_pooling_dynamic_chunk
		hnd_net_mman_node;
	synapse_structure_double_linked
		hnd_net_connman;
	synapse_structure_double_linked_node
		hnd_net_connman_node;

	spikedog_tcp_io_handler
		ptr_net_recv_handler,
		ptr_net_send_handler;

	spikedog_tcp_connect_handler
		ptr_net_conn_handler;
	spikedog_tcp_disconnect_handler
		ptr_net_disconn_handler;
} __spikedog_tcp;