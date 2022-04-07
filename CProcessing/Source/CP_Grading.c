#ifdef GRADING

//------------------------------------------------------------------------------
// file:	CP_Commands.c
// author:	Gerald Wong
// brief:	Command system used to keep track of CP functions called
//
// Copyright © 2019 DigiPen, All rights reserved.
//------------------------------------------------------------------------------
#include "cprocessing.h"
#include "cprocessing_grading.h"

static CP_Commands global_commands;

CP_API CP_Commands*	CP_Commands_GetCurrentFrame() {
	return &global_commands;
}
CP_API unsigned int CP_Commands_GetCount(CP_Commands* commands) {
	return commands->entry_count;
}

// Internal
static inline void*
AlignBackward(void* ptr, unsigned char align) {
    return (void*)((uintptr_t)(ptr) & ~(align - 1));
}

static inline void*
AlignForward(void* ptr, unsigned char align) {
    return (void*)(((uintptr_t)(ptr)+(align - 1)) & ~(align - 1));
}


static inline unsigned char
AlignBackwardDiff(void* ptr, unsigned char align) {
    return (unsigned char)((uintptr_t)ptr - (uintptr_t)(AlignBackward(ptr, align)));
}

static inline unsigned char
AlignForwardDiff(void* ptr, unsigned char align) {
    return (unsigned char)((uintptr_t)(AlignForward(ptr, align)) - (uintptr_t)(ptr));
}

// public
CP_API void CP_Commands_Clear(CP_Commands* CP_Commands) {
    CP_Commands->data_memory_at = CP_Commands->memory;

    unsigned char* entry_memory_start = CP_Commands->memory + CP_Commands->memory_size - sizeof(CP_CommandsEntryHeader);
    unsigned char adjust = AlignBackwardDiff(entry_memory_start, alignof(CP_CommandsEntryHeader));
    entry_memory_start -= adjust;

    CP_Commands->entry_memory_start = entry_memory_start;
    CP_Commands->entry_memory_at = entry_memory_start;

    CP_Commands->entry_count = 0;
}

CP_API int CP_Commands_Init(CP_Commands* M, void* memory, unsigned int memory_size) {
    if (!memory || memory_size <= 0) {
        return 0;
    }
    M->memory = (unsigned char*)memory;
    M->memory_size = memory_size;
    CP_Commands_Clear(M);
    return 1;
}


// NOTE(Momo): Accessors and Iterators
CP_API CP_CommandsEntryHeader* CP_Commands_GetEntry(CP_Commands* CP_Commands, unsigned int Index) {
    return (CP_CommandsEntryHeader*)(CP_Commands->entry_memory_start - Index * sizeof(CP_CommandsEntryHeader));
}


CP_API void* CP_Commands_GetEntryData(CP_Commands* CP_Commands, CP_CommandsEntryHeader* entry) {
    return (CP_Commands->memory + entry->offset_to_data);
}


CP_API void* CP_Commands_PushBlock(CP_Commands* commands, unsigned int Size, unsigned char Alignment, unsigned int Id)
{

    // Allocate data
    unsigned char data_adjust = AlignForwardDiff(commands->data_memory_at, Alignment);
    unsigned int data_size = Size;

    // Allocate entry
    unsigned char entry_adjust = AlignBackwardDiff(commands->entry_memory_at, alignof(CP_CommandsEntryHeader));
    unsigned int entry_size = sizeof(CP_CommandsEntryHeader);

    if (commands->entry_memory_at - entry_size - entry_adjust < commands->data_memory_at + data_size + data_adjust) {
        return 0;
    }

    void* data = ((unsigned char*)commands->data_memory_at + data_adjust);
    commands->data_memory_at += data_size + data_adjust;

    CP_CommandsEntryHeader* entry = (CP_CommandsEntryHeader*)((unsigned char*)commands->entry_memory_at + entry_adjust);

    entry->offset_to_data = (unsigned int)((unsigned char*)data - commands->memory);

    entry->type = Id;
    commands->entry_memory_at -= entry_size;
    ++commands->entry_count;

    return data;
}
#else 
typedef int make_compiler_happy;

#endif