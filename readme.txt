PROJECT MINITALK FOR 42
- By chdonnat (Christophe Donnat from 42 Perpignan, France)

AIM OF THE PROJECT:
You are required to create a communication program in the form of a client and a server.
The server must be launched first and, after starting, should display its PID.
The client takes two parameters:
- The PID of the server.
- A string to transmit.
The client must communicate the provided string to the server.
Once the server has received the entire string, it must display it.
The server should display the string quickly. If you feel the process is too slow, it probably is.
The server must be able to receive strings from multiple clients consecutively without needing to be restarted.
You may only use the two signals: SIGUSR1 and SIGUSR2.
BONUS
The list of possible bonus features includes:
- The server confirms the reception of each message by sending a signal to the client.
- Support for Unicode characters.
- Communication between your programs must be performed exclusively using UNIX signals.

ARCHITECTURE:
- src_client/ directory for client src files
- src_server/ directory for server rsc files
- includes/ directory for header files
- Makefile (with rules: make bonus clean fclean re):
- libft/ directory with my own library (standard functions, ft_printf, get_next_line)
- readme.txt for explanations and main commands of the project

SOME COMMANDS YOU CAN USE:
make
	compiles both server and client with bonus (there is no specific rule to compile bonus)
	server and client then must be launched from different terminal windows 
./server
	launches the server, which remains waiting until CTRL + C to stop it
	the server must be launched before the client
	when the client sends a message to the server, the server writes the message sent
	and sends a confirmation to the client
./client <server PID> "<Your message>"
	the client send <Your message> to the server which has the <server PID> PID
	and then wait for a response from the server

DOCUMENTATION:

process
	A process is a running instance of a program that is executed by the operating system.
	It includes the program's code, its current activity (such as variables and data), and system resources like memory and CPU time.
	Each process is identified by a unique Process ID (PID).

process id (PID)
	PID (Process ID) is a unique identifier (a number) assigned by the operating system to each running process.
	It is used to manage and track processes within the system.

parent and child processes
	A parent process is a process that creates one or more child processes.
	It is the process that initiates another process by using system calls like fork().
	The parent process can manage or communicate with its child processes, and the child processes inherit certain attributes from the parent,
	such as the environment and open files.
	For example, when you launch a program from a terminal, the terminal is the parent process and the program is its child process.
	That child process can become the parent of another process if it launches another process by itself.

init and systemd
	The first process launched during the system startup on UNIX or Linux is usually init (in older systems) or systemd (in modern systems).
	init is the parent process of all other processes on a UNIX or Linux system,
	and it is the first process executed by the kernel after hardware initialization and root filesystem mounting.
	In modern systems, systemd has replaced init and is also the first process executed after the kernel starts, with PID 1.
	Both processes serve as system managers, responsible for initializing system services, managing processes, activating devices,
	managing users, and other essential tasks to keep the system running.
	In summary, the first process launched at startup is either init (in older systems) or systemd (in modern systems), and its PID is always 1.

process stop
	When a process stops (or terminates), several things happen:
	exit status:
		The process ends and returns an exit status to the operating system,
		typically indicating whether it finished successfully or encountered an error.
		This status can be checked by the parent process to determine how the child process ended.
	process termination:
		The operating system releases the resources (like memory, file descriptors, etc.) that were allocated to the process.
		The process is removed from the process table, which is a data structure that keeps track of all running processes.
	zombie state:
		If a process has terminated but its parent has not yet read its exit status (using a system call like wait()),
		the terminated process enters a "zombie" state.
		It still occupies a slot in the process table, but is effectively dead, awaiting cleanup by the parent.
		The parent process must call wait() to collect the exit status and remove the zombie process.
	parent-child relationship:
		Once the process terminates, the parent process may take specific actions,
		such as cleaning up after the child process or launching new processes.
		If the parent doesn't handle the termination of the child,
		the operating system may assign a new parent process (often init or systemd) to clean up.

process state
	In general, a process on a UNIX or Linux system can be in one of the following states:
	Running (R):
		The process is currently running or ready to run.
		It is using the CPU or waiting for its turn to use the CPU.
	Sleeping (S):
		The process is waiting for an event or a resource.
		It can be in an interruptible sleep, where it can be awakened by a signal or an event,
		or in an uninterruptible sleep, where it cannot be interrupted.
	Stopped (T): 
		The process has been stopped, usually by a signal such as SIGSTOP or SIGTSTP.
		It can be restarted by a signal such as SIGCONT.
	Zombie (Z):
		The process has finished execution, but its entry in the process table has not yet been removed.
		This occurs when the parent process has not yet read the exit status of the child process.
	Dead (D):
		The process is in an uninterruptible sleep state, usually waiting for an I/O operation.
		This state is rarely observed and is often related to hardware issues or device lockups.

signal
	A signal in computing is a mechanism used to notify a process about an event or interrupt its execution.
	It is a form of inter-process communication in UNIX-like systems.
	Signals can be generated by the kernel or other processes to notify a process of events
	such as errors, the need to terminate, or the occurrence of certain conditions.
	Common signals include SIGINT (interrupt), SIGKILL (force termination), and SIGTERM (graceful termination).
	Processes can handle signals by either performing a default action or executing a custom signal handler.

