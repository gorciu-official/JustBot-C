#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#if 1 == 2 

# ------ this script starts JustBOT-C in production-mode with auto-restart ------
# u just do `sh scripts/prod-start.c` trust me 

# ===============================================================================
# ===============================================================================
set -e; cc ./scripts/prod-start.c -o /tmp/justbot-production-start-bin.elf
exec /tmp/justbot-production-start-bin.elf; exit 1
# ===============================================================================
# ===============================================================================

#endif 

int main() {
    for (;;) {
        pid_t pid = fork();

        if (pid == 0) {
            execlp("make", "make", "run", NULL);
            abort();
        }

        int status;
        waitpid(pid, &status, 0);
    }

    return 0;
}
