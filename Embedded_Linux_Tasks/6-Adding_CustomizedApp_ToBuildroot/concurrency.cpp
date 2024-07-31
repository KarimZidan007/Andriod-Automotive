#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

// Function for logging current time every 5 seconds
void* log_time(void* arg) {
    FILE *log_file;
    while (1) {
        log_file = fopen("/tmp/daemon_log.txt", "a");
        if (log_file == NULL) {
            perror("Failed to open log file");
            exit(EXIT_FAILURE);
        }

        time_t now = time(NULL);
        fprintf(log_file, "Current time: %s", ctime(&now));
        fclose(log_file);
        sleep(5);
    }
    return NULL;
}

// Function for logging alive message every 10 seconds
void* log_alive(void* arg) {
    FILE *log_file;
    while (1) {
        log_file = fopen("/tmp/daemon_log.txt", "a");
        if (log_file == NULL) {
            perror("Failed to open log file");
            exit(EXIT_FAILURE);
        }

        fprintf(log_file, "Thread 2: I am alive\n");
        fclose(log_file);
        sleep(10);
    }
    return NULL;
}

// Function to create a daemon process
void create_daemon() {
    pid_t pid;

    // Fork the process
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        // Parent process
        exit(EXIT_SUCCESS);
    }

    // Child process
    if (setsid() < 0) {
        perror("Failed to become session leader");
        exit(EXIT_FAILURE);
    }

    // Ignore signal sent from child to parent process
    signal(SIGCHLD, SIG_IGN);

    // Fork again to ensure the daemon cannot reacquire a terminal
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        // Exit the parent process
        exit(EXIT_SUCCESS);
    }

    // Set file permissions
    umask(0);

    // Change the working directory to the root directory
    if (chdir("/") < 0) {
        perror("Failed to change directory");
        exit(EXIT_FAILURE);
    }

    // Close all open file descriptors
    for (int x = sysconf(_SC_OPEN_MAX); x >= 0; x--) {
        close(x);
    }

    // Open log file descriptors
    open("/dev/null", O_RDWR);
    dup(0);
    dup(0);
}

int main() {
    // Create daemon process
    create_daemon();

    pthread_t thread1, thread2;

    // Create thread 1 for logging time
    if (pthread_create(&thread1, NULL, log_time, NULL) != 0) {
        perror("Failed to create thread1");
        exit(EXIT_FAILURE);
    }

    // Create thread 2 for logging alive message
    if (pthread_create(&thread2, NULL, log_alive, NULL) != 0) {
        perror("Failed to create thread2");
        exit(EXIT_FAILURE);
    }

    // Join threads
    if (pthread_join(thread1, NULL) != 0) {
        perror("Failed to join thread1");
        exit(EXIT_FAILURE);
    }

    if (pthread_join(thread2, NULL) != 0) {
        perror("Failed to join thread2");
        exit(EXIT_FAILURE);
    }

    return 0;
}

