
#ifndef ISH_SYSCALLS_H
#define ISH_SYSCALLS_H

/*
    Project #1, Part #2

    Implement the following system calls

        `ish_read`
        `ish_chdir`
        `ish_exit`
        `ish_stat`
        `ish_open`
        `ish_creat`
        `ish_dup2`
        `ish_close`
        `ish_fork`
        `ish_execve`
        `ish_waitpid`
        `ish_write`

    Documentation

        `man syscall`
        `man syscalls`
        `man 2 <system call name>`

    Linux x86-64 System Call Tables

        `syscall_64.tbl`

        https://github.com/torvalds/linux/tree/master/arch/x86/entry/syscalls

    For extra points you can implement calls for other CPU architectures. You
    need to research kernel and function calling conventions on your own.

    Linux x86 System Call Tables

        `syscall_32.tbl`

        https://github.com/torvalds/linux/tree/master/arch/x86/entry/syscalls

    Linux ARMv7-A System Call Tables from Android Bionic libc

        `unistd-common.h`

        https://github.com/android/platform_bionic/blob/master/libc/kernel/uapi/asm-arm/asm

    Linux ARMv8-A System Call Tables from Android Bionic libc

        `unistd.h`

        https://github.com/android/platform_bionic/blob/master/libc/kernel/uapi/asm-generic

    You will have to find the system call numbers for MIPS and RISC-V CPU
    architectures on your own.
*/

#ifndef ISH_USE_STDLIB
    #define read    ish_read
    #define chdir   ish_chdir
    #define exit    ish_exit
    #define stat    ish_stat
    #define open    ish_open
    #define creat   ish_creat
    #define dup2    ish_dup2
    #define close   ish_close
    #define fork    ish_fork
    #define execve  ish_execve
    #define waitpid ish_waitpid
    #define write   ish_write
#endif

#define read    ish_read

long ish_read(
        int file_descriptor,
        void *buffer,
        unsigned long buffer_size
     );

#define chdir   ish_chdir

int ish_chdir(const char *path);

#define exit    ish_exit

void ish_exit(int status);

#define stat    ish_stat

int ish_stat(const char *path, void *stat_result);

#define open    ish_open

int ish_open(const char *path, int flags);

#define creat   ish_creat

int ish_creat(const char *path, unsigned int mode);

#define dup2    ish_dup2

int ish_dup2(int old_file_descriptor, int new_file_descriptor);

#define close   ish_close

int ish_close(int file_descriptor);

#define fork    ish_fork

int ish_fork(void);

#define execve  ish_execve

int ish_execve(
        const char *path,
        char *const arguments[],
        char *const environment[]
    );

#define waitpid ish_waitpid

int ish_waitpid(int pid, int *status, int options);

#define write   ish_write

long ish_write(
        int file_descriptor,
        const void *buffer,
        unsigned long buffer_size
     );

#endif
