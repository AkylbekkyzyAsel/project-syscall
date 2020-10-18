long ish_read(
        int file_descriptor,
        void *buffer,
        unsigned long buffer_size
     )
{

    	long result;
    	__asm__ __volatile__ (
		"mov $0x0, %%rax\n\t"
		"syscall"
		:"=a" (result)

	);

    	return result;
}

int ish_chdir(const char *path)
{

	//return -1;
	int result;
	__asm__ __volatile__ (
	  	"mov $0x50, %%rax\n\t"
		"syscall"
		:"=a" (result)

	);

    	return result;
}

void ish_exit(int status)
{
	int result;
	__asm__ __volatile__ (
		"mov $0x3c, %%rax\n\t"
		"syscall"
		:"=a"(result)
	);
}

int ish_stat(const char *path, void *stat_result)
{
	int result;
	__asm__ __volatile__ (
		"mov $0x4, %%rax\n\t"
		"syscall"
		:"=a"(result)
	);
    	return result;
}

int ish_open(const char *path, int flags)
{
    int result;
        __asm__ __volatile__ (
                "mov $0x2, %%rax\n\t"
                "syscall"
                :"=a"(result)
        );
    return result;

}

int ish_creat(const char *path, unsigned int mode)
{

	int result;
        __asm__ __volatile__ (
                "mov $0x55, %%rax\n\t"
                "syscall"
                :"=a"(result)
        );
    	return result;


}

int ish_dup2(int old_file_descriptor, int new_file_descriptor)
{
	int result;
        __asm__ __volatile__ (
                "mov $0x21, %%rax\n\t"
                "syscall"
                :"=a"(result)
        );
        return result;


}

int ish_close(int file_descriptor)
{
	int result;
        __asm__ __volatile__ (
                "mov $0x3, %%rax\n\t"
                "syscall"
                :"=a"(result)
        );
        return result;

}

int ish_fork()
{
    	 int result;
        __asm__ __volatile__ (
                "mov $0x39, %%rax\n\t"
                "syscall"
                :"=a"(result)
        );
        return result;

}

int ish_execve(
        const char *path,
        char *const arguments[],
        char *const environment[]
    )
{
	int result;
        __asm__ __volatile__ (
                "mov $0x3b, %%rax\n\t"
                "syscall"
                :"=a"(result)
        );
        return result;

}

int ish_waitpid(int pid, int *status, int options)
{
	int result;
	char rusage [256];
        __asm__ __volatile__ (
                "mov $0x3d, %%rax\n\t"
                "syscall"
                :"=a"(result)
		:"c"(&rusage)
        	:
	);
        return result;

}

long ish_write(
        int file_descriptor,
        const void *buffer,
        unsigned long buffer_size
     )
{
	long result;
        __asm__ __volatile__ (
                "mov $0x1, %%rax\n\t"
                "syscall"
                :"=a"(result)
        );
        return result;

}
