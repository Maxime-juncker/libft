#include "libft/vector.h"
#include "libft/memory.h"
#include "libft/io.h"

t_vector invalidVec()
{
	return (t_vector){ .maxSize = 0, .currIdx = -1, .data = NULL };
}

t_vector newVec(size_t initialSize)
{
	t_vector vec;

	ft_bzero(&vec, sizeof(t_vector));
	vec.data = ft_calloc(initialSize, sizeof(int));
	
	if (!vec.data) // failed to initialize
	{
		return invalidVec();
	}

	vec.currIdx = -1;
	vec.maxSize = initialSize;
	return vec;
}

/// add an element to vector, if vector not big enought, size will be double an elt added
/// @param vec the vector to push elt to
/// @param elt integer to add
/// @return 0 if success, -1 if resizing failed
int	vecPush(t_vector* vec, int elt)
{
	if (vec->data && vec->currIdx + 1 < vec->maxSize)
	{
		vec->currIdx++;
		vec->data[vec->currIdx] = elt;
		return 0;
	}

	int newSize = vec->maxSize > 0 ? vec->maxSize * 2 : 1;
	int* mem = ft_calloc(newSize, sizeof(int));
	if (!mem)
	{
		free(vec->data);
		*vec = invalidVec();
		return -1;
	}

	if (vec->maxSize != 0)
	{
		for (size_t i = 0; i <= vec->currIdx; i++)
		{
			mem[i] = vec->data[i];
		}
	}
	vec->currIdx++;
	mem[vec->currIdx] = elt;

	free(vec->data);
	vec->data = mem;
	vec->maxSize = newSize;

	return 0;
}

void	freeVec(t_vector* vec)
{
	free(vec->data);
	*vec = invalidVec();
}

int			vecGet(t_vector* vec, size_t idx)
{
	if (!vec->data || idx > vec->currIdx)
		return -1;
	return vec->data[idx];
}

int			vecPop(t_vector* vec)
{
	if (!vec->data)
		return -1;
	int elt = vec->data[vec->currIdx];
	vec->data[vec->currIdx] = 0;
	vec->currIdx--;
	return elt;
}

void	printVec(t_vector* vec)
{
	ft_printf("maxSize: %-3d ", (int)vec->maxSize);
	ft_printf("currIdx: %-3d ", (int)vec->currIdx);

	if (!vec->data || vec->currIdx == (size_t)-1)
	{
		ft_printf("(data null)\n");
		return;
	}

	ft_printf("[");
	for (size_t i = 0; i < vec->currIdx; i++)
	{
		ft_printf("%d, ", vec->data[i]);
	}
	ft_printf("%d]\n", vec->data[vec->currIdx]);
}
