#include <cstring>
#include <iostream>

// Linux/POSIX-specific headers
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <dirent.h>
#include <pthread.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>

void test_linux_syscalls() {
    std::cout << "Testing Linux System Calls..." << std::endl;

    const char* filename = "/tmp/testfile.txt";
    int fd = open(filename, O_CREAT | O_WRONLY, 0644);
    if (fd >= 0) {
        const char* msg = "Hello from Linux syscall!\n";
        write(fd, msg, strlen(msg));
        close(fd);
    }

    DIR* dir = opendir("/tmp");
    if (dir) {
        struct dirent* entry;
        while ((entry = readdir(dir))) {
            std::cout << "Found file: " << entry->d_name << std::endl;
        }
        closedir(dir);
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock >= 0) {
        std::cout << "Socket created successfully." << std::endl;
        close(sock);
    }

    pid_t pid = fork();
    if (pid == 0) {
        _exit(0); // child exits
    } else if (pid > 0) {
        waitpid(pid, nullptr, 0); // parent waits
        std::cout << "Child process completed." << std::endl;
    }
}


