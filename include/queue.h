#ifndef PTHREADS_SIMULATOR_QUEUE_H_
#define PTHREADS_SIMULATOR_QUEUE_H_

#include <stdbool.h>
#include <stddef.h>

typedef struct process process_t;

typedef struct queue {
  process_t **processes;
  size_t size;
  size_t entries;
  size_t head_idx;
  size_t tail_idx;
} queue_t;

void enqueue(queue_t *queue, process_t *process);

process_t *dequeue(queue_t *queue);

queue_t *queue_create(size_t size);

bool queue_destroy(queue_t *queue);

process_t *queue_peek(queue_t *queue);

#endif /* PTHREADS_SIMULATOR_QUEUE_H_ */
