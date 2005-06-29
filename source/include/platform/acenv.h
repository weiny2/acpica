
/******************************************************************************
 *
 * Name: acenv.h - Generation environment specific items
 *
 *****************************************************************************/

/******************************************************************************
 *
 * 1. Copyright Notice
 *
 * Some or all of this work - Copyright (c) 1999, Intel Corp.  All rights
 * reserved.
 *
 * 2. License
 *
 * 2.1. This is your license from Intel Corp. under its intellectual property
 * rights.  You may have additional license terms from the party that provided
 * you this software, covering your right to use that party's intellectual
 * property rights.
 *
 * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a
 * copy of the source code appearing in this file ("Covered Code") an
 * irrevocable, perpetual, worldwide license under Intel's copyrights in the
 * base code distributed originally by Intel ("Original Intel Code") to copy,
 * make derivatives, distribute, use and display any portion of the Covered
 * Code in any form, with the right to sublicense such rights; and
 *
 * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent
 * license (with the right to sublicense), under only those claims of Intel
 * patents that are infringed by the Original Intel Code, to make, use, sell,
 * offer to sell, and import the Covered Code and derivative works thereof
 * solely to the minimum extent necessary to exercise the above copyright
 * license, and in no event shall the patent license extend to any additions
 * to or modifications of the Original Intel Code.  No other license or right
 * is granted directly or by implication, estoppel or otherwise;
 *
 * The above copyright and patent license is granted only if the following
 * conditions are met:
 *
 * 3. Conditions
 *
 * 3.1. Redistribution of Source with Rights to Further Distribute Source.
 * Redistribution of source code of any substantial portion of the Covered
 * Code or modification with rights to further distribute source must include
 * the above Copyright Notice, the above License, this list of Conditions,
 * and the following Disclaimer and Export Compliance provision.  In addition,
 * Licensee must cause all Covered Code to which Licensee contributes to
 * contain a file documenting the changes Licensee made to create that Covered
 * Code and the date of any change.  Licensee must include in that file the
 * documentation of any changes made by any predecessor Licensee.  Licensee
 * must include a prominent statement that the modification is derived,
 * directly or indirectly, from Original Intel Code.
 *
 * 3.2. Redistribution of Source with no Rights to Further Distribute Source.
 * Redistribution of source code of any substantial portion of the Covered
 * Code or modification without rights to further distribute source must
 * include the following Disclaimer and Export Compliance provision in the
 * documentation and/or other materials provided with distribution.  In
 * addition, Licensee may not authorize further sublicense of source of any
 * portion of the Covered Code, and must include terms to the effect that the
 * license from Licensee to its licensee is limited to the intellectual
 * property embodied in the software Licensee provides to its licensee, and
 * not to intellectual property embodied in modifications its licensee may
 * make.
 *
 * 3.3. Redistribution of Executable. Redistribution in executable form of any
 * substantial portion of the Covered Code or modification must reproduce the
 * above Copyright Notice, and the following Disclaimer and Export Compliance
 * provision in the documentation and/or other materials provided with the
 * distribution.
 *
 * 3.4. Intel retains all right, title, and interest in and to the Original
 * Intel Code.
 *
 * 3.5. Neither the name Intel nor any other trademark owned or controlled by
 * Intel shall be used in advertising or otherwise to promote the sale, use or
 * other dealings in products derived from or relating to the Covered Code
 * without prior written authorization from Intel.
 *
 * 4. Disclaimer and Export Compliance
 *
 * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED
 * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE
 * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,
 * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY
 * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY
 * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A
 * PARTICULAR PURPOSE.
 *
 * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES
 * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR
 * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,
 * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY
 * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL
 * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS
 * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY
 * LIMITED REMEDY.
 *
 * 4.3. Licensee shall not export, either directly or indirectly, any of this
 * software or system incorporating such software without first obtaining any
 * required license or other approval from the U. S. Department of Commerce or
 * any other agency or department of the United States Government.  In the
 * event Licensee exports any such software from the United States or
 * re-exports any such software from a foreign destination, Licensee shall
 * ensure that the distribution and export/re-export of the software is in
 * compliance with all laws, regulations, orders, or other restrictions of the
 * U.S. Export Administration Regulations. Licensee agrees that neither it nor
 * any of its subsidiaries will export/re-export any technical data, process,
 * software, or service, directly or indirectly, to any country for which the
 * United States government or any agency thereof requires an export license,
 * other governmental approval, or letter of assurance, without first obtaining
 * such license, approval or letter.
 *
 *****************************************************************************/

