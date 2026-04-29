#include "../include/queue.h"
#include <stdio.h>
#include <stdlib.h>

void enqueue(queue_t *queue, process_t *process) {
  queue->processes[queue->head_idx] = process;
  queue->head_idx = (queue->head_idx + 1) % queue->size;
  queue->entries++;
}

process_t *dequeue(queue_t *queue) {
  if (queue->tail_idx == queue->head_idx)
    return NULL;
  process_t *process = queue->processes[queue->tail_idx];
  queue->processes[queue->tail_idx] = NULL;
  queue->tail_idx = (queue->tail_idx + 1) % queue->size;
  queue->entries--;
  return process;
}

queue_t *queue_create(size_t size) {
  queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
  if (!queue)
    exit(EXIT_FAILURE);

  queue->processes = (process_t **)malloc(sizeof(process_t *) * size);
  if (!queue->processes)
    exit(EXIT_FAILURE);

  queue->size = size;
  queue->entries = 0;
  queue->head_idx = 0;
  queue->tail_idx = 0;
  return queue;
}

bool queue_destroy(queue_t *queue) {
  if (!queue) {
    printf("[queue_destroy] no queue found!");
    return false;
  }
  free(queue->processes);
  free(queue);
  return true;
}

process_t *queue_peek(queue_t *queue) { return queue->processes[queue->tail_idx]; }
