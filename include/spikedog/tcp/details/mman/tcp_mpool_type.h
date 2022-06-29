#pragma once
#include <memory/pooling/dynamic_pooling_traits.h>
#include <memory/pooling/dynamic/dynamic_pool.h>

typedef struct __spikedog_tcp_mpool
{
	synapse_memory_pooling_dynamic_traits
		ptr_mpool_traits;
} __spikedog_tcp_mpool;

typedef synapse_memory_pooling_dynamic_chunk 
			__spikedog_tcp_mpool_chunk;