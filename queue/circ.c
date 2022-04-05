#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>

struct entry {
    int data; // struct event
    TAILQ_ENTRY(entry) entries;             /* Tail queue. */
};

TAILQ_HEAD(tailhead, entry);


    int
main(void)
{
    static struct entry *np, *temp;
    struct entry *n = malloc(sizeof(struct entry) * 3);
    struct tailhead head;                   /* Tail queue head. */
    int i;

    TAILQ_INIT(&head);                      /* Initialize the queue. */

    //n[0] = malloc(sizeof(struct entry));      /* Insert at the head. */
    TAILQ_INSERT_TAIL(&head, &n[0], entries);
    n[0].data = 10;

    //n[1] = malloc(sizeof(struct entry));      /* Insert at the tail. */
    TAILQ_INSERT_TAIL(&head, &n[1], entries);
    n[1].data = 20;

    TAILQ_INSERT_TAIL(&head, &n[2], entries);
    n[2].data = 30;

    TAILQ_REMOVE(&head, head.tqh_first, entries);       /* Deletion. */


    printf("n[0] %i\n", n[0].data);
    printf("n[1] %i\n", n[1].data);
    printf("n[2] %i\n", n[2].data);

    // Get the last event :)
    temp = TAILQ_LAST(&head, tailhead);
    printf("last %i\n", temp->data);

    // Get 2nd event after last :)
    temp = TAILQ_PREV(temp, tailhead, entries );
    if (temp != NULL)
        printf("2nd: %i\n", temp->data);

    temp = TAILQ_PREV(temp, tailhead, entries ); // temp == NULL
    if (temp != NULL) {
        printf("prev: %i\n", temp->data);
    }
    // temp == NULL , please don't do that!
    // temp = TAILQ_PREV(temp, tailhead, entries );

    printf("-----------------------------------------------\n");




    /* Forward traversal. */
    // i = 0;
    // TAILQ_FOREACH(np, &head, entries)
    //     np->data = i++;

    /* Reverse traversal. */
    TAILQ_FOREACH(np, &head, entries)
        printf("%i\n", np->data);

    /* TailQ Deletion. */
    // n1 = TAILQ_FIRST(&head);
    // while (n1 != NULL) {
    //     n2 = TAILQ_NEXT(n1, entries);
    //     free(n1);
    //     n1 = n2;
    // }

    exit(EXIT_SUCCESS);
}

