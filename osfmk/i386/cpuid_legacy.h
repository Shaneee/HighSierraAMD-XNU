/*
 *  cpuid_legacy.h
 *  xnu
 *
 *  Created by mercurysquad on 21/9/08.
 *
 */

/* This file is added to avoid polluting stock cpuid.h */

#ifndef _CPUID_LEGACY_H_
#define _CPUID_LEGACY_H_

/* Declarations for non deterministic cache info */
typedef struct {
	uint32_t	encoding;
	cache_type_t	type;
	uint32_t	totalsize;
	uint32_t	associativity;
	uint32_t	linesize;
	uint32_t	partitions;
} intel_nd_cache_info;

//#define KB (1024)
#define	MB (1024*KB)

/* For encoding information, refer to IA32 instruction set reference A-M, CPUID instruction */
/* Wonder who at Intel came up with this mess */
const intel_nd_cache_info nonDet_CacheInfo[43] = {
/*	byte,	type,	size,	assoc,	linesize */
{	0x06,	L1I,	8*KB,	4,	32,	1	},
{	0x08,	L1I,	16*KB,	4,	32,	1	},
{	0x0A,	L1D,	8*KB,	2,	32,	1	},
{	0x0C,	L1D,	16*KB,	4,	32,	1	},
{	0x0E,	L1D,	24*KB,	6,	64,	1	},
{	0x22,	L3U,	512*KB,	4,	64,	2	},
{	0x23,	L3U,	1*MB,	8,	64,	2	},
{	0x25,	L3U,	2*MB,	8,	64,	2	},
{	0x29,	L3U,	4*MB,	8,	64,	2	},
{	0x2C,	L1D,	32*KB,	8,	64,	2	},
{	0x30,	L1I,	32*KB,	8,	64,	1	},
{	0x41,	L2U,	128*KB,	4,	32,	1	},
{	0x42,	L2U,	256*KB,	4,	32,	1	},
{	0x43,	L2U,	512*KB,	4,	32,	1	},
{	0x44,	L2U,	1*MB,	4,	32,	1	},
{	0x45,	L2U,	2*MB,	4,	32,	1	},
{	0x46,	L3U,	4*MB,	4,	64,	1	},
{	0x47,	L3U,	8*MB,	8,	64,	1	},
{	0x48,	L2U,	3*MB,	12,	64,	1	},
{	0x49,	L2U,	4*MB,	16,	64,	1	}, // for Xeons family Fh model 6h it's L3U but we dont care
{	0x4A,	L3U,	6*MB,	12,	64,	1	},
{	0x4B,	L3U,	8*MB,	16,	64,	1	},
{	0x4C,	L3U,	12*MB,	12,	64,	1	},
{	0x4D,	L3U,	16*MB,	16,	64,	1	},
{	0x4E,	L2U,	6*MB,	24,	64,	1	},
{	0x60,	L1D,	16*KB,	8,	64,	1	},
{	0x66,	L1D,	8*KB,	4,	64,	1	},
{	0x67,	L1D,	16*KB,	4,	64,	1	},
{	0x68,	L1D,	32*KB,	4,	64,	1	},
{	0x78,	L2U,	1*MB,	4,	64,	1	},
{	0x79,	L2U,	128*KB,	8,	64,	2	},
{	0x7A,	L2U,	256*KB,	8,	64,	2	},
{	0x7B,	L2U,	512*KB,	8,	64,	2	},
{	0x7C,	L2U,	1*MB,	8,	64,	2	},
{	0x7D,	L2U,	2*MB,	8,	64,	1	},
{	0x7F,	L2U,	512*KB,	2,	64,	1	},
{	0x80,	L2U,	512*KB,	8,	64,	1	},
{	0x82,	L2U,	256*KB,	8,	32,	1	},
{	0x83,	L2U,	512*KB,	8,	32,	1	},
{	0x84,	L2U,	1*MB,	8,	32,	1	},
{	0x85,	L2U,	2*MB,	8,	32,	1	},
{	0x86,	L2U,	512*KB,	4,	64,	1	},
{	0x87,	L2U,	1*MB,	8,	64,	1	}
};

#define CPUID_MODEL_GULFTOWN 44

#endif // _CPUID_LEGACY_H_
