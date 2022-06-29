#pragma once
#include <structure/list/double_linked.h>

typedef struct __spikedog_tcp_connman
{
	synapse_structure_double_linked
		hnd_connman;
} __spikedog_tcp_connman;

typedef synapse_structure_double_linked_node
			__spikedog_connman_connection;