#ifndef __ACENV_H__
#define __ACENV_H__


/*
 * Environment configuration.  The purpose of this file is to interface to the
 * local generation environment.
 *
 * 1) ACPI_USE_SYSTEM_CLIBRARY - Define this if linking to an actual C library.
 *      Otherwise, local versions of string/memory functions will be used.
 * 2) ACPI_USE_STANDARD_HEADERS - Define this if linking to a C library and
 *      the standard header files may be used.
 *
 * The ACPI subsystem only uses low level C library functions that do not call
 * operating system services and may therefore be inlined in the code.
 *
 * It may be necessary to tailor these include files to the target
 * generation environment.
 *
 *
 * Functions and constants used from each header:
 *
 * string.h:    memcpy
 *              memset
 *              strcat
 *              strcmp
 *              strcpy
 *              strlen
 *              strncmp
 *              strncat
 *              strncpy
 *
 * stdlib.h:    strtoul
 *
 * stdarg.h:    va_list
 *              va_arg
 *              va_start
 *              va_end
 *
 */


/*
 * Environment-specific configuration
 */

#ifdef _LINUX

#include <linux/config.h>
#include <linux/string.h>
#include <linux/kernel.h>
#include <linux/ctype.h>
#include <asm/system.h>


/* Use native Linux string library */

#define ACPI_USE_SYSTEM_CLIBRARY

/* Special functions */

#define strtoul             simple_strtoul

/* Linux clib doesn't to strupr, but we do. */
char *
strupr(char *str);

#else

#ifdef _AED_EFI

#include <efi.h>
#include <efistdarg.h>
#include <efilib.h>

#else

#ifdef WIN32

/* MS-VC++ */

#define strupr              _strupr
#define ACPI_USE_STANDARD_HEADERS

#else

/* All other environments */

#define ACPI_USE_STANDARD_HEADERS

#endif
#endif
#endif


/******************************************************************************
 *
 * C library configuration
 *
 *****************************************************************************/

#ifdef ACPI_USE_SYSTEM_CLIBRARY
/*
 * Use the standard C library headers.
 * We want to keep these to a minimum.
 *
 */

#ifdef ACPI_USE_STANDARD_HEADERS
/*
 * Use the standard headers from the standard locations
 */
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#endif /* ACPI_USE_STANDARD_HEADERS */

/*
 * We will be linking to the standard Clib functions
 */

#define STRSTR(s1,s2)           strstr((INT8 *) (s1), (INT8 *) (s2))
#define STRUPR(s)               strupr((INT8 *) (s))
#define STRLEN(s)               strlen((INT8 *) (s))
#define STRCPY(d,s)             strcpy((INT8 *) (d), (INT8 *) (s))
#define STRNCPY(d,s,n)          strncpy((INT8 *) (d), (INT8 *) (s), (n))
#define STRNCMP(d,s,n)          strncmp((INT8 *) (d), (INT8 *) (s), (n))
#define STRCMP(d,s)             strcmp((INT8 *) (d), (INT8 *) (s))
#define STRCAT(d,s)             strcat((INT8 *) (d), (INT8 *) (s))
#define STRNCAT(d,s,n)          strncat((INT8 *) (d), (INT8 *) (s), (n))
#define STRTOUL(d,s,n)          strtoul((d), (s), (n))
#define MEMCPY(d,s,n)           memcpy(d, s, (size_t) n)
#define MEMSET(d,s,n)           memset(d, s, (size_t) n)
#define TOUPPER                 toupper
#define TOLOWER                 tolower


