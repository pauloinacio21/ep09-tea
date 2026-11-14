#include "teamvec.h"
#include <stdlib.h>

struct teamvec {
    int n;      // qtd de times
    int n_max;  // capacidade
    Team **v;
};

TeamVec *tv_create(void) {
    TeamVec *tv = (TeamVec *) malloc(sizeof(TeamVec));
    if (tv == NULL)
        return NULL;

    tv->n = 0;
    tv->n_max = 4;
    tv->v = (Team **) malloc(tv->n_max * sizeof(Team *));
    if (tv->v == NULL) {
        free(tv);
        return NULL;
    }
    return tv;
}

void tv_insert(TeamVec *tv, Team *t) {
    // encheu, dobra
    if (tv->n == tv->n_max) {
        int new_max = tv->n_max * 2;
        Team **aux = (Team **) realloc(tv->v, new_max * sizeof(Team *));
        if (aux == NULL)
            return;
        tv->v = aux;
        tv->n_max = new_max;
    }
    tv->v[tv->n] = t;
    tv->n++;
}

int tv_size(TeamVec *tv) {
    return tv->n;
}

Team *tv_get(TeamVec *tv, int i) {
    return tv->v[i];
}

void tv_free(TeamVec *tv) {
    for (int i = 0; i < tv->n; i++)
        team_free(tv->v[i]);
    free(tv->v);
    free(tv);
}
