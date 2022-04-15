#include "thpool.h"

void ft_join_ttask_all(t_ttask *task) {
    while (task != NULL) {
        ft_join_ttask(task);
        task = task->next;
    }
}