common signals
	Here’s a list of common signals in UNIX-like systems, along with their associated numbers.
	In the context of the minitalk project, the only signal allowed are SIGUSR1 and SIGUSR2
	SIGINT: Interrupt signal, associated with number 2.
		It interrupts a running process. It is typically sent when a user presses Ctrl+C in the terminal.
	SIGKILL: Force termination signal, associated with number 9.
		It immediately kills the process and cannot be caught or ignored.
	SIGTERM: Termination signal, associated with number 15.
		It is a polite request for the process to terminate, which can be handled or ignored by the process.
		SIGTERM is often expected to allow for a more orderly shutdown than SIGINT.
	SIGQUIT: Quit signal, associated with number 3.
		Similar to SIGINT, but it also causes the process to create a core dump.
	SIGHUP: Hang-up signal, associated with number 1.
		Often sent to a process when its controlling terminal is closed, typically used to indicate that a process should reload its configuration.
	SIGUSR1: User-defined signal 1, associated with number 10.
		It can be used by processes for custom actions.
	SIGUSR2: User-defined signal 2, associated with number 12.
		Like SIGUSR1, it is for custom purposes.
	SIGSTOP: Stop signal, associated with number 19.
		It pauses a process, and it cannot be caught or ignored.
	SIGCONT: Continue signal, associated with number 18.
		It resumes a process that was previously stopped.
	SIGSEGV: Segmentation fault signal, associated with number 11.
		It is generated when a process tries to access an invalid memory location, often indicating a bug in the program.

SIGUSR1 and SIGUSR2
	SIGUSR1 and SIGUSR2 are user-defined signals in Unix-like systems that can be used for custom actions within a program.
	Since they have no default behavior, developers can define how the program should respond to these signals, such as
	triggering logging, reloading configurations, or toggling debugging modes.
	These signals are useful for inter-process communication and controlling a program's behavior during runtime without terminating it.
	Programs can handle SIGUSR1 and SIGUSR2 signals by setting up custom signal handlers using functions like signal() or sigaction().
	When received, the program executes the corresponding handler,
	such as (for example) logging an event for SIGUSR1 or running a diagnostic routine for SIGUSR2.

getpid()
	prototype:
		#include <unistd.h>
		pid_t getpid(void);
	The getpid() function in C retrieves the Process ID (PID) of the calling process,
	which is a unique identifier assigned by the operating system.
	It returns a value of type pid_t and is commonly used for process management, debugging, and inter-process communication
	(e.g., sending signals using kill()).
	In multithreaded programs, all threads share the same PID.
	The function is often paired with getppid() to determine the parent process's PID
	or used after fork() to differentiate between parent and child processes.
	The PID remains unique while the process is active, but it can be reused after the process terminates.

kill()
	prototype:
		#include <signal.h>
		int kill(pid_t pid, int sig);
	The kill() function in C is used to send a signal to a specific process or a group of processes.
	It takes two parameters: the pid (process ID) of the target process and the signal to be sent (e.g., SIGTERM, SIGKILL, SIGINT).
	The function returns 0 on success or -1 on error.
	It can be used to control processes, such as terminating them or sending various signals like interrupting or stopping them.
	kill() is versatile and not limited to just terminating processes; it allows sending any signal defined in the system.

pause()
	prototype:
		#include <signal.h>
		int pause(void);
	The pause() function in C suspends the execution of a program until a signal is received.
	It doesn't take any parameters and returns -1 when a signal interrupts the function call, setting errno to EINTR.
	The function is commonly used in programs that need to wait for a signal (like SIGINT) before resuming execution.
	Once the signal is received, the program resumes execution after handling the signal.

signal()
	prototype:
		#include <signal.h>
		void (*signal(int signum, void (*handler)(int)))(int);
	The signal function in C is used to associate a specific signal (like SIGINT for interrupt or SIGTERM for termination)
	with a custom handler function. This handler is executed when the process receives the signal.
	The function takes two arguments: the signal number (signum) and a pointer to the handler function,
	which must follow the prototype:
		void handler(int).
	Alternatively, you can use SIG_IGN to ignore the signal or SIG_DFL to restore its default behavior.
	If the program enters other functions or threads,
	the signal handler remains valid unless overridden by another signal() or sigaction() call.
	If you call signal(signum, ...) again within the program, it will overwrite the previous handler.
	You can restore the default behavior using signal(signum, SIG_DFL).
	Limitations:
	While signal is simple to use, it has limitations, such as platform-dependent behavior and potential issues with reentrancy.
	For better portability and finer control over signal handling, the modern alternative sigaction is recommended.
	Some signals, like SIGKILL and SIGSTOP, cannot be caught or ignored, as they are managed exclusively by the operating system.

sleep()
	prototype:
		#include <unistd.h>
		unsigned int sleep(unsigned int seconds);
	The sleep() function in C is used to pause the execution of a program for a specified number of seconds.
	It takes one argument, the number of seconds to sleep, and suspends the process for that duration.
	The function returns 0 if the sleep duration is completed, or the remaining number of seconds if the sleep was interrupted by a signal.
	sleep() is commonly used to introduce delays or pauses in a program without consuming CPU resources, allowing the system to perform other tasks.

usleep()
	prototype:
		#include <unistd.h>
		int usleep(useconds_t microseconds);
	The usleep() function in C suspends the execution of a program for a specified number of microseconds (1 second = 1,000,000 microseconds).
	It takes an argument, the number of microseconds to sleep, and returns 0 if the sleep duration is completed successfully, or -1 in case of an error.
	usleep() is typically used when shorter delays than one second are needed, such as in applications requiring high precision or brief pauses.
	However, it may not be highly accurate due to the way the operating system handles timing and other concurrent processes.
	For more precise delays, nanosleep() is often preferred.