/******************************************************************************
 *
 * Not using native C library, use local implementations
 *
 *****************************************************************************/
#else

/*
 * Use local definitions of C library macros and functions
 * NOTE: The function implementations may not be as efficient
 * as an inline or assembly code implementation provided by a
 * native C library.
 */

#ifndef va_arg

#ifndef _VALIST
#define _VALIST
typedef char *va_list;
#endif /* _VALIST */

/*
 * Storage alignment properties
 */

#define  _AUPBND                (sizeof(int) - 1)
#define  _ADNBND                (sizeof(int) - 1)

/*
 * Variable argument list macro definitions
 */

#define _Bnd(X, bnd)            (((sizeof(X)) + (bnd)) & (~(bnd)))
#define va_arg(ap, T)           (*(T *)(((ap) += ((_Bnd(T, _AUPBND))) \
                                    - (_Bnd(T, _ADNBND)))))
#define va_end(ap)              (void)0
#define va_start(ap, A)         (void) ((ap) = (((INT8 *)&(A)) \
                                    + (_Bnd(A, _AUPBND))))

#endif /* va_arg */


#define STRSTR(s1,s2)           AcpiCmStrstr    ((INT8 *) (s1), (INT8 *) (s2))
#define STRUPR(s)               AcpiCmStrupr    ((INT8 *) (s))
#define STRLEN(s)               AcpiCmStrlen    ((INT8 *) (s))
#define STRCPY(d,s)             AcpiCmStrcpy    ((INT8 *) (d), (INT8 *) (s))
#define STRNCPY(d,s,n)          AcpiCmStrncpy   ((INT8 *) (d), (INT8 *) (s), (n))
#define STRNCMP(d,s,n)          AcpiCmStrncmp   ((INT8 *) (d), (INT8 *) (s), (n))
#define STRCMP(d,s)             AcpiCmStrcmp    ((INT8 *) (d), (INT8 *) (s))
#define STRCAT(d,s)             AcpiCmStrcat    ((INT8 *) (d), (INT8 *) (s))
#define STRNCAT(d,s,n)          AcpiCmStrncat   ((INT8 *) (d), (INT8 *) (s), (n))
#define STRTOUL(d,s,n)          AcpiCmStrtoul   ((INT8 *) (d), (INT8 **) (s), (n))
#define MEMCPY(d,s,n)           AcpiCmMemcpy    ((void *) (d), (const void *) (s), (n))
#define MEMSET(d,v,n)           AcpiCmMemset    ((void *) (d), (v), (n))
#define TOUPPER                 AcpiCmToUpper
#define TOLOWER                 AcpiCmToLower

#endif /* ACPI_USE_SYSTEM_CLIBRARY */


/******************************************************************************
 *
 * Assembly code macros
 *
 *****************************************************************************/

/*
 * Handle platform- and compiler-specific assembly language differences.
 *
 * Notes:
 * 1) Interrupt 3 is used to break into a debugger
 * 2) Interrupts are turned off during ACPI register setup
 */

#ifdef WIN32   /* MS VC */

/*! [Begin] no source code translation  */

#define ACPI_ASM_MACROS
#define causeinterrupt(level)   __asm {int level}
#define BREAKPOINT3             __asm {int 3}
#define disable()               __asm {cli}
#define enable()                __asm {sti}
#define halt()                  __asm {hlt}
#define wbinvd()                __asm {WBINVD}


#define ACPI_ACQUIRE_GLOBAL_LOCK(GLptr, Acq)       __asm {     \
        __asm mov           ecx, GLptr              \
                                                    \
        __asm acq10:                                \
        __asm mov           eax, [ecx]              \
        __asm mov           edx, eax                \
        __asm and           edx, 0xFFFFFFFE         \
        __asm bts           edx, 1                  \
        __asm adc           edx, 0                  \
        __asm lock cmpxchg  dword ptr [ecx], edx    \
        __asm jnz           acq10                   \
                                                    \
        __asm cmp           dl, 3                   \
        __asm sbb           eax, eax                \
        __asm mov           Acq, al                 \
}

