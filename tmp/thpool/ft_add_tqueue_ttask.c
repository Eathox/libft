#include "thpool.h"
#include "priv.h"

static void	add_job_front(t_tqueue *queue, t_tjob *job) {
	job->next = queue->first;
	queue->first = job;
	if (queue->last == NULL)
		queue->last = job;
}

static void	add_job_back(t_tqueue *queue, t_tjob *job) {
	job->next = NULL;
	if (queue->first == NULL)
		queue->first = job;
	else
		queue->last->next = job;
	queue->last = job;
}

static void	add_job(t_tqueue *queue, t_tjob *job) {
	if ((job->task->flags & TFLAG_TASK_HIGH_PRIOR) != 0)
		add_job_front(queue, job);
	else
		add_job_back(queue, job);
	queue->size++;
	if (queue->size == 1)
		pthread_cond_broadcast(&queue->cond_not_empty);
}

t_ttask		*ft_add_tqueue_ttask(t_tqueue *queue, t_ttask *task) {
	t_tjob	*job;

	if (task == NULL)
		return (NULL);
	task->completed = false;
	job = ft_new_tjob(task);
	if (job == NULL)
		return (NULL);
	pthread_mutex_lock(&queue->lock);
	add_job(queue, job);
	pthread_mutex_unlock(&queue->lock);
	return (task);
}
