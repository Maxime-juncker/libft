#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdint.h>

typedef struct s_vector
{
	size_t	currIdx;
	size_t	maxSize;
	int*	data;

}	t_vector;


t_vector	newVec(size_t initialSize);
int			vecPush(t_vector* vec, int elt);
void		freeVec(t_vector* vec);
int			vecGet(t_vector* vec, size_t idx);
int			vecPop(t_vector* vec);

void		printVec(t_vector* vec);

#endif