#define ACPI_RELEASE_GLOBAL_LOCK(GLptr, Pnd)       __asm {     \
        __asm mov           ecx, GLptr              \
                                                    \
        __asm Rel10:                                \
        __asm mov           eax, [ecx]              \
        __asm mov           edx, eax                \
        __asm and           edx, 0xFFFFFFFC         \
        __asm lock cmpxchg  dword ptr [ecx], edx    \
        __asm jnz           Rel10                   \
                                                    \
        __asm cmp           dl, 3                   \
        __asm and           eax, 1                  \
        __asm mov           Pnd, al                 \
}

/*! [End] no source code translation !*/


#endif /* WIN32 */


#ifdef __GNUC__

#ifdef __ia64__
#define _IA64
#endif

#define ACPI_ASM_MACROS
#define causeinterrupt(level)
#define BREAKPOINT3
#define disable() __cli()
#define enable()  __sti()
#define halt()    __asm__ __volatile__ ("sti; hlt":::"memory")
#define wbinvd()


/*! [Begin] no source code translation
 *
 * A brief explanation as GNU inline assembly is a bit hairy
 *  %0 is the output parameter in EAX ("=a")
 *  %1 and %2 are the input parameters in ECX ("c") and an immediate value ("i") respectively
 *  All actual register references are preceded with "%%" as in "%%edx"
 *  Immediate values in the assembly are preceded by "$" as in "$0x1"
 *  The final asm parameter is the non-output registers altered by the operation
 */
#define ACPI_ACQUIRE_GLOBAL_LOCK(GLptr, Acq) \
    do { \
        int dummy; \
        asm("1:     movl (%1),%%eax;" \
            "movl   %%eax,%%edx;" \
            "andl   %2,%%edx;" \
            "btsl   $0x1,%%edx;" \
            "adcl   $0x0,%%edx;" \
            "lock;  cmpxchgl %%edx,(%1);" \
            "jnz    1b;" \
            "cmpb   $0x3,%%dl;" \
            "sbbl   %%eax,%%eax" \
            :"=a"(Acq),"=c"(dummy):"c"(GLptr),"i"(~1L):"dx"); \
    } while(0)

#define ACPI_RELEASE_GLOBAL_LOCK(GLptr, Acq) \
    do { \
        int dummy; \
        asm("1:     movl (%1),%%eax;" \
            "movl   %%eax,%%edx;" \
            "andl   %2,%%edx;" \
            "lock;  cmpxchgl %%edx,(%1);" \
            "jnz    1b;" \
            "andl   $0x1,%%eax" \
            :"=a"(Acq),"=c"(dummy):"c"(GLptr),"i"(~3L):"dx"); \
    } while(0)
/*! [End] no source code translation !*/

#endif /* __GNUC__ */


#ifndef ACPI_ASM_MACROS

/* Unrecognized compiler, use defaults */

#define ACPI_ASM_MACROS
#define causeinterrupt(level)
#define BREAKPOINT3
#define disable()
#define enable()
#define halt()

#define ACPI_ACQUIRE_GLOBAL_LOCK(GLptr, Acq)
#define ACPI_RELEASE_GLOBAL_LOCK(GLptr, Acq)

#endif /* ACPI_ASM_MACROS */


#ifdef ACPI_APPLICATION

/* Don't want software interrupts within a ring3 application */

#undef causeinterrupt
#undef BREAKPOINT3
#define causeinterrupt(level)
#define BREAKPOINT3
#endif


#ifdef _MSC_VER                 /* disable some level-4 warnings */

/******************************************************************************
 *
 * Compiler-specific
 *
 *****************************************************************************/

#pragma warning(disable:4100) /* warn C4100: unreferenced formal parameter */
#pragma warning(disable:4127) /* warn C4127: conditional expression is constant */
#endif


#endif /* __ACENV_H__ */
