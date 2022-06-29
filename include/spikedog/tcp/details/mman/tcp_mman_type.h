#pragma once
#include <memory/mman/mman_traits.h>
#include <memory/mman/standard_heap/stdheap.h>

typedef struct __spikedog_tcp_mman
{
	synapse_memory_mman_traits
		ptr_mman_traits;
} __spikedog_tcp_mman;