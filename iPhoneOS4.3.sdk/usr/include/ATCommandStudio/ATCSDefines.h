/*
 *  ATCSDefines.h
 *  ATCommandStudio
 *
 *  Created by Jared Grubb on 10/4/10.
 *  Copyright 2010 Apple Inc. All rights reserved.
 *
 */

// Macros to export a symbol from the ATCS library
#ifndef __ATCS_DEFINES_H__
#define __ATCS_DEFINES_H__

#ifdef __cplusplus
#define ATCS_EXTERN   extern "C" __attribute__((visibility ("default")))
#define	ATCS_PRIVATE  __attribute__((visibility("hidden")))
#else
#define ATCS_EXTERN   extern __attribute__((visibility ("default")))
#define	ATCS_PRIVATE  __attribute__((visibility("hidden")))
#endif

#define	ATCS_EXTERN_CLASS	__attribute__((visibility("default")))
#define	ATCS_PRIVATE_CLASS	__attribute__((visibility("hidden")))

#endif
