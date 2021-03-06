#ifndef CLAMPLAUNCHER_H
#define CLAMPLAUNCHER_H

#include "../clamp/includes/clamp.h"
#include <QThread>

class ClampLauncher : public QThread
{

Q_OBJECT
void run() override {
    int ret;
    ret = clamp(&args);

    if (ret != OK) printf("Error in clamp()\n");
}

public:
    ClampLauncher(clamp_args args);
    pid_t getPid();

private:
    clamp_args args;
    pid_t pid;
};

#endif // CLAMPLAUNCHER_H
